//#include "test/tester.h"
//#include"structures/stack.h"
//#include"structures/queue.h"
//#include"structures/lists/linked.h"
#include"structures/lists/forward.h"

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();
    
    /*    
    //-STACK test
    auto* stack1 = new stack<int>(3);
    stack1->push(3);
    stack1->push(13);
    stack1->push(10);
    stack1->pop();
    stack1->push(6);
    stack1->pop();
    stack1->push(100);
    stack1->push(10);
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
    //cout << "Index[2]: " << forward1[2] << endl; 
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
    forward1->push_back(7); 
    forward1->push_front(11); 
    forward1->print();
    cout << "Front: " << forward1->front() << endl;
    cout << "Back: " << forward1->back() << endl;
    

    return EXIT_SUCCESS;
}
