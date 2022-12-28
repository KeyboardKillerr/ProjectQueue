#include "Node.h"

template class Node<int>;
template class Node<double>;

template<typename G>
Node<G>::Node(G value)
{
    Value = value;
}

template<typename G>
Node<G>::Node() {}

template<typename G>
Node<G>::~Node() { }