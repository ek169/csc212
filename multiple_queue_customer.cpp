#include "customer_queue.h"
#include "priority_customer_queue.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  Customer_Queue q;
  Priority_Customer_Queue pq;
  char line[100];
  int num_customers;
  int i = 0;
  int arrival;
  int wait;
  char name;
  char type[20];

  ifstream textfile;
  textfile.open (argv[1], ifstream::in);
  textfile.getline(line, sizeof(line));
  stringstream ss(line);
  ss >> num_customers;
  cout << num_customers << endl;
  while(i < num_customers)
  {
    textfile.getline(line, sizeof(line));
    stringstream ss(line);
    ss >> arrival >> wait >> name >> type;
    if(arrival && wait && name && strlen(type) > 0)
    {
      q.enqueue(arrival, wait , name, type);
      cout << "can enqueue" << endl;
    }
    i++;
  }
  cout << "Name|" << "Type|" << "Arrived|" << "Ended|" << "Wait|" \
  << "Service" << endl;
  while(q.size_of() != 0)
  {
    q.dequeue();
  }

}
