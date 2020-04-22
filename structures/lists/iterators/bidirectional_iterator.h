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
    current = iterator.current;
    return *this;
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> iterator){
    return current != iterator.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++(){
    if(current == nullptr){ //-Current se compara con null debido a que hay end()
        cerr << "There isn't next\n";
        throw new out_of_range("no next");
    }
    current = current->next;
    return *this;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--(){
    if(current == nullptr){ //-Current se compara con null debido a que en iteradores hay rend()
        cerr << "There isn't prev\n";
        throw new out_of_range("no prev");
    }
    current = current->prev;
    return *this;
}

template<typename T>
T BidirectionalIterator<T>::operator*(){
    return current->data;
}


#endif
