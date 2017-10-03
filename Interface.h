#ifndef INTERFACE_H
#define INTERFACE_H

#include<string>
using std::string;

class Interface
{
public:
  virtual string symbol() = 0;
  virtual string value() = 0;
  virtual bool match(Interface& interface) = 0;

};

#endif
