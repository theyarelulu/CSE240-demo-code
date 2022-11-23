#include <iostream>
#include "grab-bag.hpp"
#include "node.hpp"


using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    // testing the constructor overloads for Node
    Node<int>* n1 = new Node<int>();
    *(n1->data) = 10;
    printf("n1: Constructor: Node() -> data = %d\n", *(n1->data));
    delete n1;

    Node<int>* n2 = new Node<int>(10);
    printf("n2: Constructor: Node(T data = 10, Node<T>* next = NULL) -> data = %d\n", *(n2->data));

    Node<int>* n3 = new Node<int>(12, n2);
    printf("n3: Constructor: Node(T data = 10, Node<T>* next = n2) -> data = %d, next->data = %d\n\n", *(n3->data), *(n3->next->data));

    printf("-------------------------------------------------\n\n");

    // create a new grab bag
    GrabBag<int>* gb = new GrabBag<int>();

    // insert values into grab bag
    for (int i = 0; i < 10; i++)
    {
        gb->push(i);
    }

    // try popping from the grab bag 15 times
    // Notice: we inserted only 10 elements!!!
    //         This a good way to stress test your data structures
    for(int i = 0; i < 15; i++)
    {
        Node<int>* popped = gb->popNode();
        if (popped != NULL)
            printf("Popped Node %d: %d\n\n", i, *(popped->data));
        else
            printf("Grab Bag empty!!\n\n");

        // the onus of deletion falls on the main!!
        delete popped;
    }

    printf("-------------------------------------------------\n\n");
    // now let's try doing the same thing, except we get the data structure to
    // return the data itself. we will rely on the data structure deleting 
    // unnecessary nodes.

    // push 10 values
    for (int i = 10; i < 20; i++)
    {
        gb->push(i);
    }

    // try popping 15 pieces of data
    for(int i = 0; i < 15; i++)
    {
        int* popped = gb->popData();
        if (popped != NULL)
            printf("Popped Data %d: %d\n\n", i, *popped);
        else
            printf("Grab Bag empty!!\n\n");
    }

    return 0;
}