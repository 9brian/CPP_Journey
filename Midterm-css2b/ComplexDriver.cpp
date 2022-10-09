/*
Name: Brian Palomar
Last Modified: 10/6/2021
Description: Use of overloaded operators to add,
subtract and compare complex numbers
*/

#include "Complex.hpp"
#include <iostream>
using namespace std;
int main()
{
  Complex c1(1, 2.5), c2(1.5, 2), c3;
  cout << "c1 = " << c1 << endl;
  cout << "c2 = " << c2 << endl;
  // Test each math operator
  c3 = c1 + c2;
  cout << "c1 + c2 = " << c3 << endl;
  c3 = c1 - c2;
  cout << "c1 - c2 = " << c3 << endl;
  if(c1 == c2)
  {
    cout << "c1 and c2 are equal\n";
  }
  if(c1 != c2)
  {
    cout << "c1 and c2 are NOT equal\n";
  }
  return 0;
}