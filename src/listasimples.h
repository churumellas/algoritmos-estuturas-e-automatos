#include <iostream>


template <typename T>
class NodeSimples{
    T valor;
    NodeSimples* proximo;

    NodeSimples(T valor_entrada, NodeSimples proximo_entrada);

    NodeSimples(T valor_entrada);
};

template <typename T>
class ListaSimples{
public:
    int contador;
    NodeSimples<T> *topo;
    NodeSimples<T> *base;

    ListaSimples();

    void inserir_frente(T valor);

    void inserir_fundo(T valor);

    void inserir_posicao(T valor, int posicao);
        
    bool procurar_chave(T chave);
        
    bool esta_vazio();

};
