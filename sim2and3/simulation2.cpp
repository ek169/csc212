#include "a_job_queue.h"
#include "l_job_queue.h"
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
  Customer dequeued_customer;
  A_Job_Queue q;
  //L_Job_Queue q;
  //Job_Ap_Queue q;
  //Job_Lp_Queue q;
  char line[100];
  int num_customers;
  int i = 0;
  int arrival;
  int wait;
  char name;
  char type[20];
  int served_time;
  int end_time;
  int wait_time;

  ifstream textfile;
  textfile.open (argv[1], ifstream::in);
  textfile.getline(line, sizeof(line));
  stringstream ss(line);
  ss >> num_customers;
  while(i < num_customers)
  {
    textfile.getline(line, sizeof(line));
    stringstream ss(line);
    ss >> arrival >> wait >> name >> type;
    if(arrival && wait && name && strlen(type) > 0)
    {
      q.enqueue(arrival, wait, name, type);
    }
    i++;
  }
  cout << "Name|" << "Type|" << "Arrived|" << "Ended|" << "Wait|" \
  << "Service" << endl;
  while(q.size_of() != 0)
  {
    dequeued_customer = q.dequeue();
    if(dequeued_customer.arrived > q.get_time())
    {
      q.add_time(dequeued_customer.arrived - q.get_time());
    }
    served_time = q.get_time();
    q.add_time(dequeued_customer.time_to_serve);
    end_time = q.get_time();
    wait_time = served_time - dequeued_customer.arrived;

    cout << dequeued_customer.name << "  " << dequeued_customer.type \
    << "  " << dequeued_customer.arrived << "  " << served_time << "  " \
    << end_time << "  " << wait_time << "  " << "Normal Service" << endl;
  }

}
