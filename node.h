#ifndef NODE_H
#define NODE_H

enum Operators 
{
  SEMICOLON, //; ||
  //0
  COMMA,     //. &&
  //1
  EQUALITY,  //= match
  //2
  TERM        
  //3
};

class Node 
{
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t = 0, Node *l = 0, Node *r = 0):payload(op), term(t), left(l), right(r) {}

  bool evaluate()
  {
    if(payload == EQUALITY)
    {
      return left->term->match(*(right->term));
    }
    if(payload == COMMA)
    {
      return left->evaluate() && right->evaluate();
    }
    if(payload == SEMICOLON)
    {
      bool l = left->evaluate();
      bool r = right->evaluate();
      return l || r;
    }
  };

  Operators payload;
  Term * term;
  Node *left, *right;
};

#endif
