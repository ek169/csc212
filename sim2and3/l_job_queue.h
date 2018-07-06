#ifndef L_JOB_QUEUE
#define L_JOB_QUEUE
#include "customer.h"

class L_Job_Queue
{
  private:
    Customer *head;
    Customer *tail;
    int current_time;
    int size;

  public:
    L_Job_Queue();
    void enqueue(int, int, char, char*);
    Customer* dequeue();
    int size_of();
    void print_queue();
    void add_time(int);
    int get_time();
};

#endif
