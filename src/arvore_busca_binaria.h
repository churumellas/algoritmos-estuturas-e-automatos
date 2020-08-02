#include <iostream>
#include "listadupla.h"

template <typename T>
class NodeAvoreBinaria{
public:
    T valor;
    NodeAvoreBinaria<T>* direita;
    NodeAvoreBinaria<T>* esquerda;
    NodeAvoreBinaria<T>* pai;

    NodeAvoreBinaria(T entrada);
};

template <typename T>
class ArvoreBuscaBinaria{
public:
    NodeAvoreBinaria<T>* root;

    ArvoreBuscaBinaria();

    void inserir_folha(T valor);

    void remover_folha(T valor);

    bool buscar_folha(T valor);

    void mostrar_arvore(std::string modo);
    
    ListaDupla<T> arvore_em_ordem();

    ListaDupla<T> arvore_pre_ordem();

    ListaDupla<T> arvore_pos_ordem();

};


// Implementação construtor NodeArvoreBinaria
template <typename T>
NodeAvoreBinaria<T>::NodeAvoreBinaria(T entrada){
    valor = entrada;
}

//Implementação métodos arvore binária
template <typename T>
ArvoreBuscaBinaria<T>::ArvoreBuscaBinaria(){
    root->direita = nullptr;
    root->esquerda = nullptr;
    root->pai = nullptr;
}

template <typename T>
void ArvoreBuscaBinaria<T>::inserir_folha(T valor){
    //TODO: INSERIR FOLHA
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_em_ordem(){
    //TODO: RETORNAR UMA LISTA COM A ARVORE **EM ORDEM**
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_pos_ordem(){
    //TODO: RETORNAR UMA LISTA COM A ARVORE **POS** ORDEM
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_pre_ordem(){
    //TODO: RETORNAR UMA LISTA COM A ARVORE **PRE** ORDEM
}
