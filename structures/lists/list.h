#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        //-Extra Functions
        void initialize_constructor();
        void initialize(Node<T>*&, Node<T>*&, Node<T>*);
        void show_error(string, string);

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
        void clear();
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        //-Extra Functions
        void print();
};

//---------------------EXTRA FUNCTIONS-------------------------------------------
template<typename T>
void List<T>::initialize_constructor(){
    this->head = nullptr;
    this->tail = nullptr;
    this->nodes = 0;
}

template<typename T>
void List<T>::initialize(Node<T>*& head, Node<T>*& tail, Node<T>* temp){
    head = temp;
    tail = head;
}

template<typename T>
void List<T>::show_error(string function_name, string name_list){
    string error = "Can't " + function_name + " because " + name_list + " is empty";
    cerr << error << endl;
    throw new out_of_range("error"); 
}

//-------------------------------------------------------------------------------
template<typename T>
List<T>::List(){
    initialize_constructor(); 
};

template<typename T>
List<T>::~List(){
    /*
    //Prueba 1
    tail->next = nullptr;
    auto temp = head;
    while(temp->next != nullptr){
        auto  to_delete = temp;
        temp = temp->next;
        delete to_delete;
    }
    */
    
    //Prueba 2
    tail->next = nullptr;
    head->killSelf();
    
    /*
    delete head;
    delete tail;
    */
}

template<typename T>
T List<T>::front(){
    if(empty()){
        show_error(__func__, name());
    } 
    return head->data;
}

template<typename T>
T List<T>::back(){
    if(empty()){
        show_error(__func__, name());
    }
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

template<typename T>
void List<T>::clear(){
    if(!empty()){
        tail->next = nullptr;
        head->killSelf();
        initialize_constructor();
    }
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
