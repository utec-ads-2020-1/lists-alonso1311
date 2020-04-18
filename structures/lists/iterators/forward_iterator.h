#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator();
        ForwardIterator(Node<T>*);

        ForwardIterator<T> operator=(ForwardIterator<T>);

        bool operator!=(ForwardIterator<T>);

        ForwardIterator<T> operator++();

        T operator*();
};

template<typename T>
ForwardIterator<T>::ForwardIterator(){
    this->current = nullptr;
}

template<typename T>
ForwardIterator<T>::ForwardIterator(Node<T>* current_){
    this->current = current_;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator=(ForwardIterator<T> iterator){
    iterator.current = current; 
}

template<typename T>
bool ForwardIterator<T>::operator!=(ForwardIterator<T> iterator){
    return current != iterator.current;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator++(){
    current = current->next;
    return 0;
}

template<typename T>
T ForwardIterator<T>::operator*(){
    return current->data;
}

#endif
