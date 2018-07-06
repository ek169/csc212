#ifndef JOB_AP_QUEUE
#define JOB_AP_QUEUE
#include "customer.h"

class Job_Ap_Queue
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
    Job_Ap_Queue();
    ~Job_Ap_Queue();
    void enqueue(int, int, char, char*);
    Customer* dequeue();
    int size_of();
    bool should_resize();
    void add_time(int);
    int get_time();
};

#endif
