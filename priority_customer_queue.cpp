#include <iostream>
#include "priority_customer_queue.h"
using namespace std;

Priority_Customer_Queue::Priority_Customer_Queue()
{
  size = 0;
  head = nullptr;
  tail = nullptr;
}
// add parameter 'char *ser' to enqueue for priority
void Priority_Customer_Queue::enqueue(int a, int t, char n, char *type)
{
  Customer * new_customer;
  Customer * next_customer;
  Customer * previous_customer;
  int num_cust = 0;

  new_customer = new Customer;
  new_customer->name = n;
  new_customer->type = type;
  new_customer->arrived = a;
  new_customer->time_to_serve = t;
  //new_customer->service = ser;
  if(size == 0)
  {
    tail = new_customer;
    head = new_customer;
    new_customer->next = nullptr;
    new_customer->previous = nullptr;
  }
  else
  {
    next_customer = head;
    while(next_customer->arrived > new_customer->arrived)
    {
      num_cust++;
      if(num_cust == size)
      {
        break;
      }
      next_customer = next_customer->next;
    }
    if(num_cust == 0)
    {
      new_customer->next = next_customer;
      new_customer->previous = nullptr;
      next_customer->previous = new_customer;
      head = new_customer;
    }
    else if(num_cust == size)
    {
      next_customer->next = new_customer;
      new_customer->previous = next_customer;
      new_customer->next = nullptr;
      tail = new_customer;
    }
    else
    {
      previous_customer = next_customer->previous;
      previous_customer->next = new_customer;
      new_customer->previous = previous_customer;
      new_customer->next = next_customer;
      next_customer->previous = new_customer;
    }
  }
  size += 1;
}

void Priority_Customer_Queue::dequeue()
{
  int served_time;
  int end_time;
  int wait_time;

  Customer *dequeued_customer;
  dequeued_customer = tail;
  size--;
  if(size == 0)
  {
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    tail = tail->previous;
    tail->next = nullptr;
  }
  dequeued_customer->next = nullptr;
  dequeued_customer->previous = nullptr;

  if(dequeued_customer->arrived > get_time())
  {
    add_time(dequeued_customer->arrived - get_time());
  }
  served_time = get_time();
  add_time(dequeued_customer->time_to_serve);
  end_time = get_time();
  wait_time = served_time - dequeued_customer->arrived;

  cout << dequeued_customer->name << "  " << dequeued_customer->type \
  << "  " << dequeued_customer->arrived << "  " << served_time << "  " \
  << end_time << "  " << wait_time << "  " << "Normal Service" << endl;

  delete dequeued_customer;

  return;
}

int Priority_Customer_Queue::size_of()
{
  return size;
}

void Priority_Customer_Queue::print_queue()
{
  Customer *p;
  p = head;
  while(p != nullptr)
  {
    cout << "name: " << p->name << endl;
    cout << "arrived: " << p->arrived << endl;
    cout << "time_served: " << p->time_to_serve << endl;
    p = p->next;
  }
}

void Priority_Customer_Queue::add_time(int t)
{
  current_time += t;
}

int Priority_Customer_Queue::get_time()
{
  return current_time;
}
