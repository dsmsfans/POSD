#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "variable.h"

using std::string;

class Atom : public Term
{
public:
  Atom (string s):_symbol(s){}
  string symbol(){ return _symbol;}
  string _symbol;
};

#endif
