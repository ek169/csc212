#include "l_job_queue.h"

L_Job_Queue::L_Job_Queue()
{
  size = 0;
  head = 0;
  tail = 0;
}

L_Job_Queue::~L_Job_Queue()
{
  while(size_of() != 0)
  {
    dequeue();
  }
}

void L_Job_Queue::enqueue(int a, int t, char n, char *type)
{
  Customer * new_customer;

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
    new_customer->next = 0;
    new_customer->previous = 0;
  }
  else
  {
    new_customer->next = head;
    new_customer->previous = 0;
    head->previous = new_customer;
    head = new_customer;
  }
  size += 1;
}

Customer L_Job_Queue::dequeue()
{

  Customer *dequeued_customer;
  Customer dequeue_customer_const;
  dequeued_customer = tail;
  dequeue_customer_const = *dequeued_customer;
  size--;
  if(size == 0)
  {
    head = 0;
    tail = 0;
  }
  else
  {
    tail = tail->previous;
    tail->next = 0;
  }
  dequeued_customer->next = 0;
  dequeued_customer->previous = 0;
  delete dequeued_customer;

  dequeue_customer_const.next = 0;
  dequeue_customer_const.previous = 0;
  return dequeue_customer_const;
}

int L_Job_Queue::size_of()
{
  return size;
}


void L_Job_Queue::add_time(int t)
{
  current_time += t;
}

int L_Job_Queue::get_time()
{
  return current_time;
}
