#include "Queue.hpp"
Queue::Queue(){
    list = new LinkedList();
};

Queue::~Queue(){
    delete list;
};

/** size()
   * Returns the size of the queue.
   O(1)
   */
unsigned int Queue::size(){
    return list->length();
};

/** push(int data)
   * Pushes a node containing the given data to the back of the queue.
   * O(n)
   */
void Queue::push(int data){
    list->push_back(data);
};

/** pop()
   * Removes and returns the data at the front of the queue.
   * O(1)
   */
int Queue::pop(){
    return list->pop_front();
};

/** front()
   * Returns the data at the front of the queue without changing the queue.
   * O(n)
   */
int Queue::front(){
    return list->at(0);
};

/** back()
   * Returns the data at the back of the queue without changing the queue.
   * O(n)
   */
int Queue::back(){
    return list->at(size()-1);
};

/** empty()
   * Returns whether or not the queue is empty.
   * O(1)
   */
bool Queue::empty(){
    if(size() == 0) return true;
    else return false;
};

/** clear()
   * Clears the entire stack.
   * O(n)
   */
void Queue::clear(){
    list->clear();
};
