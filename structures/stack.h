#ifndef STACK_H
#define STACK_H

#include<iostream>

using namespace std;

#define MAX 1000
#define RESIZE 10  

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;
    int to_resize;

	//-Extra functions
    void resize();

public:
	stack(int size = MAX);
	~stack();   		

	void push(T);
	void pop();
	T peak();

	int size();
	bool empty();

    //-Extra functions
    void print();
};

//--------------EXTRA FUNCTIONS------------------------
template<typename T>
void stack<T>::resize(){
    capacity += to_resize;
    T* temp_data = new T[capacity];

    for(int i = 0; i < top; ++i)
        temp_data[i] = data[i];

    delete[] data;
    data = temp_data;
    to_resize *= 2;
}

//---------------------------------------------------
template<typename T>
stack<T>::stack(int size){
    capacity = size;
    top = 0;
    data = new T[capacity];
    to_resize = RESIZE;
}

template<typename T>
stack<T>::~stack(){
    delete[] data;
}

//-----------------------------------------------
template<typename T>
void stack<T>::push(T item){
    if(top == capacity)
        resize();
    
    data[top] = item;       
    top++;
}

template<typename T>
void stack<T>::pop(){
    if(empty()){
        cerr << "Can't pop because stack is empty\n";
        throw new out_of_range("empty");
    } else {
        data[top-1] = data [top];
        top--; 
    }
}

template<typename T>
T stack<T>::peak(){
    if(empty()){
        cerr << "Can't peak because stack is empty\n";
        throw new out_of_range("empty");
    }

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
void stack<T>::print(){
    if(empty()){
        cerr << "Can't print because stack is empty\n";
        throw new out_of_range("empty");
    } else {
        for(int i = top-1; i >= 0; --i)
            cout << data[i] << endl;
    }
}

#endif
