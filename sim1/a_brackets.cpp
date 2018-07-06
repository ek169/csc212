#include "a_char_stack.h"
#include <iostream>
using namespace std;

A_Char_Stack::A_Char_Stack()
{
  size = 0;
  capacity = 2;
  arr = new char[capacity];
}

A_Char_Stack::~A_Char_Stack()
{
  delete[] arr;
}

void A_Char_Stack::copy_array()
{
  char * temp = new char[capacity];
  for(int i = 0; i < size; i++)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = temp;
  temp = nullptr;
  return;
}

bool A_Char_Stack::should_resize()
{
  if(size == capacity - 2)
  {
    capacity *= 2;
  }
  else if ((double) size < ((double) capacity / 4))
  {
    capacity /= 2;
  }
  else
  {
    return false;
  }
  copy_array();
  return true;
}

void A_Char_Stack::push(char c)
{
  arr[size] = c;
  size++;
}

char A_Char_Stack::pop()
{
  char popped_char = arr[size - 1];
  arr[size - 1] = '\0';
  size--;
  return popped_char;
}

int A_Char_Stack::get_size()
{
  return size;
}

void A_Char_Stack::clear()
{
  size = 0;
}
