#ifndef JOB_LP_QUEUE
#define JOB_LP_QUEUE
#include "customer.h"

class Job_Lp_Queue
{
  private:
    Customer *head;
    Customer *tail;
    int current_time;
    int size;

  public:
    Job_Lp_Queue();
    void enqueue(int, int, char, char*);
    Customer* dequeue();
    int size_of();
    void add_time(int);
    int get_time();
};

#endif
