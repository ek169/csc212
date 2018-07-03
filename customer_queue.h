#ifndef CUSTOMER_QUEUE
#define CUSTOMER_QUEUE

class Customer_Queue
{
  private:
    struct Customer
    {
      Customer *next;
      Customer *previous;
      int arrived;
      int time_to_serve;
      char name;
      char *type;
      //char *service;
    };
    Customer *head;
    Customer *tail;
    int current_time;
    int size;

  public:
    Customer_Queue();
    void enqueue(int, int, char, char*);
    void dequeue();
    int size_of();
    void print_queue();
    void add_time(int);
    int get_time();
};

#endif
