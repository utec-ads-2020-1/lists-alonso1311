#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    private:
        Node<T>* sentinel_end;
        Node<T>* sentinel_rend;

        //----------------EXTRA FUNCTIONS---------------------
        void initialize_sentinels();
    public:
        LinkedList();
        ~LinkedList();

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

        BidirectionalIterator<T> rbegin();
	    BidirectionalIterator<T> rend();

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

//-----------------------EXTRA FUNCTIONS--------------------------------
template<typename T>
void LinkedList<T>::initialize_sentinels(){
    sentinel_end->prev = this->tail;
    sentinel_rend->next = this->head;
}

//----------------------------------------------------------------------
template<typename T>
LinkedList<T>::LinkedList() : List<T>(){
    sentinel_end = new Node<T>();
    sentinel_rend = new Node<T>();
}

template<typename T>
LinkedList<T>::~LinkedList(){
    delete sentinel_end;
    delete sentinel_rend;
}

template<typename T>
void LinkedList<T>::push_front(T item){
    auto new_node = new Node<T>(item);
    new_node->prev = sentinel_rend;

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
        new_node->next = sentinel_end;
    } else {
        new_node->next = this->head;
        this->head->prev = new_node;
        this->head = new_node;
    }
    
    initialize_sentinels();
    this->nodes++;
}

template<typename T>
void LinkedList<T>::push_back(T item){
    auto new_node = new Node<T>(item);
    new_node->next = sentinel_end;

    if(this->empty()){
        this->initialize(this->head, this->tail, new_node);
        new_node->prev = sentinel_rend;
    } else {
        this->tail->next = new_node; 
        new_node->prev = this->tail;
        this->tail = new_node;
    }

    initialize_sentinels();
    this->nodes++;
}

template<typename T>
void LinkedList<T>::pop_front(){
    if(this->nodes == 1){
        this->clear();
    } else if(!this->empty()) {
        auto temp = this->head;
        this->head = this->head->next;
        this->head->prev = temp->prev;
            
        delete temp;
        initialize_sentinels();
        this->nodes--;
    }
}

template<typename T>
void LinkedList<T>::pop_back(){
    if(this->nodes == 1){
        this->clear();
    } else if(!this->empty()) {
        auto temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = temp->next;

        delete temp;
        initialize_sentinels();
        this->nodes--;
    }
}

template<typename T>
T LinkedList<T>::operator[](int index){
    if(index >= this->nodes || index < 0){
        cerr << "Index is out of range or " + name() + " is empty\n";
        throw new out_of_range("invalid index");
    }

    Node<T>* temp;
    int i;
    
    if(index <= this->nodes/2){
        temp = this->head; 
        i = 0;
        
        while(i != index){
            temp = temp->next;
            ++i;
        }
    } else {
        temp = this->tail;
        i = this->nodes-1;
        while(i != index){
            temp = temp->prev;
            --i;
        }
    }
    return temp->data;
}

template<typename T>
void LinkedList<T>::sort(){
    if(!this->empty()){
        auto temp = this->head;
        T max;

        for(int i = 0; i < this->nodes; ++i){
            while(temp->next != sentinel_end){
                if(temp->data > temp->next->data){
                    max = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = max;
                }
                temp = temp->next;
            }
            temp = this->head;
        }
        initialize_sentinels();
    }
}

template<typename T>
void LinkedList<T>::reverse(){
    if(!this->empty()){
        /*
        LinkedList<T> temp;
        auto left_temp = this->tail; 

        do {
            temp.push_back(left_temp->data);
            left_temp = left_temp->prev;
        } while(left_temp != nullptr);

        this->clear();
        merge(temp);
        */
        auto temp = this->head;
        Node<T>* temp_next = sentinel_rend, * temp_prev = sentinel_rend;

        do {
            temp_next = temp->next;
            temp->next = temp_prev;
            temp_prev = temp;
            temp = temp_next;
        } while(temp != sentinel_end);

        this->tail = this->head;
        this->head = temp_prev;
        initialize_sentinels();
    }
}

//-------------------------------------------------------------
template<typename T>
BidirectionalIterator<T> LinkedList<T>::begin(){
    if(this->empty()){
        this->show_error(__func__, name());
    } 
    BidirectionalIterator<T> iterator(this->head);
    return iterator;
}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::end(){
    if(this->empty()){
        this->show_error(__func__, name());
    } 
    BidirectionalIterator<T> iterator(sentinel_end);
    return iterator;
}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::rbegin(){
    if(this->empty()){
        this->show_error(__func__, name());
    } 
    BidirectionalIterator<T> iterator(this->tail);
    return iterator;
}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::rend(){
    if(this->empty()){
        this->show_error(__func__, name());
    } 
    BidirectionalIterator<T> iterator(sentinel_rend);
    return iterator;
}

//-------------------------------------------------------------
template<typename T>
string LinkedList<T>::name(){
    return "Linked List";
}

//-------------------------------------------------------------
template<typename T>
void LinkedList<T>::merge(LinkedList<T>& new_LinkedList){
    if(this->empty() && new_LinkedList.empty()){
        cerr << "Can't merge because both " + name() + " are empty\n";
        throw new out_of_range("empty");
    } else {
        auto new_temp = new_LinkedList.head;

        for(int i = 0; i < new_LinkedList.nodes; ++i){
            push_back(new_temp->data);     
            new_temp = new_temp->next;
        }

        new_LinkedList.clear();
    }
}

#endif
