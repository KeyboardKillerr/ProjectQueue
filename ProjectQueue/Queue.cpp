#include <iostream>
#include <exception>
#include "Queue.h"
using namespace std;

template class Queue<int>;
template class Queue<double>;

template<typename G>
Queue<G>::Queue(int MaxSize)
{
    this->MaxSize = MaxSize;
    Size = 0;
    Top = NULL;
    Bot = NULL;
    Start = 0;
    End = 0;
    Ring = new Node<G>*[MaxSize];
}
template<typename G>
Queue<G>::Queue(Queue<G>&& orig)
{
    cout << "move" << endl;
    MaxSize = orig.MaxSize;
    Size = orig.Size;
    Top = orig.Top;
    Bot = orig.Bot;
    Start = orig.Start;
    End = orig.End;
    Ring = orig.Ring;
    orig.Size = 0;
    orig.Top = NULL;
    orig.Bot = NULL;
    orig.Start = 0;
    orig.Bot = 0;
    //çàíóëèòü îðèã ìàññèâ
}
template<typename G>
Queue<G>::Queue(const Queue<G>& copy)
{
    cout << "copy" << endl;
    MaxSize = copy.MaxSize;
    Size = 0;
    Top = NULL;
    Bot = NULL;
    Start = 0;
    End = 0;
    if (copy.Top != NULL)
    {
        Node<G>* tmp = copy.Top;
        while (tmp != NULL)
        {
            Push(tmp->Value);
            tmp = tmp->Prev;
        }
    }
}
template<typename G>
G& Queue<G>:: operator[] (int index)
{
    if (index > this->MaxSize - 1 || index < 0 || index + 1 > Size) throw out_of_range("Wrong index");
    /*Node* tmp = Top;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->Prev;
    }*/
    if (Start + index > MaxSize - 1) index = Start + index - MaxSize;
    else index = Start + index;
    return Ring[index]->Value;
}
template<typename G>
Queue<G> operator+ (const Queue<G>& left, const Queue<G>& right)
{
    Queue<G> tmp(left);
    tmp += right;
    return tmp;
}
template<typename G>
Queue<G>& Queue<G>:: operator+= (const Queue<G>& element)
{
    if (Size < element.Size)
    {
        Size = element.Size;
    }
    Node<G>* ThisTmp = Top;
    Node<G>* ElementTmp = element.Top;
    for (int i = 0; i < element.Size; i++)
    {
        ThisTmp->Value += ElementTmp->Value;
        if (ThisTmp->Prev == NULL && i + 1 < element.Size) ThisTmp->Prev = new Node<G>(0);
        ThisTmp = ThisTmp->Prev;
        ElementTmp = ElementTmp->Prev;
    }
    return *this;
}
template<typename G>
Queue<G>& Queue<G>:: operator= (Queue<G>&& orig)
{
    if (this == &orig) return *this;
    cout << "operator move" << endl;
    cout << "move" << endl;
    MaxSize = orig.MaxSize;
    Size = orig.Size;
    Top = orig.Top;
    Bot = orig.Bot;
    Start = orig.Start;
    End = orig.End;
    Ring = orig.Ring;
    orig.Size = 0;
    orig.Top = NULL;
    orig.Bot = NULL;
    orig.Start = 0;
    orig.Bot = 0;
    delete orig.Ring;
    Ring = new Node<G>* [MaxSize];
    return *this;
}
template<typename G>
Queue<G>& Queue<G>:: operator= (const Queue<G>& copy)
{
    if (this == &copy) return *this;
    cout << "operator copy" << endl;
    cout << "copy" << endl;
    MaxSize = copy.MaxSize;
    Size = 0;
    Top = NULL;
    Bot = NULL;
    Start = 0;
    End = 0;
    if (copy.Top != NULL)
    {
        Node<G>* tmp = copy.Top;
        while (tmp != NULL)
        {
            Push(tmp->Value);
            tmp = tmp->Prev;
        }
    }
    return *this;
}
template<typename G>
int Queue<G>::GetSize()
{
    return this->Size;
}
template<typename G>
void Queue<G>::Push(G value)
{
    if (Size == MaxSize)
    {
        cout << "Queue full" << endl;
        return;
    }
    Node<G>* tmp = new Node<G>(value);
    if (Size == 0)
    {
        Top = tmp;
        Bot = tmp;
        Ring[End] = tmp;
        End++;
        if (End == MaxSize) End = 0;
    }
    else
    {
        Bot->Prev = tmp;
        Bot = tmp;
        Ring[End] = tmp;
        End++;
        if (End == MaxSize) End = 0;
    }
    Size++;
}
template<typename G>
G Queue<G>::Pop()
{
    if (Size == 0) return NULL;
    G value = Top->Value;
    Node<G>* tmp = Top->Prev;
    delete Top;
    Top = tmp;
    Size--;
    if (Start == MaxSize - 1) Start = 0;
    else Start++;
    return value;
}
template<typename G>
void Queue<G>::Print()
{
    Node<G>* tmp = Top;
    while (tmp != NULL)
    {
        cout << tmp->Value << " ";
        tmp = tmp->Prev;
    }
    cout << endl;
}
template<typename G>
Queue<G>::~Queue()
{
    while (Size != 0) Pop();
}
