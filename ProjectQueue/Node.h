#pragma once
template<typename G>
class Node
{
public:
    G Value;
    Node<G>* Prev;
    Node(G);
    Node();
    ~Node();
};