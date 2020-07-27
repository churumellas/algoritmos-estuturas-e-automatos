#include <gtest/gtest.h>
#include "src/listasimples.h"

TEST(TestesListaSimples,ListaVazia){
    ListaSimples<int> *listaVazia = new ListaSimples<int>();
    int numero_elementos = listaVazia->contador;
    bool esta_vazio = listaVazia->esta_vazio();

    ASSERT_TRUE(esta_vazio);
    ASSERT_EQ(numero_elementos,0);
}

TEST(TestesListaSimples, InserindoUmItemNaFrenteComListaVazia){
    ListaSimples<int> *lista_um_item = new ListaSimples<int>();
    
    int valor = 30;
    lista_um_item->inserir_frente(valor);

    int valor_topo = lista_um_item->topo->valor;
    int numero_itens = lista_um_item->contador;
    
    ASSERT_EQ(numero_itens,1);
    ASSERT_EQ(valor_topo, valor);
    
}

TEST(TestesListaSimples,InserirVariosItensNaFrente){
    ListaSimples<int> *lista_cheia = new ListaSimples<int>();
    
    int primeiro_valor = 1;
    int segundo_valor = 2;
    int terceiro_valor = 3;

    lista_cheia->inserir_frente(primeiro_valor);
    lista_cheia->inserir_frente(segundo_valor);
    lista_cheia->inserir_frente(terceiro_valor);

    int valor_topo = lista_cheia->topo->valor;
    int numero_elementos = lista_cheia->contador;
   
    ASSERT_EQ(valor_topo,terceiro_valor);
    ASSERT_EQ(numero_elementos, 3);
}
    
    

TEST(TestesListaSimples, InserirUmItemNoFundoComListaVazia){
    ListaSimples<int> *lista_vazia = new ListaSimples<int>();

    int valor = 20;
    lista_vazia->inserir_fundo(20);

    int valor_topo = lista_vazia->topo->valor;
    int numero_elementos = lista_vazia->contador;

    ASSERT_EQ(valor_topo,valor);
    ASSERT_EQ(numero_elementos, 1);
}

TEST(TestesListaSimples, InserirVariosItensNoFundo){
    ListaSimples<int> *lista_cheia = new ListaSimples<int>();

    int valor_1 = 35;
    int valor_2 = 55;
    int valor_3 = 75;

    lista_cheia->inserir_fundo(valor_1);
    lista_cheia->inserir_fundo(valor_2);
    lista_cheia->inserir_fundo(valor_3);

    int valor_topo = lista_cheia->topo->valor;
    int ultimo_valor = lista_cheia->topo->proximo->proximo->valor;
    int numero_elementos = lista_cheia->contador;
    
    ASSERT_NE(valor_topo, ultimo_valor);
    ASSERT_EQ(numero_elementos , 3);
    ASSERT_EQ(valor_topo, valor_1);
    ASSERT_EQ(ultimo_valor,valor_3);
}

TEST(TestesListaSimples, InserindoNaUltimaPosicaoValida){
    ListaSimples<int> *lista = new ListaSimples<int>();

    /*
        Lista com 4 posições e 5 elementos-> Contador de elementos estará em 5->
        Posições válidas 0 até "contador", onde contador representa a posição depois
        do ultimo elemento, ou seja, insere depois dele->
    */

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);
    lista->inserir_fundo(3);
    lista->inserir_fundo(4);
    
    
    int valor_inserido = 10;

    lista->inserir_posicao(valor_inserido,4);

    int ultimo_valor = lista->topo->proximo->proximo->proximo->proximo->valor;
    int numero_elementos = lista->contador;

    ASSERT_EQ(ultimo_valor, valor_inserido);
    ASSERT_EQ(numero_elementos, 5);
}


TEST(TestesListaSimples, InserindoNaPrimeiraPosicaoValida){
    /* 
        Inserir na primeira posição deve ser equivalente 
        a executar inserir_frente()
    */
   
    ListaSimples<int> *lista_n = new ListaSimples<int>();
    ListaSimples<int> *lista_p = new ListaSimples<int>();

    lista_n->inserir_frente(30);
    lista_n->inserir_frente(40);
    lista_n->inserir_frente(50);

    lista_p->inserir_frente(30);
    lista_p->inserir_frente(40);
    lista_p->inserir_frente(50);

    int valor_inserido = 60;

    lista_n->inserir_frente(valor_inserido);
    lista_p->inserir_posicao(valor_inserido,0);

    int primeiro_valor_n = lista_n->topo->valor;
    int primeiro_valor_p = lista_p->topo->valor;
    
    int contador_n = lista_n->contador;
    int contador_p = lista_p->contador;

    ASSERT_EQ(primeiro_valor_n, valor_inserido);
    ASSERT_EQ(primeiro_valor_n, primeiro_valor_p);
    ASSERT_EQ(contador_n, 4);
    ASSERT_EQ(contador_n,contador_p);

}

TEST(TestesListaSimples, InserirPosicaoNoMeioDaLista){
    ListaSimples<int> *lista = new ListaSimples<int>();

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);// Valor que aponta para o novo elemento
    lista->inserir_fundo(3);// Valor do ponteiro proximo
    lista->inserir_fundo(4);
    lista->inserir_fundo(5);

    int valor_inserido = 13;

    lista->inserir_posicao(valor_inserido,2);

    int valor_posicao_2 = lista->topo->proximo->proximo->proximo->valor; 
    int numero_elementos = lista->contador;

    ASSERT_EQ(valor_posicao_2, valor_inserido);
    ASSERT_EQ(numero_elementos, 6);
}

TEST(TestesListaSimples, ProcurarSeContemElemento){
    ListaSimples<int> *lista = new ListaSimples<int>();

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);
    lista->inserir_fundo(3);
    lista->inserir_fundo(4);
    lista->inserir_fundo(5);

    bool contem_1 = lista->procurar_chave(1);
    bool contem_3 = lista->procurar_chave(3);
    bool contem_5 = lista->procurar_chave(5);
    bool contem_30 = lista->procurar_chave(30);

    ASSERT_TRUE(contem_1);
    ASSERT_TRUE(contem_3);
    ASSERT_TRUE(contem_5);
    ASSERT_FALSE(contem_30);
}

TEST(TestesListaSimples, RemoverPrimeiroElemento){
    ListaSimples<int> *lista = new ListaSimples<int>();

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);
    lista->inserir_fundo(3);
    lista->inserir_fundo(4);
    lista->inserir_fundo(5);

    lista->remover_instancia(1);

    int valor_topo = lista->topo->valor;
    int numero_elementos_restantes = lista->contador;
    bool elemento_presente = lista->procurar_chave(1);

    
    ASSERT_FALSE(elemento_presente);
    ASSERT_EQ(valor_topo, 2);
    ASSERT_EQ(numero_elementos_restantes, 4);
}

TEST(TestesListaSimples, RemoverUltimoElemento){
    ListaSimples<int> *lista = new ListaSimples<int>();

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);
    lista->inserir_fundo(3);
    lista->inserir_fundo(4);
    lista->inserir_fundo(5);

    lista->remover_instancia(5);

    int ultimo_valor = lista->topo->proximo->proximo->proximo->valor;
    int numero_elementos_restantes = lista->contador;
    bool elemento_presente = lista->procurar_chave(5);

    ASSERT_FALSE(elemento_presente);
    ASSERT_EQ(ultimo_valor, 4);
    ASSERT_EQ(numero_elementos_restantes, 4);
}

TEST(TestesListaSimples, RemoverElementoNoMeio){
    ListaSimples<int> *lista = new ListaSimples<int>();

    lista->inserir_fundo(1);
    lista->inserir_fundo(2);
    lista->inserir_fundo(3);
    lista->inserir_fundo(4);
    lista->inserir_fundo(5);

    int chave = 3;
    lista->remover_instancia(chave);

    bool valor_presente = lista->procurar_chave(chave);
    int numero_elementos_restantes = lista->contador;
    
    ASSERT_FALSE(valor_presente);
    ASSERT_EQ(numero_elementos_restantes, 4);
}