#pragma once
#include "Node.h"
template<typename G>
class Queue
{
private:
    int MaxSize;
    int Size;
    Node<G>* Top;
    Node<G>* Bot;
    int Start;
    int End;
    Node<G>** Ring;
public:
    Queue<G>& operator= (const Queue<G>&);
    Queue<G>& operator= (Queue<G>&&);
    G& operator[] (int);
    Queue<G>& operator+= (const Queue<G>&);
    Queue(int);
    Queue(Queue<G>&&);
    Queue(const Queue<G>&);
    int GetSize();
    void Push(G);
    G Pop();
    void Print();
    ~Queue();
};
template<typename G>
Queue<G> operator+ (const Queue<G>&, const Queue<G>&);
