#include <iostream>
#include "customer_queue_array.h"
using namespace std;

Customer_Queue_Array::Customer_Queue_Array()
{
  size = 0;
  capacity = 2;
  arr = new Customer[capacity];
  front_index = 0;
  back_index = 0;
}

Customer_Queue_Array::~Customer_Queue_Array()
{
  delete[] arr;
}

// add parameter 'char *ser' to enqueue for priority
void Customer_Queue_Array::enqueue(int a, int t, char n, char *type)
{
  Customer new_customer;

  new_customer.name = n;
  new_customer.type = type;
  new_customer.arrived = a;
  new_customer.time_to_serve = t;
  //new_customer->service = ser;
  if(size == 0)
  {
    arr[0] = new_customer;
  }
  else
  {
    if(size < capacity )
    {
      arr[back_index % capacity] = new_customer;
      back_index++;
    }
  }
  size++;
  should_resize();
  return;
}

void Customer_Queue_Array::dequeue()
{
  int served_time;
  int end_time;
  int wait_time;

  Customer dequeued_customer;
  dequeued_customer = arr[front_index % capacity];
  front_index++;
  size--;
  if(size == 0)
  {
    front_index = 0;
    back_index = 0;
  }

  if(dequeued_customer.arrived > get_time())
  {
    add_time(dequeued_customer.arrived - get_time());
  }
  served_time = get_time();
  add_time(dequeued_customer.time_to_serve);
  end_time = get_time();
  wait_time = served_time - dequeued_customer.arrived;

  cout << dequeued_customer.name << "  " << dequeued_customer.type \
  << "  " << dequeued_customer.arrived << "  " << served_time << "  " \
  << end_time << "  " << wait_time << "  " << "Normal Service" << endl;
  should_resize();
  return;
}

int Customer_Queue_Array::size_of()
{
  return size;
}

void Customer_Queue_Array::copy_array()
{
  Customer * temp = new Customer[capacity];
  int front_index_sim = front_index;
  for(int i = 0; i < size; i++)
  {
    temp[i] = arr[front_index_sim];
    front_index_sim++;
  }
  front_index = 0;
  back_index = size;
  delete[] arr;
  arr = temp;
  temp = nullptr;
  return;
}

bool Customer_Queue_Array::should_resize()
{
  if(size == capacity - 1)
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

void Customer_Queue_Array::add_time(int t)
{
  current_time += t;
}

int Customer_Queue_Array::get_time()
{
  return current_time;
}
