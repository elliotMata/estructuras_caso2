#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
    virtual void enqueue(T *pValue) = 0;
    virtual T *dequeue() = 0;
    virtual T *front() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

#endif