#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T *data;
    Node *prev;
    Node *next;

public:
    Node(T *pData)
    {
        this->data = pData;
        next = NULL;
        prev = NULL;
    }

    T *getData()
    {
        return data;
    }

    void setData(T *pData)
    {
        this->data = pData;
    }

    Node *getNext()
    {
        return next;
    }

    Node *getPrev()
    {
        return prev;
    }

    void setNext(Node *pValue)
    {
        this->next = pValue;
    }

    void setPrev(Node *pValue)
    {
        this->prev = pValue;
    }
};

#endif