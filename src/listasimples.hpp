#include <iostream>

template <typename T>
class Node{
    T valor;
    Node* proximo;

    Node(T valor_entrada, Node proximo_entrada){
        valor = valor_entrada;
        proximo = proximo_entrada;
    }

    Node(T valor_entrada){
        valor = valor_entrada;
        proximo = nullptr;
    }
};

template <typename T>
class ListaSimples{
public:
    int contador;
    Node<T> *topo;
    Node<T> *base;

    ListaSimples(){
        topo = nullptr;
        base = nullptr;
        contador = 0;
    }

    void inserir_frente(T valor){
        if(contador == 0){
            topo = new Node<T>(valor);
            base = topo;
        }else{
            Node<T> novoNode = new Node<T>(valor,topo);
            topo = novoNode;
        }
        contador++;
    }

    void inserir_fundo(T valor){
        if(contador == 0){
            topo = new Node<T>(valor);
            base = topo;
        }else {
            base->proximo = new Node<T>(valor);
            base = base->proximo;
        }
        contador++;
    }

    void inserir_posicao(T valor, int posicao){
        if(contador == 0){
            topo = new Node<T>(valor);
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
            Node<T> *leitor = topo;
            int posicao_leitor = 0;
            while(posicao_leitor != posicao) {
                leitor = leitor->proximo;
            }
            leitor->proximo = new Node<T>(valor,leitor->proximo);
        }
        contador++;
    }

    bool procurar_chave(T chave){
        Node<T> *leitor = topo;
        for(int index=0;index < contador;index++){
            if(leitor->valor == chave){
                return true;
            }
            leitor = leitor->proximo;
        }
        return false;
    }

    bool esta_vazio(){
        if(contador == 0) return true;
        else return false;
    }

};
