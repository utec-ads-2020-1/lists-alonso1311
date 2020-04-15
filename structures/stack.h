#ifndef STACK_H
#define STACK_H

#include"header.h"

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;

public:
	stack(int size = MAX);
	~stack();   		

	void push(T);
	void pop();
	T peak();

	int size();
	bool empty();

    //-Extra functions
    void reserve();
    void print();
};

//---------------------------------------------------
template<typename T>
stack<T>::stack(int size){
    capacity = size;
    top = 0;
    data = new T[capacity];
}

template<typename T>
stack<T>::~stack(){
    delete[] data;
}

//-----------------------------------------------
template<typename T>
void stack<T>::push(T item){
    if(top == capacity)
        reserve();
    
    data[top] = item;       
    top++;
}

template<typename T>
void stack<T>::pop(){
    if(empty() == true)
        cerr << "The stack is empty\n";
    else {
        data[top] = data [top+1];
        top--; 
    }
}

template<typename T>
T stack<T>::peak(){
    return data[top-1];
}

//---------------------------------------------------
template<typename T>
int stack<T>::size(){
    return top;
}

template<typename T>
bool stack<T>::empty(){
    if(top == 0)
        return true;

    return false;
}

//--------------EXTRA FUNCTIONS------------------------
template<typename T>
void stack<T>::reserve(){
    capacity += MAX;
    T* temp_data = new T[capacity];
    for(int i = 0; i < top; ++i)
        temp_data[i] = data[i];

    delete[] data;
    data = temp_data;
}

template<typename T>
void stack<T>::print(){
    for(int i = top-1; i >= 0; --i)
        cout << data[i] << endl;
}

#endif
