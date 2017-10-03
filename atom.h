#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "interface.h"
#include "variable.h"

using std::string;

class Atom : public Interface
{
public:
  Atom (string s):_value(s){}


  string symbol(){ return _value;}

  string value(){ return _value;}

  bool match(Interface& interface){ return symbol() == interface.value(); }

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
