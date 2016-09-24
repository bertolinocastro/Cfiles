#include <gtk/gtk.h>
void sair(GtkWidget *w, gpointer p)
{

    gtk_main_quit();

}

void clique(GtkWidget *w, gpointer p)
{

    g_print("O botao foi clicado\n");

}

int main(int argc, char **argv)
{

    GtkWidget *janela, *botao;

    gtk_init(&argc, &argv);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (janela), "Alo Mundo");
    gtk_signal_connect(GTK_OBJECT (janela), "destroy", GTK_SIGNAL_FUNC (sair), NULL);

    botao = gtk_button_new_with_label("Clique aqui");
    gtk_container_add(GTK_CONTAINER (janela), botao);
    gtk_signal_connect(GTK_OBJECT (botao), "clicked", GTK_SIGNAL_FUNC (clique), NULL);

    gtk_widget_show(botao);
    gtk_widget_show(janela);


    gtk_main();
    return 0;

}
