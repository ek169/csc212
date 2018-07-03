#ifndef P_STACK
#define P_STACK

class pStack
{
private:
  // an array
  int size;
  int capacity;
  char * arr;
  void copy_array();

public:
  pStack();
  ~pStack();
  bool should_resize();
  int get_size();
  void push(char);
  char pop();
  void clear();
  void print_stack();

};

#endif
