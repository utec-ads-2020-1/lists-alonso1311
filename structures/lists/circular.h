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
        //void clear();
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
        new_node->prev = this->tail;
        this->head->prev = new_node;
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
        new_node->prev = this->tail;
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
        this->clear();
    } else {
        auto temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->head->prev = this->tail;

        this->tail->next = this->head;
        this->nodes--;
    }
}

template<typename T>
void CircularLinkedList<T>::pop_back(){
    if(this->empty()){
        this->show_error(__func__, name());
    } else if(this->nodes == 1){
        this->clear();
    } else {
        auto temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = temp->next;

        delete temp;
        this->nodes--;
    }

}

template<typename T>
T CircularLinkedList<T>::operator[](int index){
    if(this->empty()){
        this->show_error(__func__, name());
    } else if(index < 0){
        cerr << "Index can't be negative\n";
        throw new out_of_range("invalid index");
    }

    auto temp = this->head;
    int i = 0;

    while(i != index){
        temp = temp->next;
        ++i;
    }

    return temp->data;
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
        CircularLinkedList<T> temp;
        auto left_temp = this->tail;

        do{
            temp.push_back(left_temp->data);
            left_temp = left_temp->prev;
        } while(left_temp != this->head);
        temp.push_back(this->head->data);

        this->clear();
        merge(temp);
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
    if(this->empty() && new_CircularLinkedList.empty()){
        cerr << "Can't merge because both " + name() + " are empty\n";
        throw new out_of_range("empty");
    } else {
        auto new_temp = new_CircularLinkedList.head;

        for(int i = 0; i < new_CircularLinkedList.nodes; ++i){
            push_back(new_temp->data);
            new_temp = new_temp->next;
        }

        new_CircularLinkedList.clear();
    }
}

#endif
