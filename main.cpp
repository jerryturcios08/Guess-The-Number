//
// Title : Guess the number (Version 3.0)
// Author: Jerry Turcios
// DLM   : 11/13/2017
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <limits>
#include <ctime>
using namespace std;

void youVsCom();  // Player guesses number
void comVsYou();  // Computer guesses player's number

int main() {

   // Data declarations
   int gameMode;

   do {

      do {

         system("clear");
         cout << "\n\n     GUESS THE NUMBER     \n\n";
         cout << "     By Jerry Turcios     \n";
         cout << "       Version  3.0     \n";
         cout << "\n\nSelect a game mode:\n\n";
         cout << "1 - Player guesses\n";
         cout << "2 - Computer guesses\n";
         cout << "3 - Quit\n\n";
         cout << "Game mode? ";
         cin >> gameMode;

         if (gameMode > 3 || gameMode < 1) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

         }
        
      } while (gameMode > 3 || gameMode < 1); // Loop prevents invalid inputs

      if (gameMode == 1) {

         // Calls function and activates player mode
         youVsCom();

      } else if (gameMode == 2) {

         // Calls function and activates computer mode
         comVsYou();

      } else {

         // Occurs if player quits
         system("clear");

      }

   } while (gameMode != 3);   // Loops program if player doesn't quit

   // Program stops when player quits
   return 0;

}

void youVsCom () {

   // Data declarations
   int realNumber;
   int guessNumber = 0;
   int numOfGuesses;
   int actionPrompt1;   // Needed for action prompt

   // Title with instructions
   system("clear");
   cout << "\n\n     PLAYER GUESSES     \n\n";
   cout << "Instructions:\n";
   cout << "Guess a number between 1 and 100.\n";
   cout << "If you are too low, it will tell you.\n";
   cout << "If you are too high, it will tell you.\n";
   cout << "Once you guess the right number, the\n";
   cout << "amount of times you guessed will be shown!\n\n";
   cout << "Press enter to begin...";
   cin.ignore();
   cin.get();  // Awaits for player to click enter

   do {
      
      // This generates a random number for the player to guess
      srand((unsigned)time(NULL));
      realNumber = rand() % 100 + 1;

      // Initializes it to 0
      numOfGuesses = 0;

      system("clear");

      // Beginning of the game
      while (guessNumber != realNumber) {
      
         do {
         
            // Shows how many guesses were made and the input 
            cout << "Number of valid guesses so far: " << numOfGuesses << endl;
            cout << "Guess a number between 1 and 100: ";
            cin >> guessNumber;

            if (guessNumber > 0 && guessNumber <= 100) {

               numOfGuesses++;   // Adds number to # of guesses
               system("clear");

            } else {
               
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(),'\n');

               system("clear");
                             
            }

         } while (guessNumber < 1 || guessNumber > 100); // Loop prevents invalid inputs

         if (guessNumber < realNumber) {

            // Displays that the number was too low
            cout << "The number " << guessNumber << " is too low!\n";

         } else if (guessNumber > realNumber) {

            // Displays that the number was too high
            cout << "The number " << guessNumber << " is too high!\n";

         } else {
            
            // Occurs if the player got the number correct
            cout << "The number " << guessNumber << " was the correct answer, congratulations!\n";
            cout << "It took you " << numOfGuesses << " attempts to guess it.\n\n";
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();

         }  

      }  // Keep looping until the right number is guessed

      do {

         // Occurs after player wins a game
         system("clear");
         cout << "Please select an option:\n\n";
         cout << "1 - Play again\n";
         cout << "2 - Main menu\n\n";
         cout << "Choice? ";
         cin >> actionPrompt1;

         if (actionPrompt1 > 2 || actionPrompt1 < 1) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

         }
         
      } while (actionPrompt1 > 2 || actionPrompt1 < 1);   // Loop prevents invalid inputs

      // If the player selects 1, the program will loop back to when the number
      // is generated. If the player selects 2, the program will go back to the
      // main menu in the int main function.

   } while (actionPrompt1 == 1); // Function keeps looping if player wants to play again

}

void comVsYou() {

   // Data declarations
   int guessNumberC;
   int numOfGuessesC;    // Number of guesses the computer made 
   int isItCorrect = 0;  // Used to verify if the computer guessed the right number
   int actionPrompt2; // Needed for action prompt for this mode

   // Beginning of program
   system("clear");
   cout << "\n\n        COMPUTER GUESSES        \n\n";
   cout << "Instructions:\n";
   cout << "The computer will try to guess a number\n";
   cout << "that you are thinking of between 1 and 100.\n";
   cout << "If the number is too low, you will tell it.\n";
   cout << "If the number is too high, you will tell it.\n";
   cout << "If the number is correct, you will tell it.\n";
   cout << "Then, the number of guesses the computer made\n";
   cout << "will be displayed after the game ends!\n\n";
   cout << "Press enter when you thought of a number...";
   cin.ignore();
   cin.get();  // Awaiting for player to click enter

   do {
      
      // Data declarations
      int low = 1;
      int high = 100;
      bool firstNum = true;   // Initializes to count first guess

      // Initializes the number of guesses to 0
      numOfGuessesC = 0;

      // Beginning of the game
      do {

         // The computer will make a guess with the statement below based on the
         // lowest number and also the highest number. If the computer fails to 
         // guess the player's number, it will generate a new one. 
         random_device rd;
         mt19937 gen(rd());
         uniform_int_distribution<> dis(low, high);

         // Assigns random number to guessNumberC
         guessNumberC = dis(gen); 

         do {

            if (firstNum)        // Increases count when it is the first number
               ++numOfGuessesC;  // because the computer already made a guess!!

            // Shows how many guesses were made and choice to make 
            system("clear");
            cout << "Number of guesses so far: " << numOfGuessesC << endl;
            cout << "The computer guesses the number " << guessNumberC << ".\n\n";
            cout << "Is the number correct?\n\n";
            cout << "1 - The number is too low\n";
            cout << "2 - The number is too high\n";
            cout << "3 - The number is correct!\n\n";
            cout << "Option: ";
            cin >> isItCorrect;

            if (isItCorrect > 3 || isItCorrect < 1) {

               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(),'\n');

            }

            firstNum = false;

            if ((isItCorrect > 0 && isItCorrect < 4) && isItCorrect != 3) {    

               numOfGuessesC++;  // Prevents count from increasing when there is an invalid input

            }

         } while (isItCorrect > 3 || isItCorrect < 1);

         if (isItCorrect == 1) {
            
            // Number is too low
            low = guessNumberC + 1; // Sets new low number for guessing range

         } else if (isItCorrect == 2) {

            // Number is too high
            high = guessNumberC - 1;   // Sets new high number for guessing range

         } else {

            // Number is correct
            system("clear");
            cout << "It took the computer " << numOfGuessesC << " tries to guess\n";
            cout << "the number you had thought of.\n\n";
            cout << "Press enter to continue...";
            cin.ignore();
            cin.get();

         }

      } while (isItCorrect != 3);   // Program loops until the correct number has been guessed
      
      do {

         // Occurs after player wins a game
         system("clear");
         cout << "Please select an option:\n\n";
         cout << "1 - Play again\n";
         cout << "2 - Main menu\n\n";
         cout << "Choice? ";
         cin >> actionPrompt2;
    
         if (actionPrompt2 > 2 || actionPrompt2 < 1) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

         }
         
      } while (actionPrompt2 > 2 || actionPrompt2 < 1);

      // If the player selects 1, the program will loop back to when the number
      // is generated. If the player selects 2, the program will go back to the
      // main menu in the int main function.

   } while (actionPrompt2 == 1); // Function keeps looping if player wants to play again

}
