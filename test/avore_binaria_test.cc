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
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *alvo1 = arvore->buscar_folha(1);
    NodeAvoreBinaria<int> *alvo2 = arvore->buscar_folha(8);
    arvore->remover_folha(alvo1);
    arvore->remover_folha(alvo2);

    int numero_node =arvore->nodes;
    //ATENTION: Verificar melhor se realmente removeu node da estrutura
    ASSERT_EQ(6, numero_node);
}

TEST(TestesArvoreBuscaBinaria, SucessorDoNodeCorreto){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *node_6 = arvore->buscar_folha(6);
    NodeAvoreBinaria<int> *node_5 = arvore->buscar_folha(5);

    NodeAvoreBinaria<int> *sucessor_6 = arvore->sucessor(node_6);
    NodeAvoreBinaria<int> *sucessor_5 = arvore->sucessor(node_5);

    ASSERT_EQ(sucessor_5->valor, 6);
    ASSERT_EQ(sucessor_6->valor, 7);
}

TEST(TestesArvoreBuscaBinaria,AntecessorDoNodeCorreto){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *node_6 = arvore->buscar_folha(6);
    NodeAvoreBinaria<int> *node_5 = arvore->buscar_folha(5);

    NodeAvoreBinaria<int> *antecessor_6 = arvore->antecessor(node_6);
    NodeAvoreBinaria<int> *antecessor_5 = arvore->antecessor(node_5);

    ASSERT_EQ(5, antecessor_6->valor);
    ASSERT_EQ(6, antecessor_5->valor);
}

TEST(TestesArvoreBuscaBinaria, ValorMaximoEstaCorreto){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *maximo = arvore->maximo_arvore();
    ASSERT_EQ(10, maximo->valor);
}

TEST(TestesArvoreBuscaBinaria, ValorMinimoEstaCorreto){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    NodeAvoreBinaria<int> *minimo = arvore->minimo_arvore();
    ASSERT_EQ(1, minimo->valor);

}

TEST(TestesArvoreBuscaBinaria, ValoresDaListaEstaoEmOrdem){
    //TODO: Verificar se lista com valores em ordem está correta
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    ListaDupla<int> *lista_em_ordem = arvore->arvore_em_ordem(arvore->root); 
    int sequencia_esperada[] = {1,4,5,6,7,8,9,10};

    NodeDuplo<int> *leitor = lista_em_ordem->cabeca;
    int index = 0;
    while((leitor!=nullptr )&& (index < 8)){
        ASSERT_EQ(leitor->valor, sequencia_esperada[index]);
        leitor = leitor->proximo;
        index++;
    }
}

TEST(TestesArvoreBuscaBinaria,ValoresDaListaEstaoEmPreOrdem){
    //TODO: Verificar se lista com valores em pre-ordem está correta
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    ListaDupla<int> *lista_em_pre_ordem = arvore->arvore_pre_ordem(arvore->root); 
    int sequencia_esperada[] = {5,4,1,7,6,8,9,10};

    NodeDuplo<int> *leitor = lista_em_pre_ordem->cabeca;
    int index = 0;
    while((leitor!=nullptr )&& (index < 8)){
        ASSERT_EQ(leitor->valor, sequencia_esperada[index]);
        leitor = leitor->proximo;
        index++;
    }
}
TEST(TestesArvoreBuscaBinaria, ValoresDaListaEstaoEmPosOrdem){
    ArvoreBuscaBinaria<int> *arvore = new ArvoreBuscaBinaria<int>();
    arvore->inserir_folha(5);
    arvore->inserir_folha(7);
    arvore->inserir_folha(6);
    arvore->inserir_folha(4);
    arvore->inserir_folha(8);
    arvore->inserir_folha(9);
    arvore->inserir_folha(1);
    arvore->inserir_folha(10);

    ListaDupla<int> *lista_em_pos_ordem = arvore->arvore_pos_ordem(arvore->root); 
    int sequencia_esperada[] = {1,4,6,10,9,8,7,5};

    NodeDuplo<int> *leitor = lista_em_pos_ordem->cabeca;
    int index = 0;
    while((leitor!=nullptr )&& (index < 8)){
        ASSERT_EQ(leitor->valor, sequencia_esperada[index]);
        leitor = leitor->proximo;
        index++;
    }
}