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
    current = iterator.current; 
    return *this;
}

template<typename T>
bool ForwardIterator<T>::operator!=(ForwardIterator<T> iterator){
    return current != iterator.current;
}

template<typename T>
ForwardIterator<T> ForwardIterator<T>::operator++(){
    if(current->next == nullptr){
        cerr << "There isn't next\n";
        throw new out_of_range("no next");
    }
    current = current->next;
    return *this;
}

template<typename T>
T ForwardIterator<T>::operator*(){
    return current->data;
}

#endif
