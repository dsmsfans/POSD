#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "Interface.h"
#include "Variable.h"

using std::string;

class Atom : public Interface
{
public:
  Atom (string s):_symbol(s){}


  string symbol(){ return _symbol;}

  string value(){ return _symbol;}

  bool match(Interface& interface){ return symbol() == interface.value(); }

  bool match(Variable& v)
  {
    if(v._assignable)
    {
      v._symbol = _symbol;
      v._assignable = false;
      return true;
    }
    else
    {
      return symbol() == v.value();
    }
  }

  string _symbol;
};

#endif
