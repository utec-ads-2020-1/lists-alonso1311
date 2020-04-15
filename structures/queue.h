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
	int pop();
	int front();
    int back();

	int size();
	bool empty();
};

template<typename T>
queue<T>::queue(int size){
    cout << size << endl;
}

#endif
