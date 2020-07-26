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

    void inserir_fundor(T valor){
        if(contador == 0){
            topo = new Node<T>(valor);
            base = topo;
        }else {
            base->proximo = new Node<T>(valor);
            base = base->proximo;
        }
        contador++;
    }
};
