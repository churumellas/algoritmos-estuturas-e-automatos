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
    }else if(posicao >= tamanho){
        inserir_fundo(valor);
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
    }
}

template <typename T>
void ListaDupla<T>::remover_primeiro(T valor){
    NodeDuplo<T> *leitor = cabeca;
    int posicao_atual = 0;
    while((cabeca->valor != valor) || posicao_atual < tamanho){
        leitor = leitor->proximo;
        posicao_atual++;
    }

    if(leitor == nullptr){
        return
    }else if(leitor == cabeca){
        cabeca = leitor->proximo;
        cabeca->anterior = nullptr;
        leitor->proximo = nullptr;
        free(leitor);
    }else if(leitor == cauda){
        cauda = cauda->anterior;
        cauda->anterior = nullptr;
        leitor->anterior = nullptr;
        free(leitor);
    }else{
        leitor->proximo->anterior = leitor->anterior;
        leitor->anterior->proximo = leitor->proximo;
        leitor->proximo = nullptr;
        leitor->anterior = nullptr;
        free(leitor);
    }
    tamanho--;
}