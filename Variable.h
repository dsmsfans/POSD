#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Interface.h"

using std::string;

class Variable : public Interface
{
public:
  Variable (string s):_assignable(true),_value(s){}

  string symbol(){ return _symbol;}

  string value(){ return _value;}

  bool match(Interface& interface)
  {
    if(_assignable)
    {
      _value = interface.value();
      _assignable = false;
      return true;
    }
    else
    {
      return value() == interface.value();
    }
  }

  bool _assignable = true;
  string _symbol;
  string _value;
};

#endif
