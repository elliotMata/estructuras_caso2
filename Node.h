#ifndef NODE_H
#define NODE_H

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
        previous = NULL;
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

    Node *getPrevious()
    {
        return previous;
    }

    void setNext(Node *pValue)
    {
        this->next = pValue;
    }

    void setPrevious(Node *pValue)
    {
        this->previous = pValue;
    }
};

#endif