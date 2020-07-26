#include <gtest/gtest.h>
#include "src/listasimples.h"

TEST(TestesListaSimples,ListaVazia){
    ListaSimples<int> *listaVazia = new ListaSimples<int>();
    int numero_elementos = listaVazia->contador;
    ASSERT_EQ(numero_elementos,0);
}

TEST(TestesListaSimples, InserindoUmItemNaFrente){
    ListaSimples<int> *lista_um_item = new ListaSimples<int>();
    int valor = 30;
    lista_um_item->inserir_frente(valor);

    int valor_topo = lista_um_item->topo->valor;
    int valor_base = lista_um_item->base->valor;
    int numero_itens = lista_um_item->contador;
    ASSERT_EQ(numero_itens,1);
    ASSERT_EQ(valor_topo, valor);
    ASSERT_EQ(valor_topo,valor_base);
}