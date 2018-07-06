#include "l_char_stack.h"
#include <iostream>

L_Char_Stack::L_Char_Stack()
{
	head = nullptr;
	size = 0;
}

L_Char_Stack::~L_Char_Stack()
{
	while(!isEmpty())
		pop();
}

bool L_Char_Stack::isEmpty() const
{
    return size == 0;
}

int L_Char_Stack::get_size() const
{
    return size;
}


bool L_Char_Stack::push(const ListItemType& newItem)
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


char L_Char_Stack::pop()
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

bool L_Char_Stack::clear()
{
  while(!isEmpty())
		pop();
  return true;
}
