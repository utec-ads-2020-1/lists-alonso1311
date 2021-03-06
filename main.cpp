#include "test/tester.h"
//#include"structures/stack.h"
//#include"structures/queue.h"
//#include"structures/lists/linked.h"
//#include"structures/lists/forward.h"
#include"structures/lists/circular.h"

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
    
    /*    
    //-STACK test
    auto* stack1 = new stack<int>(3);
    stack1->push(3);
    stack1->push(13);
    stack1->push(10);
    stack1->print();
    cout << "Peak: " << stack1->peak() << endl;
    cout << "Size: " << stack1->size() << endl;
    cout << endl;
    stack1->pop();
    stack1->print();
    cout << "Peak: " << stack1->peak() << endl;
    cout << "Size: " << stack1->size() << endl;
    cout << endl;
    stack1->push(6);
    stack1->print();
    cout << "Peak: " << stack1->peak() << endl;
    cout << "Size: " << stack1->size() << endl;
    cout << endl;
    stack1->pop();
    stack1->print();
    cout << "Peak: " << stack1->peak() << endl;
    cout << "Size: " << stack1->size() << endl;
    cout << endl;
    stack1->push(100);
    stack1->push(11);
    stack1->print();
    cout << "Peak: " << stack1->peak() << endl;
    cout << "Size: " << stack1->size() << endl;

    delete stack1;
    */ 

    /*
    //-QUEUE test
    auto* queue1 = new queue<int>(3);
    queue1->push(4);
    queue1->push(6);
    queue1->push(9);
    queue1->push(1);
    queue1->pop();
    queue1->push(10);
    queue1->push(7);
    queue1->print();
    cout << "Front: " << queue1->front() << endl;
    cout << "Back: " << queue1->back() << endl;
    cout << "Size: " << queue1->size() << endl;

    delete queue1;
    */

    /*    
    //-FORWARD test
    auto* forward1 = new ForwardList<int>();
    forward1->push_back(3); 
    forward1->push_back(6); 
    forward1->push_back(10); 
    forward1->push_back(11); 
    forward1->pop_back(); 
    forward1->push_back(12); 
    forward1->push_back(1); 
    forward1->pop_front(); 
    forward1->print();
    cout << "Size: " << forward1->size() << endl;
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;
    cout << "Index[3]: " << (*forward1)[3] << endl;
    auto it_forward_begin = forward1->begin();
    cout << "Iterator begin: " << *it_forward_begin << endl;
    //++it__forward_begin;
    cout << "Iterator next: " << *(++it_forward_begin) << endl;
    auto it_forward_end = forward1->end();
    ++it_forward_begin;
    cout << "Iterator next: " << *(++it_forward_begin) << endl;
    ++it_forward_begin;
    cout << "¿it_forward_begin != it_forward_end?: " << (it_forward_begin != it_forward_end) << endl;
    //cout << "Iterator end: " << *(it_forward_end) << endl;
    ForwardIterator<int> it;
    it = it_forward_begin;
    cout << "Iterator: " << *(it) << endl;
    cout << "¿it_forward_begin != it?: " << (it != it_forward_end) << endl;
    //cout << "Iterator end next: " << *(++it_forward_end) << endl;

    forward1->clear();
    forward1->push_back(2); 
    forward1->push_back(9); 
    forward1->push_back(1); 
    forward1->push_back(8); 
    forward1->push_back(3); 
    forward1->print();
    cout << "Size: " << forward1->size() << endl;
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;
    
    ForwardList<int> to_merge;
    to_merge.push_back(5);
    to_merge.push_back(6);
    to_merge.push_back(10);
    to_merge.print();
    forward1->merge(to_merge);
    forward1->print();
    cout << "Size: " << forward1->size() << endl;
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;
    //to_merge.print();

    forward1->sort();
    forward1->print();
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;
    forward1->push_back(3); 
    forward1->print();

    forward1->reverse();
    forward1->print();
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;

    forward1->clear();
    forward1->print();
    forward1->pop_front(); 
    */

    /*
    //-CIRCULAR test
    auto* circular1 = new CircularLinkedList<int>(); 
    circular1->push_back(3); 
    circular1->push_front(5); 
    circular1->push_front(1); 
    circular1->push_back(10); 
    circular1->push_front(11); 
    circular1->print();

    auto it_rend = circular1->rend();
    ++it_rend;
    cout << "Prueba next rend: " << *it_rend << endl;

    auto it_end = circular1->end();
    --it_end;
    cout << "Prueba prev end: " << *it_end << endl;

    cout << "Front: " << circular1->front() << endl;
    cout << "Back: " << circular1->back() << endl;
    cout << "Index[4]: " << (*circular1)[4] << endl;
    auto it_circular_begin = circular1->begin();
    cout << "Iterator begin: " << *(it_circular_begin) << endl;
    --it_circular_begin;
    cout << "Iterator prev begin: " << *(it_circular_begin) << endl;
    //cout << "Iterator prev begin: " << *(it_circular_begin) << endl;
    auto it_circular_end = circular1->end();
    cout << "Iterator end: " << *(it_circular_end) << endl;
    cout << "Iterator next end: " << *(++it_circular_end) << endl;
    cout << "Iterator next end: " << *(it_circular_end) << endl;

    cout << "¿Iterator prev begin != iterator end? : " << (it_circular_begin != circular1->end()) << endl;
    cout << "¿Iterator next end != iterator prev begin? : " << (it_circular_end != it_circular_begin)<< endl;

    BidirectionalIterator<int> it;
    it = it_circular_begin;
    cout << "Iterator prev begin: " << *(it) << endl;

    circular1->pop_back(); 
    circular1->pop_front(); 
    circular1->print();
    cout << "Front: " << circular1->front() << endl;
    cout << "Back: " << circular1->back() << endl;
    circular1->push_back(5); 
    circular1->push_front(8); 
    circular1->push_front(1); 
    circular1->push_back(12);
    circular1->print();

    circular1->reverse();
    circular1->print();

    CircularLinkedList<int> to_merge;
    to_merge.push_back(5);
    to_merge.push_back(6);
    to_merge.push_back(10);
    to_merge.print();
    circular1->merge(to_merge);
    circular1->print();
    cout << "Front: " << circular1->front() << endl;
    cout << "Back: " << circular1->back() << endl;
    cout << "Index[10]: " << (*circular1)[10] << endl;
    //to_merge.print();
    it = circular1->begin();
    --it;
    cout << *it << endl;

    circular1->clear();
    //circular1->print();
    circular1->push_back(4); 
    circular1->push_front(1); 
    circular1->push_front(8); 
    circular1->push_back(2);
    circular1->print();

    circular1->sort();
    circular1->print();
    cout << "Front: " << circular1->front() << endl;
    cout << "Back: " << circular1->back() << endl;

    circular1->reverse();
    circular1->print();
    cout << "Front: " << circular1->front() << endl;
    cout << "Back: " << circular1->back() << endl;
    */

    /*
    //-LINKED test
    auto* linked1 = new LinkedList<int>();
    linked1->push_back(3);
    linked1->push_back(5);
    linked1->push_front(10);
    linked1->push_front(9);
    linked1->print();
    cout << "Front: " << linked1->front() << endl;
    cout << "Back: " << linked1->back() << endl;
    cout << "Index[0]: " << (*linked1)[0] << endl;
    auto it = linked1->end();
    --it;
    cout << "Prueba de prev end: " << *it << endl;

    auto it_rend = linked1->rend();
    ++it_rend;
    cout << "Prueba de next rend: " << *it_rend << endl;

    linked1->sort();
    linked1->print();

    for(; it != linked1->rend(); --it){
        cout << *it << " -> ";
    }
    cout << endl;

    for(; it_rend != linked1->end(); ++it_rend){
        cout << *it_rend << " -> ";
    }
    cout << endl;

    auto it_linked_begin = linked1->begin();
    cout << "Iterator begin: " << *(it_linked_begin) << endl;
    cout << "Iterator next begin: " << *(++it_linked_begin) << endl;
    cout << "Iterator next next begin: " << *(++it_linked_begin) << endl;
    cout << "Iterator next next next begin: " << *(++it_linked_begin) << endl;
    auto it_linked_end = linked1->end();
    cout << "Iterator end: " << *(it_linked_end) << endl;
    --it_linked_end;
    cout << "Iterator prev end: " << *(it_linked_end) << endl;
    //cout << "Iterator next end: " << *(++it_linked_end) << endl;
    cout << "Iterator prev end: " << *(--it_linked_end) << endl;
    linked1->sort();
    linked1->print();
    cout << "Front: " << linked1->front() << endl;
    cout << "Back: " << linked1->back() << endl;

    linked1->reverse();
    linked1->print();
    cout << "Front: " << linked1->front() << endl;
    cout << "Back: " << linked1->back() << endl;

    LinkedList<int> to_merge;
    to_merge.push_back(5);
    to_merge.push_back(6);
    to_merge.push_back(10);
    to_merge.print();
    linked1->merge(to_merge);
    linked1->print();
    to_merge.push_back(1);
    to_merge.push_front(2);
    to_merge.print();

    linked1->pop_back();
    linked1->print();
    cout << "Size: " << linked1->size() << endl;
    cout << "Front: " << linked1->front() << endl;
    cout << "Back: " << linked1->back() << endl;
    linked1->pop_front();
    linked1->print();
    cout << "Size: " << linked1->size() << endl;
    cout << "Front: " << linked1->front() << endl;
    cout << "Back: " << linked1->back() << endl;
    */

    return EXIT_SUCCESS;
}
