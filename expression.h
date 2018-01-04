#ifndef UTEXPRESSION_H
#define UTEXPRESSION_H

#include "parser.h"
#include "scanner.h"
#include "exp.h"
#include <string>
#include <iostream>

using namespace std;

TEST(Shell2, varMatchAtomSuc) 
{
  Scanner s("FILCO=awesome.");
  Parser p(s);
  try{
    p.buildExpression();
    string result;
    if(p.getExpressionTree()->evaluate())
    {
      result = p.getExpressionTree()->getResult() + ".";
    }
    ASSERT_EQ("FILCO = awesome.", result);
  } 
  catch (std::string & msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, atomMatchAtomFail) 
{
  Scanner s("smog=natural_disaster.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("false.", result);
  } 
  catch (std::string & msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, varMatchList) 
{
  Scanner s("Painful=[Clerk,forgot,pipette].");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("Painful = [Clerk, forgot, pipette].", result);
  } 
  catch (std::string & msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, varMatchStruct) 
{
  Scanner s("Pitiful=binding([rope,rope,rope], Turtle, oil).");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("Pitiful = binding([rope, rope, rope], Turtle, oil).", result);
  } 
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, varMatchItself) 
{
  Scanner s("Taiwan=Taiwan.");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("true.", result);
  } 
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, varMachingListThatIncludeVar) 
{
  Scanner s("X=[Y,tom], Y=marry.");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("X = [marry, tom], Y = marry.", result);
  } 
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, varMachingStructThatIncludeVar) 
{
  Scanner s("X=s(Y,marry), Y=tom.");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("X = s(tom, marry), Y = tom.", result);
  } 
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}


TEST(Shell2, conjunctionMatching_false) 
{
  Scanner s("X=1, X=2.");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("false.", result);
  }
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_diffExp) 
{
  Scanner s("X=1, Y=2.");
  Parser p(s);
  try 
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("X = 1, Y = 2.", result);
  } 
  catch (std::string &msg) 
  {
    FAIL() << msg;
  }
}

// TEST(Shell2, conjunctionMatching_sameExp) 
// {
//   Scanner s("X=1, X=1.");
//   Parser p(s);
//   try 
//   {
//     p.buildExpression();
//     string result = p.getExpressionTree()->getResult();
//     cout << result <<endl;
//     ASSERT_EQ("X = 1.", result);
//   } 
//   catch (std::string &msg) 
//   {
//     FAIL() << msg;
//   }
// }

TEST(Shell2, conjunctionMatching_true)
{
  Scanner s("X=X, X=X.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("true.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_trueAndExp)
{
  Scanner s("X=X, Y=1.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("Y = 1.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_expAndtrue)
{
  Scanner s("Y=1, X=X.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("Y = 1.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_trueAndfalse)
{
  Scanner s("X=X, 1=2.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("false.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_falseAndtrue)
{
  Scanner s("3=2, X=X.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("false.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_falseAndfalse)
{
  Scanner s("X=1, X=2, 1=2.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("false.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching_duplicateExp)
{
  Scanner s("Y=1, X=2, X=2.");
  Parser p(s);
  try
  {
    p.buildExpression();
    string result = p.getExpressionTree()->getResult() + '.';
    ASSERT_EQ("Y = 1, X = 2.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, conjunctionMatching)
{
  Scanner s("Y=1, X=2, X=2.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("Y = 1, X = 2.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching1)
{
  Scanner s("X=1; X=2.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1; X = 2.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching2)
{
  Scanner s("X=1; X=1, X=2.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching3)
{
  Scanner s("X=1; X=1, Y=2.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1; X = 1, Y = 2.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching4)
{
  Scanner s("X=1; X=3, X=X.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1; X = 3.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching5)
{
  Scanner s("X=1; X=X; Y=2.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1; Y = 2.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, disjunctionMatching6)
{
  Scanner s("X=1; X=1, X=2; Z=3.");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    ASSERT_EQ("X = 1; Z = 3.", result);
  }
  catch (std::string &msg)
  {
    FAIL() << msg;
  }
}

TEST(Shell2, exceptionMissingPeriodToken)
{
  Scanner s("X=1");
  Parser p(s);
  try
  {
    string result = p.buildExpression()->getResult() + '.';
    FAIL() << "It should throw an exception: Missing token '.'";
  }
  catch (std::string &msg)
  {
    ASSERT_EQ("Missing token '.'", msg);
  }
}

#endif