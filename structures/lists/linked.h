#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList();

        T front() override;
        T back() override;
        void push_front(T) override;
        void push_back(T) override;
        void pop_front() override;
        void pop_back() override;
        T operator[](int) override;
        bool empty() override;
        int size() override;
        void clear() override;
        void sort() override;
        void reverse() override;

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
        void merge(LinkedList<T>&);
};

template<typename T>
LinkedList<T>::LinkedList() : List<T>(){}

template<typename T>
T LinkedList<T>::front(){
    return (empty() == true) ? this->nodes : this->nodes-1;
}

template<typename T>
T LinkedList<T>::back(){
    return (empty() == true) ? this->nodes : this->nodes-1;
}

template<typename T>
void LinkedList<T>::push_front(T item){

}

template<typename T>
void LinkedList<T>::push_back(T item){

}

template<typename T>
void LinkedList<T>::pop_front(){

}

template<typename T>
void LinkedList<T>::pop_back(){

}

template<typename T>
T LinkedList<T>::operator[](int index){

}

template<typename T>
bool LinkedList<T>::empty(){
    return (this->head == nullptr) ? true : false;
}

template<typename T>
int LinkedList<T>::size(){
    return this->nodes;
}

template<typename T>
void LinkedList<T>::clear(){

}

template<typename T>
void LinkedList<T>::sort(){

}

template<typename T>
void LinkedList<T>::reverse(){

}

//-------------------------------------------------------------
template<typename T>
BidirectionalIterator<T> LinkedList<T>::begin(){

}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::end(){

}

//-------------------------------------------------------------
template<typename T>
string LinkedList<T>::name(){
    return "Linked List";
}

//-------------------------------------------------------------
template<typename T>
void LinkedList<T>::merge(LinkedList<T>& new_LinkedList){

}

#endif
