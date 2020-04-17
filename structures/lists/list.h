#ifndef LIST_H
#define LIST_H

#include "node.h"
#include<cassert>

// TODO: Implement all methods
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        //-Extra Functions
        void initialize(Node<T>*&, Node<T>*&, Node<T>*);

    public:
        List();
        ~List();

        T front();
        T back();
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;
        bool empty();
        int size();
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        //-Extra Functions
        void print();
};

//---------------------EXTRA FUNCTIONS-------------------------------------------
template<typename T>
void List<T>::initialize(Node<T>*& head, Node<T>*& tail, Node<T>* temp){
    head = temp;
    tail = head;
}

//-------------------------------------------------------------------------------
template<typename T>
List<T>::List(){
    this->head = nullptr;
    this->tail = nullptr;
    this->nodes = 0;
};

template<typename T>
List<T>::~List(){
    delete head;
    delete tail;
}

template<typename T>
T List<T>::front(){
    return head->data;
}

template<typename T>
T List<T>::back(){
    return tail->data;
}

template<typename T>
bool List<T>::empty(){
    return head == nullptr;
}

template<typename T>
int List<T>::size(){
    return nodes;
}

//---------------------EXTRA FUNCTIONS-------------------------------------------
template<typename T>
void List<T>::print(){
    auto temp = head;
    for(int i = 0; i < nodes; ++i){
        cout << temp->data << " -> "; 
        temp = temp->next;
    }
    cout << endl;
}

#endif
