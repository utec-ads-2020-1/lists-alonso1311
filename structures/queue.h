#ifndef QUEUE_H
#define QUEUE_H

#include"header.h"

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	int top;
	int capacity;

public:
	queue(int size = MAX);
	~queue();   		

	void push(T);
	void pop();
	T front();
    T back();

	int size();
	bool empty();

    //-Extra functions
    void reserve();
    void print();
};

//--------------------------------------------------------------------
template<typename T>
queue<T>::queue(int size){
    capacity = size;
    top = 0;
    data = new T[capacity];
}

template<typename T>
queue<T>::~queue(){
    delete[] data; 
}

//--------------------------------------------------------------------
template<typename T>
void queue<T>::push(T item){
    if(top == capacity)
        reserve();

    data[top] = item;
    top++;
}
template<typename T>
void queue<T>::pop(){
    if(empty() == true)
        cerr << "The queue is empty\n";
    else{
        for(int i = 0; i < top; ++i)
            data[i] = data[i+1];

        top--;
    }
}

template<typename T>
T queue<T>::front(){
    return data[0];
}

template<typename T>
T queue<T>::back(){
    return data[top-1];
}

//--------------------------------------------------------------------
template<typename T>
int queue<T>::size(){
    return top;
}

template<typename T>
bool queue<T>::empty(){
    return (top == 0) ? true : false;
}

//----------------EXTRA FUNCTIONS------------------------------------
template<typename T>
void queue<T>::reserve(){
    capacity += MAX;
    T* temp_data = new T[capacity];

    for(int i = 0; i < top; ++i)
        temp_data[i] = data[i];

    delete[] data;
    data = temp_data;
}

template<typename T>
void queue<T>::print(){
    for(int i = 0; i < top; ++i)
        cout << data[i] << endl;
}

#endif
