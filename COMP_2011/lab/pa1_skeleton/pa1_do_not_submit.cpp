// === Region: Headers ===
// iostream is included for console printing.
// Other libraries are included for random number generation.
// Do not include extra header files.
// =======================
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

const int MAX_DIGITS = 9;


// Here, we copy and paste pa1.cpp (i.e., the file you need to submit)
#include "pa1.cpp" 


/* function generateRandomAnswer(int numDigits):
 *
 * Note: This function is given because the logic of generating a random answer with unique digits
 * is a little bit complicated
 *
 * A valid random guess needs to satisify the following criteria:
 *
 * (1) contains digits 1 to 9 (Note: 0 is excluded)
 * (2) contain no duplicate digits
 *
 * @return a randomly generated valid secret number. return -1 for any errors
 * (e.g., numDigits is invalid)
 */
int generateRandomAnswer(int numDigits)
{
    if (numDigits < 1 || numDigits >= 10)
        return -1;

    int i, j;
    int digits[MAX_DIGITS];

    // Step1: initialize the digit order array
    for (i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;

    // Step 2: Set the initial order of digits
    // For example, if the number of digits is 4
    // The initial array looks like this:
    //
    // Array index: 0 1 2 3 4 5 6 7 8
    // Digit value: 1 2 3 4 5 6 7 8 9
    // Order      : 1 2 3 4 0 0 0 0 0
    //
    // Note: We are going to shuffle the orders in the following loop

    int order = 1;
    for (i = 0; i < numDigits; i++)
    {
        digits[i] = order;
        order++;
    }

    // Step 3: Shuffle the digit orders
    // The initial order comes from the previous loop
    // We are going to shuffle the digits by SHUFFLE_COUNT
    // Any shuffle count is fine. 500 is a good number for this application
    const int SHUFFLE_COUNT = 500;
    int fromIndex, toIndex, tmp;
    for (i = 0; i < SHUFFLE_COUNT; i++)
    {
        fromIndex = rand() % MAX_DIGITS;
        toIndex = rand() % MAX_DIGITS;
        if (fromIndex != toIndex)
        {
            // swap the stored value
            tmp = digits[fromIndex];
            digits[fromIndex] = digits[toIndex];
            digits[toIndex] = tmp;
        }
    }

    // Debug: Print out the digit order
    // for (i=0; i<MAX_DIGITS; i++)
    //    cout << digits[i] << " ";
    // cout << endl;

    // Step 4:
    // Calculate the final secret number based on the digit order
    // Example:
    //
    // Array index: 0 1 2 3 4 5 6 7 8
    // Digit value: 1 2 3 4 5 6 7 8 9
    // Order      : 4 0 2 1 0 3 0 0 0  (after shuffling)
    //
    // Note: Order = 1 should be placed as the rightmost digit
    //
    // The corresponding secret number will be: 1634

    int num = 0;
    int digit, base;
    for (i = 0; i < MAX_DIGITS; i++)
    {
        order = digits[i];
        if (order > 0)
        {
            digit = i + 1; // index 0 refers to digit 1, etc.
            base = 1;
            for (j = 1; j < order; j++)
                base *= 10;

            // Example:
            // order = 1, base = 1
            // order = 2, base = 10
            // order = 3, base = 100
            // ...
            // order = 9, base = 10000000

            num += base * digit;
        }
    }

    return num;
}

// Necessary header files are included in pa1.h
// Note: using namespace std is included in pa1.h
//
// The main function
// Do not modify the main function
//
// You only need to write code and submit pa1.cpp
// Do not submit pa1_do_not_submit.cpp
//
// After the submission deadline, we will use another main function to grade your work

int main(int argc, char *argv[])
{
    srand(time(0));

    int answer, guess; 
    int numDigitsForAnswer, numDigitsForGuess;
    bool isGuessContainZeroDigit, isGuessContainDuplicateDigit;
    int bulls, cows;
    int numGuesses = 0;
    const bool TESTING_MODE = true; // testing mode is true by default

    if (TESTING_MODE)
    {
        // Note: You can change the answer and the number of digits manually to test different cases
        // Make sure they are correct
        answer = 6251;
        numDigitsForAnswer = 4;
        cout << "Testing mode activated. The secret number is " << answer << "." << endl;
    }
    else
    {
        numDigitsForAnswer = rand() % 9 + 1; // A random digit from 1..9 
        answer = generateRandomAnswer(numDigitsForAnswer);
    }

    cout << "Welcome to Bulls and Cows Game!" << endl;
    cout << "Try to guess a secret " << numDigitsForAnswer << "-digit number with no duplicates." << endl;
    cout << "For each guess, you will know the number of bulls and cows:" << endl;
    cout << "- Bulls refer to number of digits that are at the correct position;" << endl;
    cout << "- Cows refer to number of digits that are in the secret number, but not in the correct position." << endl;
    cout << "For example, if the secret number is 6251, a guess of 1236 results in 1B2C." << endl;
    cout << endl;

    while (true)
    {
        cout << "Make your guess (type 0 or a negative integer to exit): ";
        cin >> guess;
        if (guess <= 0)
            break;

        // Check1: The number of digits matches or not
        numDigitsForGuess = countNumDigits(guess);
        if ( numDigitsForGuess != -1 && numDigitsForAnswer == numDigitsForGuess ) 
        {
            cout << "Check1 PASSED: The number of digits matches" << endl; 
        }
        else 
        {
            cout << "Check1 FAILED: The number of digits does not match. The program exits" << endl;
            break;
        }

        // Check2: The number contains digit 0 or not
        isGuessContainZeroDigit = checkContainDigitZero(guess);
        if ( !isGuessContainZeroDigit )
        {
            cout << "Check2 PASSED: The guess does not contain 0 digit(s)" << endl;
        }
        else
        {
            cout << "Check2 FAILED: The guess contains 0 digit(s). The program exits" << endl;
            break;
        }

        // Check3: Check duplicate digit or not
        isGuessContainDuplicateDigit = checkDuplicateDigit(guess);
        if ( !isGuessContainDuplicateDigit  )
        {
            cout << "Check3 PASSED: The guess does not contain duplicate digit(s)" << endl;
        }
        else
        {
            cout << "Check3 FAILED: The guess contains duplicate digit(s). The program exits" << endl;
            break;
        }

        // Now, all the checking steps are complete, 
        // We can run the countBullsAndCows function
         ++numGuesses;
        countBullsCows(numDigitsForGuess, guess, answer, bulls, cows);
        if (guess == answer) {
            cout << "Congratulations! You have guessed the number in " << numGuesses << " attempts." << endl;
            break;
        }
        else {
            cout << "Your guess result is: " << bulls << "B" << cows << "C" << endl;
        }
        
    }

    return 0;
}
