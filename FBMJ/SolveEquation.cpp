/*
 * SolveEquation.cpp
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

不是tag里的题，面经之前好像也没看到过，利口留思零变种。

楼主一接电话一听是烙印就有点慌，沟通的时候烙印略有口音。 接着看到题目发现没见过就非常慌乱，变种是方程左右两边有括号。
总结来说还是自己太紧张，题目虽然没见过，看到题目之后一直在发蒙，（此时烙印一直在催我跟他说话），冷静下来之后思路很快就来了，
最后跌跌撞撞做完题目，感觉能不能过就随缘了。
 */

#include <string>

using namespace std;

/*
 * 1. consider w/o the parentheses
 */
// process the input string to make it the form of kx + b, we need to get k and b
// upgrade: if we need to add '(' and ')' in the equation
void processEquation(string input, int& i, int& k, int& b)
{
  int num = 0, sign = 1;
  while(i < input.length())
  {
    if(input[i] == '+')
    {
      sign = 1;
      i++;
    }
    else if(input[i] == '-')
    {
      sign = -1;
      i++;
    }
    else if(input[i] == '(')
    {
      int subk = 0, subb = 0;
      i++;
      processEquation(input, i, subk, subb);
      k += sign * subk;  // pitfull
      b += sign * subb;  // pitfull
      num = 0;
      sign = 1;
    }
    else if(input[i] == ')')
    {
      i++;
      return;
    }
    else
    {
      if(input[i] == 'x')
      {
        k += sign;
        i++;
      }
      else
      {
        while(i < input.size() && input[i] >= '0' && input[i] <= '9')
        {
          num = num * 10 + input[i++]-'0';
        }
        if(i < input.size() && input[i] == 'x')
        {
          k += num * sign;
          i++;
        }
        else
        {
          b += num * sign;
        }
      }

      // clean-up
      sign = 1;
      num = 0;
    }
  }
}

// we want to finalize the equation to the form of k1x + b1 = k2x + b2
// x = (b2 - b1)/(k1 - k2)
string solveEquation(string equation)
{
  if(equation.empty()) return "No solution";
  int equ = equation.find('=');
  int k1 = 0, b1 = 0, k2 = 0, b2 = 0, pos = 0;

  processEquation(equation.substr(0, equ), pos, k1, b1);

  pos = 0;
  processEquation(equation.substr(equ+1), pos, k2, b2);

  int deltk = k1 - k2, deltb = b2 - b1;
  if(deltk == 0 && deltb == 0) return "Infinite solutions";
  if(deltk == 0 && deltb != 0) return "No solution";

  int result = deltb/deltk;
  return "x = " + to_string(result);
}

// To execute C++, please define "int main()"
int main() {
  cout << solveEquation("x=x+2") << endl;  // No solution
  cout << solveEquation("x=x") << endl;    // Infinite solution
  cout << solveEquation("2x=x") << endl;   // x = 0
  cout << solveEquation("(2x+3x)-6x=x+2") << endl; // x = -1
  cout << solveEquation("3-2x-(-7x+1)+5+(-2x+(5x+3))=(x+(-x+2x+(-5x+3)))") << endl;
}


