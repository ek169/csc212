#include "job_ap_queue.h"
#include "job_lp_queue.h"
#include "customer.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  typedef Job_Ap_Queue queue_type;
  //typedef Job_Lp_Queue queue_type;
  queue_type * q;
  queue_type master_q;
  Customer * next_customer;
  Customer * dequeued_customer;
  int * available;
  int shortest_queue;
  char line[100];
  int num_customers;
  int num_queues;
  int i;
  int j;
  int arrival;
  int wait;
  char name;
  char type[20];
  char * customer_type;
  int served_time;
  int end_time;
  int wait_time;
  int is_enqueued = 0;

  ifstream textfile;
  textfile.open (argv[1], ifstream::in);
  textfile.getline(line, sizeof(line));
  stringstream ss(line);
  ss >> num_customers >> num_queues;
  ss.clear();

  if(num_queues > 0)
  {
    i = 0;
    while(i < num_customers)
    {
      textfile.getline(line, sizeof(line));
      ss.str(line);
      ss >> arrival >> wait >> name >> type;
      if(arrival && wait && name && strlen(type) > 0)
      {
        master_q.enqueue(arrival, wait , name, type);
      }
      i++;
      ss.clear();
    }

    q = new queue_type[num_queues];
    available = new int[num_queues];

    while(master_q.size_of() != 0)
    {
      shortest_queue = 0;
      next_customer = master_q.dequeue();

      arrival = next_customer->arrived;
      wait = next_customer->time_to_serve;
      name = next_customer->name;
      customer_type = next_customer->type;

      delete next_customer;

      is_enqueued = 0;
      for(i = 1; i < num_queues; i++)
      {
        if((available[shortest_queue] - arrival) <= 0)
        {
          q[shortest_queue].enqueue(arrival, wait, name, customer_type);
          available[shortest_queue] = (arrival+wait);
          is_enqueued = 1;
          break;
        }
        else if((available[i] - arrival) < (available[shortest_queue] - arrival))
        {
          shortest_queue = i;
        }
        else
        {
          continue;
        }
      }
      if(!is_enqueued)
      {
        q[shortest_queue].enqueue(arrival, wait, name, customer_type);
        available[shortest_queue] += wait;

      }
    }

    i = 0;
    while(i < num_queues)
    {
      cout << "~~~~ This is Queue " << i << " ~~~~" << endl;
      cout << "Name|" << "Type|" << "Arrived|" << "Ended|" << "Wait|" \
      << "Service" << endl;
      while(q[i].size_of() != 0)
      {
        dequeued_customer = q[i].dequeue();
        if(dequeued_customer->arrived > q[i].get_time())
        {
          q[i].add_time(dequeued_customer->arrived - q[i].get_time());
        }
        served_time = q[i].get_time();
        q[i].add_time(dequeued_customer->time_to_serve);
        end_time = q[i].get_time();
        wait_time = served_time - dequeued_customer->arrived;

        cout << dequeued_customer->name << "  " << dequeued_customer->type \
        << "  " << dequeued_customer->arrived << "  " << served_time << "  " \
        << end_time << "  " << wait_time << "  " << "Normal Service" << endl;
        delete dequeued_customer;
      }
      i++;
    }

    delete[] q;
    delete[] available;
  }


}
