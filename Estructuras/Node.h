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
    Node(T *pData = nullptr) : data(pData) {}
    T *getData();
    void setData(T *pData);
    Node *getNext();
    void setNext(Node *pNext);
    Node getPrev();
    void setPrev(Node *pPrev);
};

#endif