#include "job_ap_queue.h"

Job_Ap_Queue::Job_Ap_Queue()
{
  size = 0;
  capacity = 2;
  arr = new Customer*[capacity];
  front_index = 0;
  back_index = 0;
}

Job_Ap_Queue::~Job_Ap_Queue()
{
  delete[] arr;
}

// add parameter 'char *ser' to enqueue for priority
void Job_Ap_Queue::enqueue(int a, int t, char n, char *type)
{
  Customer* new_customer;
  Customer* next_customer;
  Customer* current_customer;
  new_customer = new Customer;
  int num_cust;
  int to_increment;
  new_customer->name = n;
  new_customer->type = type;
  new_customer->arrived = a;
  new_customer->time_to_serve = t;
  // after this
  to_increment = back_index;
  num_cust = back_index;
  if(back_index < front_index)
  {
    num_cust += capacity;
    to_increment += capacity;
  }
  if(size == 0)
  {
    arr[0] = new_customer;
  }
  else
  {
    while(arr[(num_cust - 1) % capacity]->arrived > new_customer->arrived)
    {
      if((num_cust - 1) == front_index)
      {
        num_cust--;
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
  }
  size++;
  back_index++;
  back_index = back_index % capacity;
  should_resize();
  return;
}

Customer* Job_Ap_Queue::dequeue()
{
  int served_time;
  int end_time;
  int wait_time;

  Customer* dequeued_customer;
  dequeued_customer = arr[front_index % capacity];
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

int Job_Ap_Queue::size_of()
{
  return size;
}

void Job_Ap_Queue::copy_array()
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

bool Job_Ap_Queue::should_resize()
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

void Job_Ap_Queue::add_time(int t)
{
  current_time += t;
}

int Job_Ap_Queue::get_time()
{
  return current_time;
}
