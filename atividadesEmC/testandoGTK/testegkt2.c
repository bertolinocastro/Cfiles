#include <gtk/gtk.h>

void clique(GtkWidget *widget, gpointer data) {

g_print("%s foi clicado!\n", (char *)data);

}

void sair(GtkWidget *widget, gpointer data) {

g_print("Saindo...\n");
gtk_main_quit();

}

int main(int argc, char **argv) {

GtkWidget *janela, *caixa, *botão;
gtk_init(&argc, &argv);
janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_signal_connect(GTK_OBJECT (janela), "destroy", GTK_SIGNAL_FUNC (sair), NULL);
caixa = gtk_hbox_new(TRUE, 10);
gtk_container_add(GTK_CONTAINER (janela), caixa);
botão = gtk_button_new_with_label("Botão 1");
gtk_signal_connect(GTK_OBJECT (botão), "clicked", GTK_SIGNAL_FUNC (clique), "botão 1");
gtk_box_pack_start(GTK_BOX (caixa), botão, FALSE, TRUE, 0);
gtk_widget_show(botão);
botão = gtk_button_new_with_label("Botão 2");
gtk_signal_connect(GTK_OBJECT (botão), "clicked", GTK_SIGNAL_FUNC (clique), "botão 2");
gtk_box_pack_start(GTK_BOX (caixa), botão, FALSE, TRUE, 0);
gtk_widget_show(botão);
gtk_widget_show(caixa);
gtk_widget_show(janela);
gtk_main();
return 0;

}
