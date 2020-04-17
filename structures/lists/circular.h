#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList();

        //T front();
        //T back();
        void push_front(T) override;
        void push_back(T) override;
        void pop_front() override;
        void pop_back() override;
        T operator[](int) override;
        //bool empty();
        //int size();
        void clear() override;
        void sort() override;
        void reverse() override;

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() override;

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
void CircularLinkedList<T>::push_front(T item){
    auto new_node = new Node<T>(item);

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
    } else {
        new_node->next = this->head;
        this->head = new_node;
    }

    this->tail->next = this->head;
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::push_back(T item){
    auto new_node = new Node<T>(item);

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    
    this->tail->next = this->head;
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::pop_front(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else if(this->nodes == 1){
        clear();
    } else {
        auto temp = this->head;
        this->head = this->head->next;
        delete temp;

        this->tail->next = this->head;
        this->nodes--;
    }
}

template<typename T>
void CircularLinkedList<T>::pop_back(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else if(this->nodes == 1){
        clear();
    } else {
        auto temp = this->head;
        while(temp->next != this->tail){
            temp = temp->next;
        }

        temp->next = this->tail->next;
        delete this->tail;
        this->tail =  temp;

        this->tail->next = this->head;
        this->nodes--;
    }

}

template<typename T>
T CircularLinkedList<T>::operator[](int index){
    auto temp = this->head;
    int i = 0;

    while(i != index){
        temp = temp->next;
        ++i;
    }

    return temp->data;
}

template<typename T>
void CircularLinkedList<T>::clear(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else {
        this->tail->next = nullptr;
        this->head->killSelf();
        this->initialize_constructor();
    }
}

template<typename T>
void CircularLinkedList<T>::sort(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else {
        auto temp = this->head;
        T max;
    
        for(int i = 0; i < this->nodes; ++i){
            while(temp->next != this->head){
                if(temp->data > temp->next->data){
                    max = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = max;
                }
                temp = temp->next;
            }
            temp = this->head;
        }
    }
}

template<typename T>
void CircularLinkedList<T>::reverse(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else {
        auto temp = this->head;
        Node<T>* temp_next = nullptr, * temp_prev = nullptr;

        do{
            temp_next = temp->next;
            temp->next = temp_prev;
            temp_prev = temp;
            temp = temp_next;
        } while(temp != this->head);

        this->tail = this->head;
        this->head = temp_prev;
        this->tail->next = this->head;
    }
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
