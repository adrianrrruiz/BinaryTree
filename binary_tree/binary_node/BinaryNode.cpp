#include "BinaryNode.hpp"


template<typename T>
BinaryNode<T>::BinaryNode(T data){
    this->data = data;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}


template <typename T>
BinaryNode<T>::BinaryNode(T data, BinaryNode<T> *left, BinaryNode<T> *right)
{
    this->data = data;
    this->leftChild = left;
    this->rightChild = right;
}

/*
template <typename T>
BinaryNode<T>::~BinaryNode()
{
    delete leftChild;
    leftChild = nullptr;
    delete rightChild;
    rightChild = nullptr;
}
 */
/*
//Comparador para utilizar en la cola de prioridad
template <typename T>
bool operator<(const BinaryNode<T>& lhs, const BinaryNode<T>& rhs) {
    return lhs.data > rhs.data;
}
*/
template <typename T>
T BinaryNode<T>::getData() const
{
    return data;
}

template <typename T>
void BinaryNode<T>::setData(T data)
{
    this->data = data;
}


template <typename T>
BinaryNode<T> *BinaryNode<T>::getLeft() const
{
    return leftChild;
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T> *left)
{
    this->leftChild = left;
}


template <typename T>
BinaryNode<T> *BinaryNode<T>::getRight() const
{
    return rightChild;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T> *right)
{
    this->rightChild = right;
}

template <typename T>
bool BinaryNode<T>::operator==(const BinaryNode<T> &otherBinaryNode) const
{
    return data == otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::operator!=(const BinaryNode<T> &otherBinaryNode) const
{
    return !(otherBinaryNode == *this);
}

template <typename T>
bool BinaryNode<T>::operator<(const BinaryNode<T> &otherBinaryNode) const
{
    return data < otherBinaryNode.data;
}

template <typename T>
bool BinaryNode<T>::operator>(const BinaryNode &otherBinaryNode) const
{
    return data > otherBinaryNode.data;
}


template <typename T>
bool BinaryNode<T>::operator<(const BinaryNode<T>* otherBinaryNode) const
{
    return data < otherBinaryNode->data;
}

template <typename T>
bool BinaryNode<T>::operator>(const BinaryNode<T>* otherBinaryNode) const
{
    return data > otherBinaryNode->data;
}




template <typename T>
bool BinaryNode<T>::isLeaf() const
{
    return leftChild == nullptr && rightChild == nullptr;
}

template <typename U>
ostream &operator<<(ostream &os, const BinaryNode<U> &binaryNode)
{
    os << "data: " << binaryNode.data;
    return os;
}