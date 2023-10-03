#include <iostream>
#include "binary_tree/BinaryTree.hpp"
#include "person/Person.hpp"

int main(int argc, char const *argv[])
{

    BinaryTree<int> myTree = BinaryTree<int>(5);

    cout << myTree.getRoot() << endl;

    /*
    myTree.addNode(3);
    myTree.addNode(7);
    myTree.addNode(2);
    myTree.addNode(4);
    myTree.addNode(6);
    myTree.addNode(8);
    myTree.addNode(9);
    myTree.addNode(10);
    myTree.addNode(0);
    myTree.addNode(1);
*/
    /*
    //prueba right-left
    myTree.addNode(10);
    myTree.addNode(5);
    myTree.addNode(20);
    myTree.addNode(15);
    myTree.addNode(21);
    myTree.addNode(14);
*/
    //Prueba left-right
    myTree.addNode(10);
    myTree.addNode(6);
    myTree.addNode(20);
    myTree.addNode(4);
    myTree.addNode(8);
    myTree.addNode(7);


    list<int> myList = myTree.preOrder();

    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }
    //prueba eliminar
    myTree.deleteNode(10);

    myList = myTree.preOrder();

    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    //fin prueba eliminar

    BinaryTree<Person> myPersonsTree = BinaryTree<Person>(Person("Juan", "Perez", 20));

    cout << endl
         << myPersonsTree.getRoot() << endl;

    myPersonsTree.addNode(Person("Pedro", "Gomez", 30));
    myPersonsTree.addNode(Person("Karol", "Santana", 5));
    myPersonsTree.addNode(Person("Maria", "Lopez", 40));
    myPersonsTree.addNode(Person("Jose", "Garcia", 50));
    myPersonsTree.addNode(Person("Ana", "Martinez", 60));
    myPersonsTree.addNode(Person("Luis", "Sanchez", 70));
    myPersonsTree.addNode(Person("Laura", "Rodriguez", 80));

    list<Person> myPersonsList = myPersonsTree.preOrder();

    for (auto it = myPersonsList.begin(); it != myPersonsList.end(); it++)
    {
        cout << *it << " ";
    }
    BinaryNode<int>* nodoAux;
    nodoAux = myTree.getRootNode();
    int altura = myTree.alturaNodo(nodoAux);

    cout<<"\n"<<altura<<endl;

    myList = myTree.preOrder();

    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}