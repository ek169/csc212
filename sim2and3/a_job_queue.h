#ifndef A_JOB_QUEUE
#define A_JOB_QUEUE
#include "customer.h"


class A_Job_Queue
{
  private:
    int size;
    int capacity;
    int front_index;
    int back_index;
    Customer ** arr;
    void copy_array();
    int current_time;

  public:
    A_Job_Queue();
    ~A_Job_Queue();
    void enqueue(int, int, char, char*);
    Customer dequeue();
    int size_of();
    bool should_resize();
    void add_time(int);
    int get_time();
};

#endif
