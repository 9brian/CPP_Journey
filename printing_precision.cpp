// Line Comment
/*
Brian Palomar
Last Modified: 9/07/21
Description: Displays text onto the screen.
*/
// #include <iostream> //Input and output library
// using namespace std;

// int main()
// {
//   cout << "Hello World!" << endl;
//   cout << "This is my  first program" << endl;
//   cout << "This is a paragraph of text. In \n"
//        << "another line of text." << endl;
//   cout << "\"Hey!\", exlaimed Pooh" << endl;
//   return 0;
// }

#include <iostream>
using namespace std;

int main()
{
  cout.setf(ios::fixed);//turn on fixed notation
  cout.setf(ios::showpoint);//turn on - always display decimal point
  cout.precision(2);// use two decimals

  cout << 2.3456677 << endl;
  cout.precision(3); // 3 decimal places
  cout << 2.345667 << endl;

  return 0;
}


