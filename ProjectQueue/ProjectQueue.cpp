#include <iostream>
#include "Queue.h"
using namespace std;

Queue<int> create_queue()
{
    Queue<int> Q(10);
    Q.Push(1);
    Q.Push(3);
    Q.Push(4);
    Q.Push(5);
    return Q;
}
//Queue create_new_queue(Queue** pointer)
//{
//    Queue* Q = new Queue(10);
//    Q->Push(8);
//    *pointer = Q;
//    return *Q;
//}

int main()
{
    try
    {
        Queue<int> QI(3);
        QI.Push(2);
        QI.Print();

        Queue<double> QD(3);
        QD.Push(2.5);
        QD.Print();
        cout << QD[1];
    }
    catch (exception& ex)
    {
        cout << ex.what();
    }
    //Queue* P;
    //Queue Q4(create_new_queue(&P));
    //delete P;
    //cout << Q4.Pop();
}