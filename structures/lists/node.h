#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node();
    Node(T);

    void killSelf();
};

template<typename T>
Node<T>::Node(){
    next = nullptr;
    prev = nullptr;
}

template<typename T>
Node<T>::Node(T _data) : data{_data} {
    next = nullptr;
    prev = nullptr;
}

template<typename T>
void Node<T>::killSelf(){
    if(next){
        next->killSelf();
    }
    delete this;
}

#endif
