/* 
Name: Brian Palomar
Date Modified: 12/7/21
Description: Reads in the numbers in the file nums.txt and displays the smallest and largest number in the file, as well as the average number.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  ifstream inFile; 
  int largestNum = 0, smallestNum = 4990;
  double sum = 0, numCount = 0;
  int value;
  double avgNum;

  inFile.open("nums.txt"); // Opens file
  if(inFile.fail()) // Checks if file fails
  {
    cout << "Error opening file\n";
    exit(1);
  }
  while(inFile >> value) 
  {
    numCount++;  // Num counter     
    sum += value; // Increases Sum
   
    if(value > largestNum) // Updates largest num
    {
      largestNum = value;
    }

    if(value < smallestNum) // Updates smallest num
    {
      smallestNum = value;
    }
  }

  inFile.close(); // Closes file
  avgNum = sum / numCount; // Calculates avg num


  cout << "Largest Num  in txt.file is "
   << largestNum << endl;
  cout << "Smallest Num in txt.file is "
   << smallestNum << endl;
  cout << "Average Num in txt.file is " 
   << avgNum << endl;

  return 0;
} 