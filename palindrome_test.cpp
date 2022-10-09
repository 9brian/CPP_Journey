/*
Name: Brian Palomar
Date Modified: 11/30/21
Description: Identifies if the user string is a palindrome through the use of the function of isPalindrome.
*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() 
{
  char choice = 'q'; // I&D choice
  string str; // Initializes str
  
  do
  {
    // Prompts the user to enter a string
    cout << "Enter your string\n";
    cin >> str;

    // Tells the user if their string is a palindrome
    if (isPalindrome(str) == true)
    {
      cout << str << " is a palindrome\n";
    }
    else
    {
      cout << str << " is not a palindrome\n";
    }

    // Asks the user if they would like to repeat the program
    cout << "Would you like to try again? Y-yes\n";
    cin >> choice;
    cout << endl;
  }while(choice == 'y' || choice == 'Y');
  
} 

bool isPalindrome(string str)
{
  int length = str.length();

  for(int i = 0; i < length; i++)
  {
    str[i] = tolower(str[i]);
  }

  for(int i = 0; i < length / 2; i++)
  {
    if(str[i] != str[length - 1 - i])
    {
      return false;
    }
  }
  return true;
}