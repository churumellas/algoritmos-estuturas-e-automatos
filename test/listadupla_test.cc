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
    lista->inserir_frente('c');

    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 3);
}

TEST(ListaDuplaTeste, InserirNoFundoDaLista){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_fundo('a');
    lista->inserir_fundo('b');
    lista->inserir_fundo('c');

    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(3, n_elementos);
}

TEST(ListaDuplaTeste, InserirNoMeio){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    lista->inserir_frente('c');
    
    lista->inserir_meio('x',1);
    lista->inserir_meio('x',2);

    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 5);
}

TEST(ListaDuplaTeste, RemoverPrimeiroElementoListaUnitaria){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->remover_primeiro('a');

    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_TRUE(vazio);
    ASSERT_EQ(n_elementos, 0);
}

TEST(ListaDuplaTeste, RemoverPrimeiroElemento){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    lista->inserir_frente('c');

    lista->remover_primeiro('b');
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 2);
}

TEST(ListaDuplaTeste, RemoverTodasAparicoesListaUnitaria){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('b');
    lista->remover_todos('b');
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_TRUE(vazio);
    ASSERT_EQ(n_elementos, 0);
}

TEST(ListaDuplaTeste, RemoverTodasAparicoes){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('c');

    lista->remover_todos('b');
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 2);
}

TEST(ListaDuplaTeste, RemoverTodasAparicoesComecandoCabeca){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('c');

    lista->remover_todos('b');
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 1);
}

TEST(ListaDuplaTeste, RemoverTodasAparicoesTerminandoCauda){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('b');

    lista->remover_todos('b');
    bool vazio = lista->vazio();
    int n_elementos = lista->tamanho;

    ASSERT_FALSE(vazio);
    ASSERT_EQ(n_elementos, 1);
}

TEST(ListaDuplaTeste, EncontrarElementoListaUnitaria){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    bool encontrou = lista->procurar_elemento('a');

    ASSERT_TRUE(encontrou);
}

TEST(ListaDuplaTeste, NaoEncontrarElementoListaUnitaria){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    bool encontrou = lista->procurar_elemento('b');

    ASSERT_FALSE(encontrou);
}

TEST(ListaDuplaTeste, AcharElementoPrimeiraPosicao){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('a');
    lista->inserir_frente('b');
    lista->inserir_frente('c');

    bool encontrou = lista->procurar_elemento('a');

    ASSERT_TRUE(encontrou);
}

TEST(ListaDuplaTeste, AcharElementoUltimaPosicao){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('b');
    lista->inserir_frente('c');
    lista->inserir_frente('a');
    
    bool encontrou = lista->procurar_elemento('a');

    ASSERT_TRUE(encontrou);
}

TEST(ListaDuplaTeste, AcharElementoNoMeio){
    ListaDupla<char> *lista = new ListaDupla<char>();

    lista->inserir_frente('b');
    lista->inserir_frente('b');
    lista->inserir_frente('c');
    lista->inserir_frente('a');
    lista->inserir_frente('c');
    lista->inserir_frente('b');

    bool encontrou = lista->procurar_elemento('a');
    ASSERT_TRUE(encontrou);
}