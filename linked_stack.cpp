#include "linked_stack.h"
#include <iostream>

Linked_List::Linked_List()
{
	head = nullptr;
	size = 0;
}

Linked_List::~Linked_List()
{
	while(!isEmpty())
		pop();
}

bool Linked_List::isEmpty() const
{
    return size == 0;
}

int Linked_List::get_size() const
{
    return size;
}


bool Linked_List::push(const ListItemType& newItem)
{
  if(newItem)
  {
    int newLength = get_size() + 1;
    size = newLength;
    ListNode *newPtr = new ListNode;
    newPtr->item = newItem;
    if(size == 1)
    {
       newPtr->next = nullptr;
    }
    else
    {
      head->previous = newPtr;
      newPtr->next = head;
    }
    newPtr->previous = nullptr;
    head = newPtr;
    return true;
  }
  return false;
}


char Linked_List::pop()
{
    char item;
    if(size > 0)
    {
      ListNode *current;
      current = head;
      if(size == 1)
      {
        head = nullptr;
      }
      else
      {
        head = head->next;
        head->previous = nullptr;
      }
      item = current->item;
      current->next = nullptr;
      current->previous = nullptr;
      delete current;
      current = nullptr;
      size = get_size() - 1;
    }
    return item;

}

bool Linked_List::clear()
{
  while(!isEmpty())
		pop();
  return true;
}
