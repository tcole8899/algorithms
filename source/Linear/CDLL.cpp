#include "LinkedList.hpp"

LinkedList::LinkedList()
{
  head = nullptr;
  tail = head;
  len = 0;
}

LinkedList::~LinkedList()
{
  clear();
}

unsigned int LinkedList::length()
{
  return len;
}

void LinkedList::push_front(int d)
{
  Node *n = new Node(d);
  if (!head)
  {
    head = n;
    n->next = head;
    n->prev = head;
    len = 1;
  }
  else
  {
    Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    n->prev = temp;
  }
}

int LinkedList::pop_front()
{
  Node *temp = head;
  int ret = head -> data;
  if (len == 1)
  {
    head->next->prev = nullptr;
  }
  else{
    temp = temp -> next;
    head = temp;
    tail -> next = head;
  }

  return ret;
}

int LinkedList::index(int data)
{
  return 0;
}

void LinkedList::push_back(int d)
{
}

int LinkedList::pop_back()
{
  return 0;
}

int LinkedList::at(int idx)
{
  return 0;
}

int LinkedList::set(int idx, int d)
{
  return 0;
}

void LinkedList::push(int d, int idx)
{
}

int LinkedList::pop(int idx)
{
  return 0;
}

void LinkedList::clear()
{
}

void LinkedList::remove(int d)
{
}

void LinkedList::reverse()
{
}

void LinkedList::print(std::ostream &oss)
{
  Node *temp = head;
  while (temp)
  {
    oss << temp->data << ", ";
    temp = temp->next;
  }
  oss << std::endl;
  return;
}