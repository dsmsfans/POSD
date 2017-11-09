#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <iostream>
using std::string;

#include "number.h"
#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm()
  {
    int token = _scanner.nextToken();
    _currentToken = token;
    //std::cout << _currentToken << std::endl;
    if(token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM || token == ATOMSC)
    {
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) 
        {
          _scanner.nextToken() ;
          vector<Term*> terms = getArgs();
          if(_currentToken == ')')
          {
            return new Struct(*atom, terms);
          }
            
        }
        else
          return atom;
    }
    
    else if(token == '[')
    {
      //std::cout << "123" << std::endl;
      vector<Term*> terms = getArgs();
      
      if(_currentToken == ')')
      {
        throw(std::string("unexpected token"));
      } 
      if(_currentToken == ']' || _currentToken == 0)
      {
          return new List(terms);
      }
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args = {};
    if(term)
    {
      args.push_back(term);
    }
    if((_currentToken == ']' || _currentToken == ')') && term == nullptr)
    {
        
        return args;
    }
    while((_currentToken = _scanner.nextToken()) == ',') 
    {
      args.push_back(createTerm());
    }
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
