#include <iostream>
#include "customer_priority_queue_array.h"
using namespace std;

Customer_Priority_Queue_Array::Customer_Priority_Queue_Array()
{
  size = 0;
  capacity = 2;
  arr = new Customer[capacity];
  front_index = 0;
  back_index = 0;
}

Customer_Priority_Queue_Array::~Customer_Priority_Queue_Array()
{
  delete[] arr;
}

// add parameter 'char *ser' to enqueue for priority
void Customer_Priority_Queue_Array::enqueue(int a, int t, char n, char *type)
{
  Customer new_customer;
  Customer next_customer;
  Customer current_customer;
  int num_cust;
  int to_increment;
  new_customer.name = n;
  new_customer.type = type;
  new_customer.arrived = a;
  new_customer.time_to_serve = t;
  // after this
  to_increment = back_index;
  num_cust = back_index;
  if(back_index < front_index)
  {
    num_cust += capacity;
    to_increment += capacity;
  }
  while(arr[(num_cust - 1) % capacity].arrived > new_customer.arrived)
  {
    if(num_cust == front_index)
    {
      break;
    }
    num_cust--;
  }
  if(num_cust == back_index)
  {
    arr[back_index % capacity] = new_customer;
  }
  else
  {
    current_customer = arr[num_cust % capacity];
    arr[num_cust % capacity] = new_customer;
    num_cust++;
    while(num_cust <= to_increment)
    {
      next_customer = arr[num_cust % capacity];
      arr[num_cust % capacity] = current_customer;
      current_customer = next_customer;
      num_cust++;
    }
  }
  size++;
  back_index++;
  back_index = back_index % capacity;
  should_resize();
  return;
}

void Customer_Priority_Queue_Array::dequeue()
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

int Customer_Priority_Queue_Array::size_of()
{
  return size;
}

void Customer_Priority_Queue_Array::copy_array()
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

bool Customer_Priority_Queue_Array::should_resize()
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

void Customer_Priority_Queue_Array::add_time(int t)
{
  current_time += t;
}

int Customer_Priority_Queue_Array::get_time()
{
  return current_time;
}
