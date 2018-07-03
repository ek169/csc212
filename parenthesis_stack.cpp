#include "parenthesis_stack.h"
#include <iostream>
using namespace std;

pStack::pStack()
{
  size = 0;
  capacity = 2;
  arr = new char[capacity];
}

pStack::~pStack()
{
  delete[] arr;
}

void pStack::copy_array()
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

bool pStack::should_resize()
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

void pStack::push(char c)
{
  arr[size] = c;
  size++;
}

char pStack::pop()
{
  char popped_char = arr[size - 1];
  arr[size - 1] = '\0';
  size--;
  return popped_char;
}

int pStack::get_size()
{
  return size;
}

void pStack::clear()
{
  size = 0;
}

void pStack::print_stack()
{
  for(int i = 0; i < size; i++)
  {
    cout << "Element " << i << ": " << arr[i] << endl;
  }
}
