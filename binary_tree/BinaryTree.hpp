#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <list>
#include <deque>
#include <queue>
#include <unordered_map>

#include "binary_node/BinaryNode.hpp"

using namespace std;

template <typename T>
class BinaryTree
{
protected:
    BinaryNode<T> *root;

private:
    bool addNodeAux(T const &data, BinaryNode<T> *&node);
    void preOrderAux(BinaryNode<T> *node, list<T> &list) const;
    void inOrderAux(BinaryNode<T> *node, list<T> &list) const;
    void postOrderAux(BinaryNode<T> *node, list<T> &list) const;
    int alturaNodoAux(BinaryNode<T> *&node) const;
    bool balanceo(BinaryNode<T> *&node);
    void rightRotation(BinaryNode<T> *&node);
    void leftRotation(BinaryNode<T> *&node);
    BinaryNode<T>* highestNodeLeft(BinaryNode<T> *&node) const;
    BinaryNode<T>* highestNodeLeftAux(BinaryNode<T> *&node) const;
    bool deleteNodeAux(T const &data, BinaryNode<T> *&node);
    void byLevelsAux(BinaryNode<T> *node, list<T> &list) const;


public:
    /* Constructor and Destructor */
    explicit BinaryTree(T const &data);
    explicit BinaryTree(BinaryNode<T> *&node);
    BinaryTree();
    ~BinaryTree();

    /* Getters and Setters */
    T getRoot() const;
    BinaryNode<T>* getRootNode() const;

    // No tiene sentido implementar un setter para el nodo raíz, ya que
    // no se deberia poder cambiar el nodo raíz de un árbol binario.
    // void setRoot(BinaryNode<T> *root);

    int alturaNodo(BinaryNode<T> *node) const;

    bool deleteNode(T const &data);




    bool isEmpty() const;

    bool addNode(T const &data);


    list<T> preOrder() const;
    list<T> inOrder() const;
    list<T> postOrder() const;
    list<T> byLevels() const;
};

#include "BinaryTree.cpp"
#endif //BINARY_TREE_HPP
