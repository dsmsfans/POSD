#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "variable.h"
#include "atom.h"
#include "number.h"
#include "struct.h"
#include <vector>
#include <iostream>

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X._symbol);
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}

TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX)
{
  Variable X("X");
  Number n(2.7182);
  X.match(n);
  EXPECT_EQ(X.value(),"2.7182");
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX)
{
  Variable X("X");
  Variable Y("Y");
  Number n(1);
  X.match(Y);
  X.match(n);
  EXPECT_EQ(Y.value(),"1");

}

// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY)
{
  Variable X("X");
  Variable Y("Y");
  Number n(1);
  X.match(Y);
  Y.match(n);
  EXPECT_EQ(X.value(),"1");
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX)
{
  Variable X("X");
  Number n(1);
  X.match(X);
  X.match(n);
  EXPECT_EQ(X.value(),"1");
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY)
{
  Variable X("X");
  Variable Y("Y");
  Number n(1);
  Y.match(n);
  X.match(Y);
  EXPECT_EQ(X.value(),"1");
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX)
{
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  Number n(1);
  X.match(Y);
  Y.match(Z);
  Z.match(n);
  EXPECT_EQ(X.value(),"1");
  EXPECT_EQ(Y.value(),"1");
  EXPECT_EQ(Z.value(),"1");
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX)
{
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  Number n(1);
  X.match(Y);
  X.match(Z);
  Z.match(n);
  EXPECT_EQ(X.value(),"1");
  EXPECT_EQ(Y.value(),"1");
  EXPECT_EQ(Z.value(),"1");
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1)
{
  Variable X("X");
  Variable Y("Y");
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  Y.match(s);
  EXPECT_EQ(Y.symbol(),"Y");
  EXPECT_EQ(Y.value(),"s(X)");
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2)
{
  Variable X("X");
  Variable Y("Y");
  Atom teddy("teddy");
  X.match(teddy);
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  Y.match(s);
  EXPECT_EQ(Y.symbol(),"Y");
  EXPECT_EQ(Y.value(),"s(teddy)");
}


TEST (Variable, num1_to_varY_and_varX_match_varY1111)
{
  Variable X("X");
  Variable Y("Y");
  Number n(1);
  Y.match(n);
  Y.match(X);
  EXPECT_EQ(X.value(),"1");
}

#endif
