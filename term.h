#ifndef TERM_H
#define TERM_H

#include<string>
using std::string;

class Term
{
public:
  virtual string symbol() = 0;
  virtual string value(){return symbol();};
  virtual bool match(Term& term){return symbol() == term.value();};
  virtual bool isVariable(){return false;};
};

#endif
