#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

unsigned int i = 0 , j = 0;
unsigned int Ndiscos;

/* Declaracoes para hanoi() */
void hanoi( unsigned int n , unsigned int Ori , unsigned int Dest , unsigned int Aux );

/* Declarações para interfaceGraf(); */
void interfaceGraf( int argc , char **argv );
GtkWidget *janela , *grade , **pilar, **disco , *espacadorV , *botao;
GdkRGBA color , corDiscos;
unsigned int qtdRows;

void fecharJanela( GtkWidget *w , gpointer p );

void passo( GtkWidget *w , gpointer p );

void moveDisco( unsigned int numDisco , unsigned int pilarOri , unsigned int pilarDest );

/* Declarações para espacarVertical() */
void espacarVertical( unsigned int pilarAtual );
struct{
    unsigned int pilar[3];
} discos_existentes = { { 0 , 0 , 0 } };

void desespacarVertical( unsigned int pilarAtual );


int main( int argc , char **argv ){

    scanf( "%u" , &Ndiscos );

    printf( "Número total de movimentos: %u\n" , i );

    interfaceGraf( argc , argv );

    return 0;
}

void hanoi( unsigned int n , unsigned int Ori , unsigned int Dest , unsigned int Aux ){
    if( n <= 1 ){
        printf( "Movendo disco %u do pilar %u para o %u\n" , n , Ori , Dest);
        sleep( 1 );
        moveDisco( n - 1 , Ori , Dest );
        ++j;
    }else{
        hanoi( n - 1 , Ori , Aux , Dest );
        printf( "Movendo disco %u do pilar %u para o %u\n" , n , Ori , Dest );
        sleep( 1 );
        moveDisco( n - 1 , Ori , Dest );
        ++j;
        hanoi( n - 1 , Aux , Dest , Ori );
    }
}

void moveDisco( unsigned int numDisco , unsigned int pilarOri , unsigned int pilarDest ){
    gpointer auxiliar;
    auxiliar = g_object_ref( GTK_WIDGET ( disco[numDisco] ) );
    gtk_container_remove( GTK_CONTAINER ( grade ) , disco[numDisco] );
    gtk_grid_attach( GTK_GRID ( grade ) , disco[numDisco] , ( pilarDest - 1 ) * 10 , qtdRows - discos_existentes.pilar[pilarDest-1] , 10 , 1 );
    g_object_unref( auxiliar );

    --discos_existentes.pilar[pilarOri-1];
    ++discos_existentes.pilar[pilarDest-1];
/*
    desespacarVertical( pilarOri - 1 );
    desespacarVertical( pilarDest - 1 );
    espacarVertical( pilarOri - 1 );
    espacarVertical( pilarDest - 1 );
*/
    gtk_widget_queue_draw( GTK_WIDGET ( disco[numDisco] ) );
    while ( g_main_context_iteration( NULL , FALSE ) );
}

void espacarVertical( unsigned int pilarAtual ){
    printf( "DEBUG: %u -> pilatual %u\n" , qtdRows , pilarAtual );
    /* Verificar a partir de qual posição do pilar possui um disco */
    unsigned int margem;
    margem = ( qtdRows - discos_existentes.pilar[pilarAtual] ) * 20;
    gtk_widget_set_margin_top( GTK_WIDGET ( gtk_grid_get_child_at( GTK_GRID ( grade ) , pilarAtual * 10 , qtdRows - discos_existentes.pilar[pilarAtual] ) ) , margem );
}

void desespacarVertical( unsigned int pilarAtual ){
    for( i = qtdRows - discos_existentes.pilar[pilarAtual] ; i < qtdRows ; ++i , printf( "Limpeza: %u -> pilatual %u\n" , i - 1 , pilarAtual ) ) gtk_widget_set_margin_top( GTK_WIDGET ( gtk_grid_get_child_at( GTK_GRID ( grade ) , pilarAtual * 10 , i ) ) , 0 );
}

void fecharJanela( GtkWidget *w , gpointer p ){
    gtk_main_quit();
}

void chamahanoi( GtkWidget *w , gpointer p ){
    /* Chamada para a função recursiva da torre de Hanói */
    hanoi( Ndiscos , 1 , 2 , 3 );
}

void interfaceGraf( int argc , char **argv ){

    unsigned int altPilar = 20 * Ndiscos + 40 ;
    char letra;
    qtdRows = Ndiscos + 2;

    gtk_init( &argc , &argv );

    disco = malloc( Ndiscos * sizeof( GtkWidget * ) );
    pilar = malloc( 3 * sizeof( GtkWidget * ) );

    botao = gtk_button_new_with_label( "Inicio" );
    g_signal_connect( GTK_BUTTON ( botao ) , "clicked" , G_CALLBACK ( chamahanoi ) , NULL );

    /* Criação da janela como um todo */
    janela = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_title( GTK_WINDOW (janela) , "Torre de Hanoi" );
    /*gtk_window_set_default_size( GTK_WINDOW (janela) , 800 , 600 );*/

    /* Função para finalizar a execução caso fechar a janela */
    g_signal_connect( GTK_WINDOW ( janela ) , "destroy" , G_CALLBACK ( fecharJanela ) , NULL );

    /* Criação do grid que irá conter os elementos (pinos) */
    grade = gtk_grid_new();

    /* Espaçamento da grid */
    gtk_container_set_border_width( GTK_CONTAINER ( grade ) , 100 );

    /* Inserção da linha principal (baseline) */
    for( i = 0 ; i < qtdRows ; ++i ) gtk_grid_insert_row( GTK_GRID ( grade ) , i );

    /* Inserção de colunas na grid */
    for( i = 0 ; i < 30 ; ++i ) gtk_grid_insert_column( GTK_GRID ( grade ) , i );

    /* Criação dos widgets (pilares) */
    for( i = 0 , letra = '1' ; i < 3 ; ++i , ++letra ) pilar[i] = gtk_widget_new( GTK_TYPE_LABEL , "label" , &letra /*, "xalign" , 0.0 */, NULL );

    /* Margeamento à esquerda dos pilares */
    for( i = 0 ; i < 3 ; ++i ) ( gtk_widget_set_margin_start( GTK_WIDGET ( pilar[i] ) , 50 ) , gtk_widget_set_margin_end( GTK_WIDGET ( pilar[i] ) , 50 ) );

    /* Cricação das cores */
    gdk_rgba_parse( &color , "red" );
    for( i = 0 ; i < 3 ; ++i ) gtk_widget_override_background_color( GTK_WIDGET ( pilar[i] ) , GTK_STATE_NORMAL , &color );

    /* Dimensionamento dos pilares */
    for( i = 0 ; i < 3 ; ++i ) gtk_widget_set_size_request( GTK_WIDGET ( pilar[i] ) , 10 , altPilar );

    /* Posicionamento dos pilares */
    for( i = 0 ; i < 3 ; ++i ) gtk_widget_set_halign( GTK_WIDGET ( pilar[i] ) , GTK_ALIGN_CENTER );

    /* Inserção dos pilares dentro do grid */
    for( i = 0 ; i < 3 ; ++i ) gtk_grid_attach( GTK_GRID ( grade ) , pilar[i] , 10 * i , 0 , 10 , 30 );

    /* Criacao dos discos */
    for( i = 0 , letra = '1' ; i < Ndiscos ; ++i , ++letra ) disco[i] = gtk_widget_new( GTK_TYPE_LABEL , "label" , &letra /*, "xalign" , 0.0*/ , NULL );

    for( i = 0 ; i < Ndiscos ; ++i ) gtk_widget_set_halign( GTK_WIDGET ( disco[i] ) , GTK_ALIGN_CENTER );

    /* Colorindo discos */
    gdk_rgba_parse( &corDiscos , "white" );
    for( i = 0 ; i < Ndiscos ; ++i ) gtk_widget_override_background_color( GTK_WIDGET ( disco[i] ) , GTK_STATE_NORMAL , &corDiscos );

    /* Definindo tamanho dos discos */
    for( i = 0 ; i < Ndiscos ; ++i ) gtk_widget_set_size_request( GTK_WIDGET ( disco[i] ) , 30 + i * 5 , 20 );

    /* Inserindo os discos nas colunas dos pilares */
    for( i = 0 ; i < Ndiscos ; printf( "Inserindo o disco[%u] na row: %u\n" , i , qtdRows - Ndiscos + i ) , ++i , ++discos_existentes.pilar[0] ) gtk_grid_attach( GTK_GRID ( grade ) , disco[i] , 0 ,  qtdRows - Ndiscos + i , 10 , 1 );

    /* Primeira chamada à função de espacar verticalmente */
    espacarVertical( 0 );

    /* Inserindo botão */
    gtk_grid_attach( GTK_GRID ( grade ) , botao , 0 , 0 , 1 , 1 );

    /* Inserção dos containers internos à janela */
    gtk_container_add( GTK_CONTAINER( janela ) , grade );

    gtk_widget_show_all( janela );

    gtk_main();

}


