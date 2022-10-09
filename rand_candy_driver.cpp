/* 
Name: Brian Palomar
Last Modified: 10/21/21
Description: Program that displays random number 
of candies given out.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
  // Initalize max candies
  int candy = 100; 
  // Initializes candies taken variable
  int takenCandy = 0; 
  // Initializes people receiving candy counter
  int i = 0;

  // Generates random seed
  srand(time(0));

  // While loop that continues while candy bowl is full
  while(candy >= 0)
  { 
    // Generates random number
    takenCandy = rand() % 10 + 1;

    // If candy in bowl is less than number generated
    if (candy < takenCandy)
    {
      // Infinite while loop that iterates till random number is equal to candies in bowl
      while (candy != takenCandy)
      {
        takenCandy = rand() % 10 + 1;
      }
      // Updates candy variable
      candy = candy - takenCandy;
      // Outputs number of candies given out
      cout << takenCandy << " pieces of candy handed out\n";
      i++; // Updates people counter 
    }
    else
    {
      // Outputs number of candies given out
      cout << takenCandy << " pieces of candy handed out\n";
      // Updates candy variable
      candy = candy - takenCandy;
      i++; // Updates people counter
    }

    // Breaks while loop
    if(candy == 0)
    {
      break;
    }
  }
  
  // Outputs number of people that recieved candies
  cout << i << " people recieved candy\n" << endl;

  return 0;
}