#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList();

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

        ForwardIterator<T> begin();
	    ForwardIterator<T> end();

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
        void merge(ForwardList<T>&);
};

template<typename T>
ForwardList<T>::ForwardList() : List<T>(){}

template<typename T>
void ForwardList<T>::push_front(T item){
    auto new_node = new Node<T>(item);

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
    } else {
        new_node->next = this->head;
        this->head = new_node;
    }

    this->nodes++;
}

template<typename T>
void ForwardList<T>::push_back(T item){
    auto new_node = new Node<T>(item);

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }

    this->nodes++;
}

template<typename T>
void ForwardList<T>::pop_front(){
    if(this->empty()){
        cerr << name() + " is empty\n";
    } else {
        auto temp = this->head; 
        this->head = this->head->next;
        delete temp;

        if(this->nodes == 1){
            this->tail = this->head;
        }
        
        this->nodes--;
    }
}

template<typename T>
void ForwardList<T>::pop_back(){
    if(this->empty()){
        cerr << name() + " is empty\n";
    } else {
        auto temp = this->head; 
        if(this->nodes > 1){
            while(temp->next != this->tail){
                temp = temp->next;
            }
        }
         
        temp->next = this->tail->next;
        delete this->tail;

        if(this->nodes == 1){
            this->initialize(this->head, this->tail, temp);
        } else {
            this->tail = temp;
        }

        this->nodes--;
    }
}

template<typename T>
T ForwardList<T>::operator[](int index){
    auto temp = this->head; 
    for(int i = 0; i < index; ++i){
        temp = temp->next;     
    }
    
    return temp->data;
}

template<typename T>
void ForwardList<T>::clear(){
    this->head->killSelf();
    this->head = nullptr;
    this->tail = nullptr;
    this->nodes = 0;
}

template<typename T>
void ForwardList<T>::sort(){
    auto temp = this->head;
    T max;

    for(int i = 0; i < this->nodes - 1; ++i){
        for(int j = i + 1; j < this->nodes; ++j){
            if(temp->data > temp->next->data){
                max = temp->data;
                temp->data = temp->next->data;
                temp->next->data = max;
                temp = temp->next;
            } else {
                temp = temp->next;
            }
        } 
        temp = this->head;
    }
}

template<typename T>
void ForwardList<T>::reverse(){
    auto temp = this->head;    
    Node<T>* temp_next = nullptr,* temp_prev = nullptr;

    while(temp != nullptr){
        temp_next = temp->next; 
        temp->next = temp_prev;
        temp_prev = temp;
        temp = temp_next;
    }

    this->tail = this->head;
    this->head = temp_prev;
}

//-------------------------------------------------------------
template<typename T>
ForwardIterator<T> ForwardList<T>::begin(){

}

template<typename T>
ForwardIterator<T> ForwardList<T>::end(){

}

//-------------------------------------------------------------
template<typename T>
string ForwardList<T>::name(){
    return "Forward List";
}

//-------------------------------------------------------------
template<typename T>
void ForwardList<T>::merge(ForwardList<T>& new_ForwardList){
    
}

#endif
