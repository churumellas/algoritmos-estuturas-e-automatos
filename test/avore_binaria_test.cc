#include <gtest/gtest.h>
#include "src/arvore_busca_binaria.h"

TEST(TestesArvoreBuscaBinaria, CriarUmaArvoreVazia){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    int numero_nodes = arvore->nodes;
    
    ASSERT_EQ(numero_nodes, 0);
}

TEST(TestesArvoreBuscaBinaria, InseirUmElementoNaArvore){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(10);

    int valor_raiz = arvore->root->valor;
    int numero_elementos = arvore->nodes;

    ASSERT_EQ(1, numero_elementos);
    ASSERT_EQ(valor_raiz, 10);
}

TEST(TestesArvoreBuscaBinaria, InserirMultiplosElementosNaArvore){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(6);
    arvore->inserir_folha(3);
    arvore->inserir_folha(7);
    arvore->inserir_folha(2);
    arvore->inserir_folha(9);
    

    int numero_elementos = arvore->nodes;
    int valor_raiz = arvore->root->valor;

    ASSERT_EQ(5, numero_elementos);
    ASSERT_EQ(6, valor_raiz);
}

TEST(TestesArvoreBuscaBinaria, RemoverUmItemDaArvore){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *alvo = arvore->buscar_folha(7);
    arvore->remover_folha(alvo);
    int numero_elementos = arvore->nodes;
    int valor_raiz = arvore->root->valor;

    ASSERT_EQ(numero_elementos, 6);
    ASSERT_EQ(valor_raiz, 5);
}

TEST(TestesArvoreBuscaBinaria, RemoverMesmoItemDuasVezes){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *alvo = arvore->buscar_folha(7);
    arvore->remover_folha(alvo);
    arvore->remover_folha(alvo);
    int numero_elementos = arvore->nodes;
    int valor_raiz = arvore->root->valor;

    //NOTE: Apagar depois
    arvore->mostrar_arvore("ord");

    ASSERT_EQ(numero_elementos, 6);
    ASSERT_EQ(valor_raiz, 5);
}

TEST(TestesArvoreBuscaBinaria, BuscarNaArvoreRecursivamente){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(6);
    arvore->inserir_folha(7);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *resultado_busca = arvore->buscar_folha(1);
    int valor_node = resultado_busca->valor;

    ASSERT_EQ(valor_node, 1);    
}

TEST(TestesArvoreBuscaBinaria,RemoverDoisElementos){
    //TODO: Remover duas vezes na mesma arvore com valores diferentes

}

TEST(TestesArvoreBuscaBinaria, SucessorDoNodeCorreto){
    //TODO: Checar se sucessor está correto

}

TEST(TestesArvoreBuscaBinaria,AntecessorDoNodeCorreto){
    //TODO: Checar se antecessor está correto
}

TEST(TestesArvoreBuscaBinaria, ValorMaximoEstaCorreto){
    //TODO: Verificar se valor maximo é o maior

}

TEST(TestesArvoreBuscaBinaria, ValorMinimoEstaCorreto){
    //TODO: Verificar se valor minimo é o menor

}

TEST(TestesArvoreBuscaBinaria, ValoresDaListaEstaoEmOrdem){
    //TODO: Verificar se lista com valores em ordem está correta

}

TEST(TestesArvoreBuscaBinaria,ValoresDaListaEstaoEmPreOrdem){
    //TODO: Verificar se lista com valores em pre-ordem está correta

}
TEST(TestesArvoreBuscaBinaria, ValoresDaListaEstaoEmPosOrdem){
    //TODO: Verificar se lista com valores em pos-ordem está correta

}