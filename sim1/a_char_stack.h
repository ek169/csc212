#ifndef A_CHAR_STACK
#define A_CHAR_STACK

class A_Char_Stack
{
private:
  // an array
  int size;
  int capacity;
  char * arr;
  void copy_array();

public:
  A_Char_Stack();
  ~A_Char_Stack();
  bool should_resize();
  int get_size();
  void push(char);
  char pop();
  void clear();

};

#endif
