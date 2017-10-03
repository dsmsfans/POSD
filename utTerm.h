#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "variable.h"
#include "atom.h"
#include<iostream>

using namespace std;
//test Number.value()
TEST (Number,ctor)
{
  Number n(25);
  EXPECT_EQ(n.value(),"25");
}
//test Number.symbol()
TEST (Number, symbol)
{
  Atom n("tom");
  EXPECT_EQ(n.symbol(),"tom");
}
//?- 25=25.
//true.
TEST (Number, matchSuccess)
{
  Number n1(25);
  Number n2(25);
  EXPECT_TRUE(n1.match(n2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue)
{
  Number n1(25);
  Number n2(0);
  EXPECT_FALSE(n1.match(n2));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant)
{
  Number n1(25);
  Atom tom("tom");
  EXPECT_FALSE(n1.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar)
{
  Variable X("X");
  Number n(25);
  EXPECT_TRUE(n.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant)
{
  Atom tom("tom");
  Number n(25);
  EXPECT_FALSE(tom.match(n));

}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar)
{
  Atom tom("tom");
  Variable X("X");
  tom.match(X);
  EXPECT_EQ(X.value(),tom.value());
  EXPECT_TRUE(X.match(tom));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant)
{
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  tom.match(X);
  EXPECT_TRUE(X.match(tom));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant)
{
  Variable X("X");
  Atom jerry("jerry");
  Atom tom("tom");
  X.match(jerry);
  EXPECT_FALSE(tom.match(X));

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber)
{
  Variable X("X");
  Number n(5);
  EXPECT_TRUE(X.match(n));

}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers)
{
  Variable X("X");
  Number n1(25);
  Number n2(100);
  X.match(n1);
  EXPECT_FALSE(X.match(n2));

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber)
{
  Variable X("X");
  Atom tom("tom");
  Number n(25);
  X.match(tom);
  EXPECT_FALSE(X.match(n));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2)
{
  Atom tom("tom");
  Variable X("X");
  Number n(25);
  tom.match(X);
  EXPECT_FALSE(n.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom)
{
  Variable X("X");
  Atom tom("tom");
  X.match(tom);
  EXPECT_TRUE(X.match(tom));
}
#endif
