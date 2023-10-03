#include "BinaryTree.hpp"

//SECCION AVL

template <typename T>
void BinaryTree<T>::leftRotation(BinaryNode<T> *&node){
    //Nodo auxiliar
    BinaryNode<T>* binaryAux;
    binaryAux = node;

    //El padre se convierte en el hijo derecho del mismo
    node = node->rightChild;

    //El auxiliar toma como hijo derecho al hijo izquierdo del nuevo padre
    binaryAux->rightChild = node->leftChild;

    //El padre actual, toma como hijo izquierdo el que antes fue su padre
    node->leftChild = binaryAux;

}

template <typename T>
void BinaryTree<T>::rightRotation(BinaryNode<T> *&node){
    //Nodo auxiliar
    BinaryNode<T>* binaryAux;
    binaryAux = node;

    //El padre se convierte en el hijo izquierdo del mismo
    node = node->leftChild;

    //El auxiliar toma como hijo izquierdo al hijo derecho del nuevo padre
    binaryAux->leftChild = node->rightChild;

    //El padre actual, toma como hijo izquierdo el que antes fue su padre
    node->rightChild = binaryAux;

}

template <typename T>
bool BinaryTree<T>::balanceo(BinaryNode<T> *&node){
    int debug1;
    int debug2;
    if(node->isLeaf()){
        return false;
    }
    //Si la diferencia es de 2 positivo, la altura izquierda es mayor
    debug1 = alturaNodo(node->leftChild)+1;
    debug2 = alturaNodo(node->rightChild)+1;

    if((alturaNodo(node->leftChild)+1)-(alturaNodo(node->rightChild)+1)==2){


        if((alturaNodo(node->leftChild->leftChild)+1)-(alturaNodo(node->leftChild->rightChild)+1)<0){
            //left-right rotation
            leftRotation(node->leftChild);
        }


        rightRotation(node);
        return true;
    }
    //Si la diferencia es de 2 negativo, la altura derecha es mayor
    //Sumamos 1 al dato retornado, debido a que cuando llamamos la funcion, ya aumentamos 1 el recorrido.

    if((alturaNodo(node->leftChild)+1)-(alturaNodo(node->rightChild)+1)==-2){

        //Right-left rotation
        if(((alturaNodo(node->rightChild->leftChild))+1)-((alturaNodo(node->rightChild->rightChild))+1)>0){
            //Al ser el izquierdo mas pesado, rotamos a la derecha
            rightRotation(node->rightChild);
        }



        leftRotation(node);
        return true;
    }
    return false;
}

template <typename T>
int BinaryTree<T>::alturaNodo(BinaryNode<T> *node) const{
    int varIzq = 1;
    int varDer = 1;
    //Retornamos -1 por funcionalidad del metodo balanceo cuando es nulo, debido a que ahi estamos sumando 1 por el
    //consumo de un recorrido, pero si no hubo nada, ese recorrido se invalida
    if(node==nullptr){
        return -1;
    }

    //Si el metodo es llamado desde una hoja o un nulo
    if(node->isLeaf()){
        return 0;
    }

    varIzq+= alturaNodoAux(node->leftChild);
    varDer+= alturaNodoAux(node->rightChild);

    if(varIzq>varDer){
        return varIzq;
    }
    //Si llegamos aqui es porque son iguales, o der es mayor, por ende no tiene relevancia cual se devuelve aqui
    return varDer;


}

template <typename T>
int BinaryTree<T>::alturaNodoAux(BinaryNode<T> *&node) const{
    int varIzq = 1;
    int varDer = 1;

    //Si el nodo no tiene hijo por este lado, retornara 0
    if(node== nullptr){
        return -1;
    }
    //Si se pudo llamar la auxiliar significa que desde donde se llamó no es hoja, por ende retorna 1
    if(node->isLeaf()){
        return 0;
    }

    varIzq+= alturaNodoAux(node->leftChild);
    varDer+= alturaNodoAux(node->rightChild);

    if(varIzq>varDer){
        return varIzq;
    }
    //Si llegamos aqui es porque son iguales, o der es mayor, por ende no tiene relevancia cual se devuelve aqui
    return varDer;
}

//FIN SECCION AVL

template <typename T>
bool BinaryTree<T>::addNodeAux(T const &data, BinaryNode<T> *&node)
{
    if (node == nullptr)
    {
        node = new BinaryNode<T>(data);
        return true;
    }
    else if (data < node->data)
    {
        addNodeAux(data, node->leftChild);
        return balanceo(node);
    }
    else if (data > node->data)
    {
        addNodeAux(data, node->rightChild);
        return balanceo(node);
    }

    // Se supone que un arbol binario no puede tener dos nodos con el mismo valor
    // por lo que si se llega a este punto, se retorna false.
    // Depende de la implementacion necesaria y el problema.
    return false;
}


template <typename T>
bool BinaryTree<T>::deleteNode(T const &data)
{
    return deleteNodeAux(data, root);
}


template <typename T>
bool BinaryTree<T>::deleteNodeAux(T const &data, BinaryNode<T> *&node)
{
    BinaryNode<T> *nodeAux;
    if (data == node->data) {
        if (node->isLeaf()) {
            node = nullptr;
            return true;
        }
        if (node->rightChild == nullptr) {
            node = node->leftChild;
            return true;
        }
        if (node->leftChild == nullptr) {
            node = node->rightChild;
            return true;
        }
        if (node->leftChild != nullptr && node->rightChild != nullptr) {
            nodeAux = highestNodeLeft(node);
            node->data = nodeAux->data;
            //En caso que no tuviese hijo izquierdo se pondría en nulo
            //Un caso con el hijo derecho no tiene sentido porque la funcion de highestNode nos devuelve el
            //de mas a la derecha
            node->leftChild = nodeAux->leftChild;
            return true;
        }
    }
    if(data<node->data){
        deleteNodeAux(data, node->leftChild);
    }
    if(data>node->data){
        deleteNodeAux(data, node->rightChild);
    }

    return balanceo(node);
}

template <typename T>
BinaryNode<T>* BinaryTree<T>::highestNodeLeft(BinaryNode<T> *&node) const
{
    return highestNodeLeftAux(node->leftChild);
}


template <typename T>
BinaryNode<T>* BinaryTree<T>::highestNodeLeftAux(BinaryNode<T> *&node) const
{
    BinaryNode<T> *nodeAux1;

    if(node->isLeaf()){
        return node;
    }
    if(node->rightChild == nullptr){
        return node;
    }

    nodeAux1=highestNodeLeftAux(node->rightChild);

    /*
    //No tiene sentido hacer esta comparación, el lado derecho de un nodo siempre será mayor.
    if(node>nodeAux1){
        return node;
    }
    */
    return nodeAux1;
}


template <typename T>
void BinaryTree<T>::preOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    list.push_back(node->data);
    preOrderAux(node->leftChild, list);
    preOrderAux(node->rightChild, list);
}

template <typename T>
void BinaryTree<T>::inOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    inOrderAux(node->leftChild, list);
    list.push_back(node->data);
    inOrderAux(node->rightChild, list);
}

template <typename T>
void BinaryTree<T>::postOrderAux(BinaryNode<T> *node, list<T> &list) const
{
    if (node == nullptr)
    {
        return;
    }

    postOrderAux(node->leftChild, list);
    postOrderAux(node->rightChild, list);
    list.push_back(node->data);
}



//Constructor con dato
template <typename T>
BinaryTree<T>::BinaryTree(T const &data)
{
    root = new BinaryNode<T>(data);
}
//Constructor con nodo
template <typename T>
BinaryTree<T>::BinaryTree(BinaryNode<T> *&node)
{
    root = node;
}
//Constructor defecto
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}
//Destructor
template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
    root = nullptr;
}

template <typename T>
T BinaryTree<T>::getRoot() const
{
    return root->data;
}

template <typename T>
BinaryNode<T>* BinaryTree<T>::getRootNode() const {
    return root;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
bool BinaryTree<T>::addNode(T const &data)
{
    if (isEmpty())
    {
        root = new BinaryNode<T>(data);
        return true;
    }
    return addNodeAux(data, root);
}

template <typename T>
list<T> BinaryTree<T>::preOrder() const
{
    // Creamos una lista vacia para almacenar los datos del arbol
    // en preorden.
    list<T> list;

    // Llamamos a la funcion auxiliar para recorrer el arbol en preorden.
    // Recibe por referencia la lista vacia para ir agregando los datos
    // del arbol.
    preOrderAux(root, list);

    return list;
}

template <typename T>
list<T> BinaryTree<T>::inOrder() const
{
    list<T> list;

    inOrderAux(root, list);

    return list;
}

template <typename T>
list<T> BinaryTree<T>::postOrder() const
{
    list<T> list;

    postOrderAux(root, list);

    return list;
}

