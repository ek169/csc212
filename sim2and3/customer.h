#ifndef CUSTOMER
#define CUSTOMER
struct Customer
{
  Customer *next;
  Customer *previous;
  int arrived;
  int time_to_serve;
  char name;
  char *type;
};
#endif
