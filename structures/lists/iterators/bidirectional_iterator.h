#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator();
        BidirectionalIterator(Node<T>*);

        BidirectionalIterator<T> operator=(BidirectionalIterator<T>);

        bool operator!=(BidirectionalIterator<T>);

        BidirectionalIterator<T> operator++();

        BidirectionalIterator<T> operator--();

        T operator*();
};

template<typename T>
BidirectionalIterator<T>::BidirectionalIterator(){
    this->current = nullptr;
}

template<typename T>
BidirectionalIterator<T>::BidirectionalIterator(Node<T>* current_){
    this->current = current_;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator=(BidirectionalIterator<T> iterator){
    iterator.current = current;
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> iterator){
    return current != iterator.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++(){
    current = current->next;
    return 0;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--(){
    current = current->prev;
    return 0;
}

template<typename T>
T BidirectionalIterator<T>::operator*(){
    return current->data;
}


#endif
