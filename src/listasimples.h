#include <iostream>

template <typename T>
class NodeSimples{
public:
    T valor;
    NodeSimples* proximo;

    NodeSimples(T valor_entrada, NodeSimples<T>* proximo_entrada);

    NodeSimples(T valor_entrada);
};

template <typename T>
class ListaSimples{
public:
    int contador;
    NodeSimples<T> *topo;
    
    ListaSimples();

    void inserir_frente(T valor);

    void inserir_fundo(T valor);

    void inserir_posicao(T valor, int posicao);
        
    bool remover_instancia(T valor);

    bool procurar_chave(T chave);
        
    bool esta_vazio();

};


// Implementação dos métodos para classe NodeSimples
template <typename T>
NodeSimples<T>::NodeSimples(T valor_entrada){
    valor = valor_entrada;
    proximo = nullptr;
}

//Implementação para métodos da classe ListaSimples
template <typename T>
ListaSimples<T>::ListaSimples(){
    topo = nullptr;

    contador = 0;
}


template <typename T>
void ListaSimples<T>::inserir_frente(T valor){
        if(contador == 0){
            topo = new NodeSimples<T>(valor);
        }else{
            NodeSimples<T> *novoNodeSimples = new NodeSimples<T>(valor);
            novoNodeSimples->proximo = topo;
            topo = novoNodeSimples;
        }
        contador++;
}

template <typename T>
void ListaSimples<T>::inserir_fundo(T valor){
    if(contador == 0){
        topo = new NodeSimples<T>(valor);
    }else {
        NodeSimples<T> *leitor;
        leitor = topo;
        while(leitor->proximo != nullptr){
            leitor = leitor->proximo;
        }
        leitor->proximo = new NodeSimples<T>(valor);
    }
    contador++;
}

template <typename T>
void ListaSimples<T>::inserir_posicao(T valor, int posicao){
    if(contador == 0){
        topo = new NodeSimples<T>(valor);
    }else if(posicao > contador || posicao < 0){
        std::cout <<"[ERRO] Posição inválida para inserção." 
        << "Erro em " 
        << __FILE__
        << " linha" 
        << __LINE__;
        exit(-1);
    }else if (posicao == 0){
        inserir_frente(valor);
    }else if(posicao == contador){
        inserir_fundo(valor);
    }else{
        NodeSimples<T> *leitor = topo;
        int posicao_leitor = 0;
        while(posicao_leitor != posicao) {
            leitor = leitor->proximo;
            posicao_leitor++;
        }
        if(leitor->proximo == nullptr){
            NodeSimples<T>* newNode = new NodeSimples<T>(valor);
            newNode->proximo = leitor->proximo;
            leitor->proximo = newNode;
        }else{
            leitor->proximo =  new NodeSimples<T>(valor);
        }
        contador++;
    }
}

template <typename T>
bool ListaSimples<T>::remover_instancia(T valor){
    if(contador == 0){
        return false;
    }else if((contador == 1 ) && (topo->valor == valor)){
        topo = nullptr;
        contador--;
        return true;
    }else {
        NodeSimples<T> *leitor = topo;
        NodeSimples<T> *pre_leitor;
        while((leitor != nullptr) && (leitor->valor != valor)){
            pre_leitor = leitor;            
            leitor = leitor->proximo;
        }
        if(leitor != nullptr){
            pre_leitor->proximo = leitor->proximo;
            free(leitor);
            contador--;
            return true;
        }else{
            return false;
        }
        
    }
    
    return false;
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
