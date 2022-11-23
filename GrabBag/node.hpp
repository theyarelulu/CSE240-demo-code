#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    public:
        T* data;
        Node<T>* next;

        // default constructor
        Node();

        // overloaded constructor with default value for next
        // makes the next parameter optional 
        //      -> functionally similar to Node(T data)
        Node(T data, Node<T>* next = NULL);
        
        // Node(T data, Node<T>* next);
};

template <typename T>
Node<T>::Node()
{
    // we cannot guarantee the type of data type that may be passed into our node
    // to be on the safer side, we just assign the data a piece of memory of the
    // size of the data type and static cast it to T*
    this->data = (T*)malloc(sizeof(T));
    this->next = NULL;
}

template <typename T>
Node<T>::Node(T data, Node<T>* next)
{
    this->data = (T*)malloc(sizeof(T));
    *(this->data) = data;
    this->next = next;
}

// ***************************
// we actually don't need to explictly define Node(T data)
// we can use Node(T data, Node<T>* next = NULL) with a default
// value. it's a handy dandy way of overloading things

// template <typename T>
// Node<T>::Node(T data)
// {
//     this->data = (T*)malloc(sizeof(T));
//     *(this->data) = data;

//     // next is null by default
//     this->next = NULL;
// }

// **************************

#endif