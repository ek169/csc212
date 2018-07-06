#include <iostream>
#include <fstream>
#include "l_char_stack.h"
#include "a_char_stack.h"
#include <stdlib.h>
using namespace std;

int main () {

  int total_lines = 0;
  int valid_lines = 0;
  int invalid_lines = 0;
  bool line_is_correct;
  A_Char_Stack stack; // comment out if using linked list
  //L_Char_Stack stack; // comment out if using dynamic array
  char line[100];
  ifstream textfile;
  textfile.open ("parenthesis_txt2.txt", ifstream::in);
  while (textfile.getline(line, sizeof(line)))
  {
    line_is_correct = true;
    total_lines++;
    for(int c = 0; c < strlen(line); c++)
    {
      char character = line[c];

      switch(character)
      {
        case '{':
        case '[':
        case '(':
          stack.push(character);
          // stack.should_resize(); // uncomment if using dynamic array
          break;
        case '}':
          if(!(stack.pop() == '{'))
          {
            line_is_correct = false;
          }
          break;
        case ']':
          if(!(stack.pop() == '['))
          {
            line_is_correct = false;
          }
          break;
        case ')':
          if(!(stack.pop() == '('))
          {
            line_is_correct = false;
          }
          break;
        default:
          break;
        }
      }
      if(line_is_correct && (stack.get_size() == 0))
      {
        valid_lines++;
      }
      else
      {

        invalid_lines++;
      }
      stack.clear();
  }
  cout << "~ Statistics ~" << endl;
  cout << total_lines << " total lines." << endl;
  cout << valid_lines << " valid lines." << endl;
  cout << invalid_lines << " invalid lines." << endl;
  cout << ((double) valid_lines / total_lines) * 100 << "% valid" << endl;
  cout << ((double) invalid_lines / total_lines) * 100 << "% invalid" << endl;

  textfile.close();
  return 0;
}
