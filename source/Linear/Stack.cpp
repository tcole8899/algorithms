#include "Stack.hpp"

Stack::Stack(){
    head =  nullptr;
    len = 0;
};

Stack::~Stack(){
    clear();
};

/** size()
* Returns the size of the stack.
*/
unsigned int Stack::size(){
    return len;
};

/** push(int data)
   * Pushes a node containing the given data to the top of the stack.
   */
void Stack::push(int data){
    Node* n = new Node(data);
    if(len == 0) head = n;
    else{
        Node* temp = head;
        while(temp) temp = temp->next;
        temp->next = n;
        n -> next = head;
        head = n;
    }
};

/** pop()
   * Removes and returns the data at the top of the stack.
   */
int Stack::pop(){
    int result = head -> data;
    if(len == 0) return;
    else if(len == 1) return result;
    else{
        Node* temp = head;
        while(temp) temp = temp -> next;
    }

};

/** top()
   * Returns the data at the top of the stack without changing the stack.
   */
int top();

/** empty()
   * Returns whether or not the stack is empty.
   */
bool empty();

/** clear()
   * Clears the entire stack.
   */
void clear();
