#ifndef CUSTOMER_QUEUE_ARRAY
#define CUSTOMER_QUEUE_ARRAY

class Customer_Queue_Array
{
  private:
    struct Customer
    {
      int arrived;
      int time_to_serve;
      char name;
      char *type;
      //char *service;
    };
    int size;
    int capacity;
    int front_index;
    int back_index;
    Customer * arr;
    void copy_array();
    int current_time;

  public:
    Customer_Queue_Array();
    ~Customer_Queue_Array();
    void enqueue(int, int, char, char*);
    void dequeue();
    int size_of();
    bool should_resize();
    void add_time(int);
    int get_time();
};

#endif
