#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
    virtual void push(T *pValue) = 0;
    virtual T *pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

#endif