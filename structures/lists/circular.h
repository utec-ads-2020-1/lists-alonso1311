#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList();

        T front();
        T back();
        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        T operator[](int);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name();

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(CircularLinkedList<T>&);
};

template<typename T>
CircularLinkedList<T>::CircularLinkedList() : List<T>(){}

template<typename T>
T CircularLinkedList<T>::front(){
    return (empty() == true) ? this->nodes : this->nodes-1;
}

template<typename T>
T CircularLinkedList<T>::back(){
    return (empty() == true) ? this->nodes : this->nodes-1;
}

template<typename T>
void CircularLinkedList<T>::push_front(T item){

}

template<typename T>
void CircularLinkedList<T>::push_back(T item){

}

template<typename T>
void CircularLinkedList<T>::pop_front(){

}

template<typename T>
void CircularLinkedList<T>::pop_back(){

}

template<typename T>
T CircularLinkedList<T>::operator[](int index){

}

template<typename T>
bool CircularLinkedList<T>::empty(){
    return (this->head == nullptr) ? true : false;
}

template<typename T>
int CircularLinkedList<T>::size(){
    return this->nodes;
}

template<typename T>
void CircularLinkedList<T>::clear(){

}

template<typename T>
void CircularLinkedList<T>::sort(){

}

template<typename T>
void CircularLinkedList<T>::reverse(){

}

//-------------------------------------------------------------
template<typename T>
BidirectionalIterator<T> CircularLinkedList<T>::begin(){

}

template<typename T>
BidirectionalIterator<T> CircularLinkedList<T>::end(){

}

//-------------------------------------------------------------
template<typename T>
string CircularLinkedList<T>::name(){
    return "Circular List";
}

//-------------------------------------------------------------
template<typename T>
void CircularLinkedList<T>::merge(CircularLinkedList<T>& new_CircularLinkedList){

}

#endif
