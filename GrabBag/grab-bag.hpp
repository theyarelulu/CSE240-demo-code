#pragma once
#ifndef GRAB_BAG_H
#define GRAB_BAG_H
#include "node.hpp"

template <typename T>
class GrabBag
{
    public:
        Node<T>* head;
        int size;
        GrabBag();
        void push(T data);
        Node<T>* popNode();
        T* popData();
};

template <typename T>
GrabBag<T>::GrabBag()
{
    // set head to null and size to 0 by default
    this->head = NULL;
    this->size = 0;
}

// this method pushes a node to the head of the grab bag
template <typename T>
void GrabBag<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data, this->head);
    this->head = newNode;
    size++;
}

// this method pops a node and returns a pointer to the node
// Deletion of this node is now the responsibility of whoever receives the node
//      in this case: our main function
template <typename T>
Node<T>* GrabBag<T>::popNode()
{
    if (size == 0 || this->head == NULL)
    {
        return NULL;
    }

    int indexToRemove = (int)(size / 2);

    if (indexToRemove == 0)
    {
        Node<T>* returnNode = this->head;
        this->head = NULL;
        size--;
        return returnNode;
    }

    Node<T>* temp = this->head;
    for(int i = 0; i < indexToRemove-1; i++)
    {
        temp = temp->next;
    }
    Node<T>* returnNode = temp->next;
    temp->next = temp->next->next;
    size--;
    return returnNode;

}

// this method pops a node and returns a pointer to the data it holds
template <typename T>
T* GrabBag<T>::popData()
{
    if (size == 0 || this->head == NULL)
    {
        return NULL;
    }

    int indexToRemove = (int)(size / 2);

    if (indexToRemove == 0)
    {
        Node<T>* returnNode = this->head;
        this->head = NULL;
        
        T* data = returnNode->data;
        delete returnNode;

        size--;
        
        return data;
    }

    Node<T>* temp = this->head;
    for(int i = 0; i < indexToRemove-1; i++)
    {
        temp = temp->next;
    }

    Node<T>* returnNode = temp->next;
    temp->next = temp->next->next;

    T* data = returnNode->data;
    delete returnNode;

    size--;
    return data;

}

#endif 