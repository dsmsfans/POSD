#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include "term.h"
#include <stack>
#include <queue>
#include <iostream>
using std::stack;
using std::queue;


template <class T>
class Iterator 
{
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() = 0;
  virtual bool isDone() = 0;
};

template <class T>
class NullIterator :public Iterator<T>
{
public:
  NullIterator(Term *n):temp(n){}
  void first(){}
  void next(){}
  Term * currentItem()
  {
      return temp;
  }
  bool isDone()
  {
    return true;
  }
  Term* temp;

};

template <class T>
class StructIterator :public Iterator<T>
{
public:
  friend class Struct;
  void first() 
  {
    _index = 0;
  }

  Term* currentItem()
  {
    return _s->args(_index);
  }

  bool isDone() 
  {
    return _index >= _s->arity();
  }

  void next() 
  {
    _index++;
  }
private:
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

template <class T>
class ListIterator :public Iterator<T> 
{
public:
  friend class List;
  
  void first() 
  {
    _index = 0;
  }

  Term* currentItem()
  {
    return _list->args(_index);
  }

  bool isDone()
  {
    return _index >= _list->arity();
  }

  void next() 
  {
    _index++;
  }
private:
  ListIterator(List *list): _index(0), _list(list) {}
  int _index;
  List* _list;
};

template <class T>
class DFSIterator : public Iterator<T>
{
public:
  friend class List;
  friend class Struct;

  void first()
  {
    
    while(!_iteratorstack.empty())
    {
      _iteratorstack.pop();
    }
    _iteratorstack.push(_item->createIterator());
    std::cout << _iteratorstack.top()->currentItem() <<std::endl;
  }
  Term *currentItem()
  {
    return _iteratorstack.top()->currentItem();
  }
  void next()
  {
    if(!isDone())
    {
      if(isLeaf())
      {
        _iteratorstack.top()->next();
        while(!isDone() && _iteratorstack.top()->isDone())
        {
          _iteratorstack.pop();
          if(!isDone())
          {
            _iteratorstack.top()->next();
            std::cout <<_iteratorstack.top()->currentItem() << std::endl;
          }
        }
      }
      else
      {
        _iteratorstack.push(currentItem()->createIterator());
      }
    }
  }
  bool isDone()
  {
    return _iteratorstack.empty();
  }

 
private:
  DFSIterator(T item):_item(item)
  {
    _iteratorstack.push(_item->createIterator());
  }
  bool isLeaf()
  {
    return currentItem()->createIterator()->isDone();
  }
  stack<Iterator<Term*>*>_iteratorstack;
  T _item;
};

template <class T>
class BFSIterator : public Iterator<T>
{
public:
  friend class Struct;
  friend class List;

  void first()
  {
    while(!_iteratorqueue.empty())
    {
      _iteratorqueue.pop();
    }
    _iteratorqueue.push(_item->createIterator());
  }
  Term *currentItem()
  {
    return _iteratorqueue.front()->currentItem();
  }
  void next()
  {
    if(!isDone())
    {
      if(isLeaf())
      {
        _iteratorqueue.front()->next();
        if(_iteratorqueue.front()->isDone())
        {
          _iteratorqueue.pop();
        }
      }
      else
      {
        _iteratorqueue.push(currentItem()->createIterator());
        _iteratorqueue.front()->next();
        if(_iteratorqueue.front()->isDone())
        {
          _iteratorqueue.pop();
        }
      }
    }
  }
  bool isDone()
  {
    return _iteratorqueue.empty();
  }
private:
  BFSIterator(T item): _item(item)
  {
    _iteratorqueue.push(_item->createIterator());
  }
  bool isLeaf()
  {
    return currentItem()->createIterator()->isDone();
  }
  queue<Iterator<Term *>*>_iteratorqueue;
  T _item;
};

#endif
