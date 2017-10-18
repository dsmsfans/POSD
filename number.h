#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "term.h"
#include "variable.h"

using std::string;

class Number : public Term
{
public:
  Number (double s):_symbol(s){}
  string symbol()
  {
    string n = std::to_string(_symbol);
    int i = n.size() - 1;
    for(;n[i] == '0';i--){}
    if(n[i] == '.')
    {
      i--;
    }
    n.resize(i + 1);
    return n;
  }
  double _symbol;
};
#endif
