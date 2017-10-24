#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <vector>
#include "variable.h"
#include <string>
#include "iostream"
using std::string;
using std::vector;

class List : public Term {
public:
  List (): _elements() {}
  List (vector<Term *>elements):_elements(elements){}
  Term * elements(int index)
  {
    return _elements[index];
  }

  string symbol()
  {
    if(_elements.empty())
    {
      return "[]";
    }
    string ret ="[";
    for(int i = 0; i < _elements.size() - 1 ; i++)
    {
      ret += _elements[i]-> symbol() + ", ";
    }
    ret += _elements[_elements.size()-1]-> symbol() + "]";
    return  ret;
  }

  string value()
  {
    if(_elements.empty())
    {
      string empty = "[]";
      return empty;
    }
    string ret ="[";
    for(int i = 0; i < _elements.size() - 1 ; i++)
    {
      ret += _elements[i]-> value() + ", ";
    }
    ret += _elements[_elements.size()-1]-> value() + "]";
    return  ret;
  }

  bool match(Term & term)
  {
    List * ps = dynamic_cast<List *>(&term);
    if (ps)
    {
      if(_elements.size()!= ps->_elements.size())
      {
        return false;
      }
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
      for(int i=0;i<_elements.size();i++)
      {
        if(!_elements[i]->match(*(ps->_elements[i])))
        {
          std::cout << "match\n";
          return false;
        }
      }
      return true;
    }
    return false;
  }

  bool match(Variable &variable)
  {
    for(int i = 0;i < _elements.size();i++)
    {
      if(&variable == _elements[i])
      {
        return false;
      }
    }
    if(variable.assignable())
    {
      variable.setvalue(this);
      return true;
    }
    return symbol() == variable.value();
  }

public:
  Term * head()
  {
    if(_elements.empty())
    {
      throw string("Accessing head in an empty list");
    }
    return _elements.front();
  }
  List * tail()
  {
    if(_elements.empty())
    {
      throw string("Accessing head in an empty list");
    }
    vector<Term *> _tail;
    for(int i = 1;i < _elements.size();i++)
    {
      _tail.push_back(_elements[i]);
    }
    List *l = new List(_tail);
    return l;
  }

private:
  vector<Term *> _elements;

};

#endif
