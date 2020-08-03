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
    int altura;
    int nodes;
    NodeAvoreBinaria<T>* root;

    ArvoreBuscaBinaria();

    void inserir_folha(T valor);

    void remover_folha(T valor);

    bool buscar_folha(T chave);

    bool busca_iterativa(T chave);

    void mostrar_arvore(std::string modo);

    T maximo();

    T minimo();
    
    ListaDupla<T> arvore_em_ordem(NodeAvoreBinaria<T> *node);

    ListaDupla<T> arvore_pre_ordem(NodeAvoreBinaria<T> *node);

    ListaDupla<T> arvore_pos_ordem(NodeAvoreBinaria<T> *node);

private:
    bool buscar_folha(NodeAvoreBinaria<T> *leitor, T valor);
    void printar_ordem(NodeAvoreBinaria<T> *leitor);
    void printar_pre_ordem(NodeAvoreBinaria<T> *leitor);
    void printar_pos_ordem(NodeAvoreBinaria<T> *leitor);

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
    altura = 0;
    nodes = 0;
}

template <typename T>
void ArvoreBuscaBinaria<T>::printar_ordem(NodeAvoreBinaria<T> *leitor){
    if(leitor!= nullptr){
        printar_ordem(leitor->esquerda);
        std::cout << leitor->valor << " ";
        printar_ordem(leitor->direita);
    }
}

template <typename T>
void ArvoreBuscaBinaria<T>::printar_pre_ordem(NodeAvoreBinaria<T> *leitor){
    if(leitor!= nullptr){
        std::cout << leitor->valor << " ";
        printar_ordem(leitor->esquerda);
        printar_ordem(leitor->direita);
    }
}

template <typename T>
void ArvoreBuscaBinaria<T>::printar_pos_ordem(NodeAvoreBinaria<T> *leitor){
    if(leitor!= nullptr){
        printar_ordem(leitor->esquerda);
        printar_ordem(leitor->direita);
        std::cout << leitor->valor << " ";
    }
}

template <typename T>
void ArvoreBuscaBinaria<T>::printar_ordem(NodeAvoreBinaria<T> *leitor){
    if(leitor!= nullptr){
        printar_ordem(leitor->esquerda);
        std::cout << leitor->valor << " ";
        printar_ordem(leitor->direita);
    }
}

template <typename T>
void ArvoreBuscaBinaria<T>::mostrar_arvore(std::string modo){
    
    /*
        ord - Mostrar arvore em ordem
        pre - Mostrar árvore pre ordem
        pos - Mostrar árvore pos ordem
    */
   
    if(modo == "ord")
        printar_ordem(root);
    
    if(modo == "pre")
        printar_pre_ordem(root);
    
    if(modo == "pos")
        printar_pos_ordem(root);
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_em_ordem(NodeAvoreBinaria<T>* node){
    static ListaDupla<T> elementos_em_ordem = new ListaDupla<T>();
    if(node != nullptr){
        arvore_em_ordem(node->esquerda);
        elementos_em_ordem.inserir_fundo(node->valor);
        arvore_em_ordem(node->direita);
    }
    if(node == root)
        return elementos_em_ordem;
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_pos_ordem(NodeAvoreBinaria<T> *node){
    static ListaDupla<T> elementos_em_ordem = new ListaDupla<T>();
    if(node != nullptr){
        arvore_em_ordem(node->esquerda);
        arvore_em_ordem(node->direita);
        elementos_em_ordem.inserir_fundo(node->valor);
    }
    if(node == root)
        return elementos_em_ordem;
}

template <typename T>
ListaDupla<T> ArvoreBuscaBinaria<T>::arvore_pre_ordem(NodeAvoreBinaria<T> *node){
    static ListaDupla<T> elementos_em_ordem = new ListaDupla<T>();
    if(node != nullptr){
        elementos_em_ordem.inserir_fundo(node->valor);
        arvore_em_ordem(node->esquerda);
        arvore_em_ordem(node->direita);
    }
    if(node == root)
        return elementos_em_ordem;
}

template <typename T>
bool ArvoreBuscaBinaria<T>::buscar_folha(NodeAvoreBinaria<T> *leitor,T chave){
    if(leitor == nullptr){
        return false;
    }
    else if(leitor->valor == chave){
        return true;
    }

    if(leitor->valor > chave) return buscar_folha(leitor->esquerda);
    else(leitor->valor < chave) return buscar_folha(leitor->direita);
}

template <typename T>
bool ArvoreBuscaBinaria<T>::buscar_folha(T chave){
    return buscar_folha(root, chave);
}

template <typename T>
bool ArvoreBuscaBinaria<T>::busca_iterativa(T chave){
    NodeAvoreBinaria<T> *leitor = root;
    while(leitor->valor != chave){
        if(leitor->valor < chave) leitor = leitor->esquerda;
        else leitor = leitor->direita;

        if(leitor == nullptr) return false;
    }
    return true;
}

template <typename T>
void ArvoreBuscaBinaria<T>::inserir_folha(T valor){
    //TODO: INSERIR FOLHA
}

template <typename T>
void ArvoreBuscaBinaria<T>::remover_folha(T valor){
    //TODO: REMOVER FOLHA
}

template <typename T>
T ArvoreBuscaBinaria<T>::maximo(){
    NodeAvoreBinaria<T> *leitor = root;
    while(leitor->direita != nullptr)
        leitor = leitor->direita;
    
    return leitor->valor;
}

template <typename T>
T ArvoreBuscaBinaria<T>::minimo(){
    NodeAvoreBinaria<T> *leitor = root;
    while(leitor->esquerda != nullptr)
        leitor = leitor->esquerda;
    
    return leitor->valor;
}
