template <typename T>
class NodeDuplo{
public:
    NodeDuplo<T> *proximo;
    NodeDuplo<T> *anterior;
    T valor;

    NodeDuplo(T valor_chave);
};

template <typename T>
class ListaDupla{
public:
    NodeDuplo<T> *cabeca;
    NodeDuplo<T> *cauda;
    int tamanho;

    ListaDupla();

    void inserir_frente(T valor);

    void inserir_fundo(T valor);

    bool inserir_meio(T valor, int posicao);

    void remover_primeiro(T valor);

    void remover_todos(T valor);

    void deletar_node(NodeDuplo<T> *node);

    bool procurar_elemento(T valor);

    bool vazio();
};


//Implementação construtor da classe NodeDuplo
template <typename T>
NodeDuplo<T>::NodeDuplo(T valor_chave){
    valor = valor_chave;
    proximo  = nullptr;
    anterior = nullptr;
}


//Implementação metodos ListaDupla

template <typename T>
ListaDupla<T>::ListaDupla(){
    cabeca = nullptr;
    cauda = nullptr;
    tamanho = 0;
}

template <typename T>
void ListaDupla<T>::inserir_frente(T valor){
    if(tamanho == 0){
        cabeca = new NodeDuplo<T>(valor);
        cauda = cabeca;
    }else{
        NodeDuplo<T> *novoNode = new NodeDuplo<T>(valor);
        novoNode->proximo = cabeca;
        cabeca->anterior = novoNode;
        cabeca = novoNode;
    }
    tamanho++;
}

template <typename T>
void ListaDupla<T>::inserir_fundo(T valor){
    if(tamanho == 0){
        inserir_frente(valor);
    }else{
        NodeDuplo<T> *novoNode = new NodeDuplo<T>(valor);
        cauda->proximo = novoNode;
        novoNode->anterior = cauda;
        cauda = novoNode;
    }
    tamanho++;
}

template <typename T>
bool ListaDupla<T>::inserir_meio(T valor, int posicao){
    if(tamanho == 0){
        inserir_frente(valor);
        return true;
    }else if(posicao >= tamanho){
        inserir_fundo(valor);
        return true;
    }else{
        NodeDuplo<T> *leitor = cabeca;
        NodeDuplo<T> *novoNode = new NodeDuplo<T>(valor);
        for(int index=0;index < posicao;index++){
            leitor = leitor->proximo;
        }
        novoNode->proximo = leitor->proximo;
        leitor->proximo = novoNode;
        novoNode->anterior = leitor;
        novoNode->proximo->anterior = novoNode;

        tamanho++;
        return true;
    }
    return false;
}
template <typename T>
void ListaDupla<T>::deletar_node(NodeDuplo<T> *node){
    if(node->proximo == nullptr){
        node->anterior->proximo = nullptr;
        node->anterior = nullptr;
        delete[] node;
    }else if(node->anterior == nullptr){
        node->proximo->anterior = nullptr;
        node->proximo = nullptr;
        delete[] node;
    }else{
        node->proximo->anterior = node->anterior;
        node->anterior->proximo = node->proximo;
        node->proximo = nullptr;
        node->anterior = nullptr;
        delete[] node;
    }
    tamanho--;
}

template <typename T>
void ListaDupla<T>::remover_primeiro(T valor){
    NodeDuplo<T> *leitor = cabeca;
    int posicao_atual = 0;
    while((leitor->valor != valor) || posicao_atual < tamanho){
        leitor = leitor->proximo;
        posicao_atual++;
    }

    if(leitor == nullptr){
        return;
    }else {
        deletar_node(leitor);
    }
}

template <typename T>
void ListaDupla<T>::remover_todos(T valor){
    NodeDuplo<T> *leitor = cabeca;
    NodeDuplo<T> proximo_leitor;
    while(leitor != nullptr){
        if(leitor->valor == valor){
            proximo_leitor = leitor->proximo;
            deletar_node(leitor.copy());
            leitor = proximo_leitor;
        }else{
            leitor = leitor->proximo;
        }
    }
}

template <typename T>
bool ListaDupla<T>::procurar_elemento(T valor){
    NodeDuplo<T> *leitor = cabeca;
    
    while(leitor != nullptr){
        if(leitor->valor == valor) return true;
        else leitor = leitor->proximo;
    }
}

template <typename T>
bool ListaDupla<T>::vazio(){
    if (tamanho == 0) return true;
    else return false;
}