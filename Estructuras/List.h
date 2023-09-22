#ifndef LIST_H
#define LIST_H

#include "Queue.h"
#include "Stack.h"
#include "Node.h"

template <typename T>
class List : public Queue<T>, public Stack<T>
{
private:
    Node<T> *first;
    Node<T> *last;
    int size;

public:
    List();
    ~List();
    int getSize();
    Node *getFirst();
    void setFirst(Node *pFirst);
    Node *getLast();
    void setLast(Node *pLast);
    bool isEmpty();
    T *find(int position);
    void add(T *pData);
    void insert(int position, T *pData);
    T *remove(int position);
    void push(T *pNode);
    T *pop();
    void enqueue(T *pNode);
    T *dequeue();
};

#endif