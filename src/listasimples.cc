#include <iostream>
#include "listasimples.h"


// Implementação dos métodos para classe NodeSimples
template <typename T>
NodeSimples<T>::NodeSimples(T valor_entrada, NodeSimples proximo_entrada){
    valor = valor_entrada;
    proximo = proximo_entrada;
}

template <typename T>
NodeSimples<T>::NodeSimples(T valor_entrada){
    valor = valor_entrada;
    proximo = nullptr;
}

//Implementação para métodos da classe ListaSimples
template <typename T>
ListaSimples<T>::ListaSimples(){
    topo = nullptr;
    base = nullptr;
    contador = 0;
}


template <typename T>
void ListaSimples<T>::inserir_frente(T valor){
        if(contador == 0){
            topo = new NodeSimples<T>(valor);
            base = topo;
        }else{
            NodeSimples<T> novoNodeSimples = new NodeSimples<T>(valor,topo);
            topo = novoNodeSimples;
        }
        contador++;
}

template <typename T>
void ListaSimples<T>::inserir_fundo(T valor){
    if(contador == 0){
        topo = new NodeSimples<T>(valor);
        base = topo;
    }else {
        base->proximo = new NodeSimples<T>(valor);
        base = base->proximo;
    }
    contador++;
}

template <typename T>
void ListaSimples<T>::inserir_posicao(T valor, int posicao){
    if(contador == 0){
        topo = new NodeSimples<T>(valor);
        base = topo;
    }else if(posicao > contador || posicao < 0){
        std::cout <<"[ERRO] Posição inválida para inserção." 
        << "Erro em " 
        << __FILE__
        << " linha" 
        << __LINE__;
        exit(-1);
    }else if (posicao == 0){
        inserir_frente(valor);
    }else if(posicao == contador+1){
        inserir_fundo(valor);
    }else{
        NodeSimples<T> *leitor = topo;
        int posicao_leitor = 0;
        while(posicao_leitor != posicao) {
            leitor = leitor->proximo;
        }
        leitor->proximo = new NodeSimples<T>(valor,leitor->proximo);
    }
    contador++;
}

template <typename T>
bool ListaSimples<T>::procurar_chave(T chave){
        NodeSimples<T> *leitor = topo;
        for(int index=0;index < contador;index++){
            if(leitor->valor == chave){
                return true;
            }
            leitor = leitor->proximo;
        }
        return false;
}
template <typename T>
bool ListaSimples<T>::esta_vazio(){
    if(contador == 0) return true;
    else return false;
}
