//
//  main.cpp
//  FunctionAssignmentCSS1
//
//  Created by Sonia Arteaga on 11/7/20.
//

/*
Name: Brian Palomar
Last Modified: 11/18/21
Description: This program displays a covered up word (covered up with dashes) and prompts the user to guess the word by typing in one character at a time. Each time the character is not in the word, there is a missed try. The user can miss 8 times. The function prototypes and comments are pasted below.

Task: Build function implementations with given comments.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

const int NUM_WORDS = 5;
const int TOTAL_GUESSES = 8;
const string WORDS[5] = {"CHOCOLATE", "TURKEY", "PARKING", "SUNSET", "CLOUDY"};
// **********************************************************************
int generateRandomNumber();
// Summary: This function generates a random number from 0 up to
// (NUM_WORDS - 1), which in this case is from 0 to 4.
// Postconditions: A random number from 0 to 4 is returned.
// **********************************************************************
//
// **********************************************************************
string generateBlankString(int stringLength);
// Summary:This creates a string with stringLength number of dashes.
// For example if stringLength = 3, then this function returns the string
// containing "***".
// Preconditions: stringLength is >= 0
// Postconditions: A string containing stringLength number of dashes
// is returned.
// **********************************************************************
//
// **********************************************************************
bool foundMatch(string word, char userguess);
// Summary: This function returns true if the word contains at least 1
// character matching that in userguess. The function returns false
// otherwise.
// For example, if word = "tree" and userguess = 'r', then the function
// returns true.
// Preconditions: userguess is an alphabetical letter.
// Postconditions: This function returns true if the word contains the
// character userguess and false otherwise.
// **********************************************************************
//
// **********************************************************************
string updateGuessingWord(string word, char userguess, string guessWord);
// Summary: This function checks for matches of the character userguess in
// word and if there is a match, it sets the character in the same spot
// in guessWord. The function then returns guessWord with the changes.
// For example: if word = "tree", userguess = 'r' and guessWord = "----"
// Then guessWord would now look like "-r--" and this is the string the
// function would return.
// Preconditions: userguess is an alphabetical letter.
// Postconditions: guessWord is returned with userguess character revealed.
// **********************************************************************
//
// **********************************************************************
bool checkIfWordIsGuessed(string guessWord);
// Summary: This function looks for 1 or more dashes in the word. If it
// one or more dashes, then it returns false (because the word is still
// not completely guessed). Otherwise, the function returns true since
// there are no more dashes.
// Postconditions: Returns true if there are no dashes in the string
// guessWord and false otherwise.
// **********************************************************************
//

int main() {
    // Set up generator
    srand(static_cast<unsigned>(time(0))); // using this syntax removes
    // the warning
    
    // Create variables
    int randNum = 0, misses = 0;
    string guessingWord;
    char userGuess, repeat;
    bool foundMatchingChar = false;
    
    do{
        misses = 0;
        // create random number for new word
        randNum = generateRandomNumber();
        // Create string with dashes so that the word is hidden
        guessingWord = generateBlankString(WORDS[randNum].length());
        while(!checkIfWordIsGuessed(guessingWord) && misses != TOTAL_GUESSES)
        {
            cout << "Guess this word. You can only miss " << TOTAL_GUESSES << " times\n\n";
            cout << guessingWord << endl;
            // Get user's guess
            cout << "Enter a character. (You have " << (TOTAL_GUESSES - misses) << " missed guesses.)\n";
            cin >> userGuess;
            userGuess = toupper(userGuess); // Make char guess into uppercase
            // Check if that is a character in the string
            foundMatchingChar = foundMatch(WORDS[randNum], userGuess);
            if(foundMatchingChar)
            {
                // If the user guessed correctly then update the string
                guessingWord = updateGuessingWord(WORDS[randNum], userGuess, guessingWord);
            }
            else
            {
                // Add 1 to number of missed guesses
                misses++;
            }
        }
        if(TOTAL_GUESSES == misses)
        {
            cout << "Sorry you are out of missed guesses. The word was: \n"
            << WORDS[randNum] << endl;
        }
        else
        {
            cout << "You got the word!\n";
        }
        cout << "Would you like to try again?\nEnter y for yes\n";
        cin >> repeat;
    }while(tolower(repeat) == 'y');
    return 0;
}
int generateRandomNumber()
{
  int randomNumber = rand() % 5;
  return randomNumber;
}
string generateBlankString(int stringLength)
{
  assert(stringLength >= 0);
  string str="";
  for(int i = 0; i < stringLength; i++)
  {
    str+="-";
  }  
  return str;
}
bool foundMatch(string word, char userguess)
{
  bool boolean;
  int trueCounter = 0;
  int falseCounter = 0;

  assert(userguess >= 'A' && userguess <= 'Z');


  for(int z = 0; z < word.length(); z++)
  {
    if(word[z] == userguess)
    {
      trueCounter++;
    }
    else
    {
      falseCounter++;
    }
  }

  if(trueCounter >= 1 && falseCounter >= 0)
  {
    boolean = true;
  }
  else if(trueCounter == 0 && falseCounter >= 1)
  {
    boolean = false;
  }
  
  return boolean;
}
string updateGuessingWord(string word, char userguess, string guessWord)
{
  assert(userguess >= 'A' && userguess <= 'Z');
  for(int z = 0; z < word.length(); z++)
  {
    if(word[z] == userguess)
    {
      guessWord[z] = userguess;
    }
    else if (word[z] != '-')
    {
      word[z] = guessWord[z];
    }
    else
    {
      guessWord[z] = '-';
    }
  }
  
  cout << endl;
  return guessWord;
}
bool checkIfWordIsGuessed(string guessWord)
{
  bool numDashes = true;

  for(int z = 0; z < guessWord.length(); z++)
  {
    if(guessWord[z] == '-')
    {
      numDashes = false;
    }
  }
  
  return numDashes;
}
