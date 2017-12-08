#ifndef STRUCT_H
#define STRUCT_H

#include "term.h"
#include "atom.h"
#include <vector>
#include <string>

using std::string;


template <class T>
class Iterator;
template <class T>
class DFSIterator;
template <class T>
class BFSIterator;

class Struct:public Term
{
public:
  Struct(Atom name, std::vector<Term *> args):_name(name), _args(args) {}

  int arity()
  {
    return _args.size();
  }

  Term * args(int index)
  {
    return _args[index];
  }

  Atom name()
  {
    return _name;
  }
  string symbol()
  {
    string ret =_name.symbol() + "(";
    if(arity() == 0)
    {
      ret += ")";
      return ret;
    }
    for(int i = 0; i < _args.size() - 1 ; i++)
    {
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return  ret;
  }
  string value()
  {
    string ret =_name.value() + "(";
    if(arity() == 0)
    {
      ret += ")";
      return ret;
    }
    for(int i = 0; i < _args.size() - 1 ; i++)
    {
      ret += _args[i]-> value() + ", ";
    }
    ret += _args[_args.size()-1]-> value() + ")";
    return  ret;
  }
  bool match(Term &term)
  {
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps)
    {
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++)
      {
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }
  bool match(Variable &variable)
  {
    if (variable.assignable())
    {
      variable.setvalue(this);
      return true;
    }
    else
    {
      return symbol() == variable.value();
    } 
  } 

  bool isContain(string symbol)
  {
    for (int i = 0; i < _args.size(); i++)
    {
      if (symbol == _args[i]->symbol() || _args[i]->isContain(symbol))
      {
        return true;
      }
    }
  }
  
  Term *find(string symbol)
  {
    for (int i = 0; i < _args.size(); i++)
    {
      if (_args[i]->find(symbol) != nullptr)
        return _args[i]->find(symbol);
    }
  }
  
  Iterator <Term*>* createIterator();
  Iterator <Term*>* createDFSIterator();
  Iterator <Term*>* createBFSIterator();

private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
