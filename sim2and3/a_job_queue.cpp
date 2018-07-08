#include "a_job_queue.h"

A_Job_Queue::A_Job_Queue()
{
  size = 0;
  capacity = 2;
  arr = new Customer*[capacity];
  front_index = 0;
  back_index = 0;
}

A_Job_Queue::~A_Job_Queue()
{
  while(size_of() != 0)
  {
    dequeue();
  }
  delete[] arr;
}

// add parameter 'char *ser' to enqueue for priority
void A_Job_Queue::enqueue(int a, int t, char n, char *type)
{
  Customer* new_customer;
  new_customer = new Customer;

  new_customer->name = n;
  new_customer->type = type;
  new_customer->arrived = a;
  new_customer->time_to_serve = t;
  //new_customer->service = ser;
  if(size == 0)
  {
    arr[0] = new_customer;
  }
  else
  {
    arr[back_index % capacity] = new_customer;
    back_index++;
  }
  size++;
  should_resize();
  return;
}

Customer A_Job_Queue::dequeue()
{
  Customer dequeued_customer;
  dequeued_customer = *arr[front_index % capacity];
  delete arr[front_index % capacity];
  arr[front_index % capacity] = 0;
  front_index++;
  size--;
  if(size == 0)
  {
    front_index = 0;
    back_index = 0;
  }
  should_resize();
  return dequeued_customer;
}

int A_Job_Queue::size_of()
{
  return size;
}

void A_Job_Queue::copy_array()
{
  Customer ** temp = new Customer*[capacity];
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
  temp = 0;
  return;
}

bool A_Job_Queue::should_resize()
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

void A_Job_Queue::add_time(int t)
{
  current_time += t;
}

int A_Job_Queue::get_time()
{
  return current_time;
}
