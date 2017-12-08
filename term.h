#ifndef TERM_H
#define TERM_H

#include<string>
using std::string;

template <class T>
class Iterator;
template <class T>
class DFSIterator;
template <class T>
class BFSIterator;

class Term
{
public:
  virtual string symbol() = 0;
  virtual string value(){return symbol();};
  virtual bool match(Term& term){return symbol() == term.value();};
  virtual bool isVariable(){return false;};
  virtual bool isContain(string symbol){return false;};
  
  virtual Term *find(string symbol)
  {
    if(symbol == this->symbol())
    {
      return this;
    }
    return nullptr;
  };

  virtual Iterator<Term *> *createIterator();
  virtual Iterator<Term *> *createDFSIterator();
  virtual Iterator<Term *> *createBFSIterator();
  
  
  
};

#endif
