#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

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
};

//--------------------------------------------------------------------
template<typename T>
queue<T>::queue(int size){
    cout << size << endl;
}

template<typename T>
queue<T>::~queue(){
    
}

//--------------------------------------------------------------------
template<typename T>
void queue<T>::push(T item){

}
template<typename T>
void queue<T>::pop(){

}

template<typename T>
T queue<T>::front(){

}

template<typename T>
T queue<T>::back(){

}

//--------------------------------------------------------------------
template<typename T>
int queue<T>::size(){

}

template<typename T>
bool queue<T>::empty(){

}

#endif
