#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"

using std::string;

class Variable : public Term
{
public:
  Variable (string s):_symbol(s),_value(NULL){}
  string symbol(){ return _symbol;}
  string value()
  {
    if(!_value)
    {
      return _symbol;
    }
    return _value->value();
  }

  bool match(Term& term)
  {
    if(&term == this)
    {
      return true;
    }
    if(_value)
    {
      return _value->match(term);
    }
    _value = &term;
    return true;
  }

  //bool _assignable = true;
  string _symbol;
  Term * _value;
};

#endif
