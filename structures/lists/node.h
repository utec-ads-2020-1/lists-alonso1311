#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf();
};

template<typename T>
void Node<T>::killSelf(){

}

#endif
