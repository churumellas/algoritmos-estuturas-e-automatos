//TODO: Implementar testes para listas duplas
#include <gtest/gtest.h>
#include "src/listadupla.h"
#include <iostream>

TEST(ListaDuplaTeste, CriarListaDuplaVazia){
    ListaDupla<char> *lista = new ListaDupla<char>();
    bool vazio = lista->vazio();
    ASSERT_TRUE(vazio);
}

TEST(ListaDuplaTeste, InserirInicioDaLista){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 2);
}