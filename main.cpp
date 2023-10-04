#include <iostream>
#include "binary_tree/BinaryTree.hpp"

int main()
{
    int opcion, dato;
    BinaryTree<int> arbol = BinaryTree<int>();

    do{
        cout << "ARBOL BINARIO AVL\n";
        cout << "1. Ingresar un dato\n";
        cout << "2. Mostrar arbol con preorden\n";
        cout << "3. Mostrar arbol con inorden\n";
        cout << "4. Mostrar arbol con posorden\n";
        cout << "5. Eliminar un dato\n";
        cout << "6. Altura del arbol\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: "; cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                cout << "Ingrese el numero que quiera insertar al arbol: ";
                cin >> dato;
                arbol.addNode(dato);
                system("pause");
                break;
            case 2:{
                cout << "PREORDEN\n";
                list<int> myList = arbol.preOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 3:{
                cout << "INORDEN\n";
                list<int> myList = arbol.inOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 4:{
                cout << "POSORDEN\n";
                list<int> myList = arbol.postOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 5: 
                cout << "Ingrese el numero que quiera eliminar al arbol: ";
                cin >> dato;
                arbol.deleteNode(dato);
                break;
            case 6:{
                BinaryNode<int>* nodoAux = arbol.getRootNode(); //Se le pide la raiz del arbol
                int altura = arbol.alturaNodo(nodoAux); //Se pasa por parametro para saber la altura
                cout << "La altura del arbol es: " << altura << endl;
                system("pause");
                break;
            }
            case 7:
                cout << "Muchas gracias por usar el sistema :)\n";
                system("pause");
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 7);

    return 0;
}