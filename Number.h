#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "Interface.h"
#include "Variable.h"

using std::string;

class Number : public Interface
{
public:
  Number (string s):_value(s){}


  string symbol(){ return _value;}

  string value(){ return _value;}

  bool match(Interface& interface){ return value() == interface.value(); }

  bool match(Variable& v)
  {
    if(v._assignable)
    {
      v._value = _value;
      v._assignable = false;
      return true;
    }
    else
    {
      return value() == v.value();
    }
  }

  string _value;
};
#endif
