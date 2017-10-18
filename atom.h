#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "variable.h"
#include <iostream>

using std::string;

class Atom : public Term
{
public:
  Atom (string s):_symbol(s){}
  string symbol(){ return _symbol;}
  bool match(Term &term)
  {
    Variable * variable;
    if(term.isVariable())
    {
      variable = dynamic_cast<Variable *>(&term);
      if(variable->assignable())
      {
        variable->setvalue(this);
        return true;
      }
      return symbol() == variable->symbol();
    }
    return _symbol == term.value();
  }

  string _symbol;

};

#endif
