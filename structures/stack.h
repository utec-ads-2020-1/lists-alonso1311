#ifndef STACK_H
#define STACK_H

#include<iostream>

using namespace std;

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
    data[top] = item;       
    top++;
}

template<typename T>
void stack<T>::pop(){
    
}

template<typename T>
T stack<T>::peak(){

}

//---------------------------------------------------
template<typename T>
int stack<T>::size(){
    return top;
}

template<typename T>
bool stack<T>::empty(){

}

#endif
