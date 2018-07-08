#include "job_lp_queue.h"

Job_Lp_Queue::Job_Lp_Queue()
{
  size = 0;
  head = 0;
  tail = 0;
}
// add parameter 'char *ser' to enqueue for priority
void Job_Lp_Queue::enqueue(int a, int t, char n, char *type)
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
    new_customer->next = 0;
    new_customer->previous = 0;
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
      new_customer->previous = 0;
      next_customer->previous = new_customer;
      head = new_customer;
    }
    else if(num_cust == size)
    {
      tail->next = new_customer;
      new_customer->previous = tail;
      new_customer->next = 0;
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
  return;
}

Customer Job_Lp_Queue::dequeue()
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

int Job_Lp_Queue::size_of()
{
  return size;
}

void Job_Lp_Queue::add_time(int t)
{
  current_time += t;
}

int Job_Lp_Queue::get_time()
{
  return current_time;
}
