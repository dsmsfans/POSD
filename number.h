#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "interface.h"
#include "variable.h"

using std::string;

class Number : public Interface
{
public:
  Number (int s):_value(s){}


  string symbol(){ return std::to_string(_value);}

  string value(){ return std::to_string(_value);}

  bool match(Interface& interface){ return value() == interface.value(); }

  bool match(Variable& v)
  {
    if(v._assignable)
    {
      v._value = std::to_string(_value);
      v._assignable = false;
      return true;
    }
    else
    {
      return value() == v.value();
    }
  }

  int _value;
};
#endif
