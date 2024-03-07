// === Region: Project Overview ===
//
//  COMP2011 Spring 2024
//  PA1: Bulls and Cows Game
//
//
//  Your name:
//  Your ITSC email:           @connect.ust.hk
//
//  Note: This cpp file cannot be compiled directly
//  It will be copied and pasted to pa1_do_not_submit.cpp
//
//  Project TA: Peter ( cspeter@cse.ust.hk )
//
//  For code-level questions, please send a direct email to the above TA.
//  Asking questions with code blocks in Piazza may cause plagiarism issues
//  Usually, you will get the quickest response via a direct email.
//
// =====================================

/**
 * Task1
 *
 * function: countNumDigits counts the number of digits of the given number
 * @param number: an integer (e.g., 1234, 1145)
 *
 * Note: This function only counts the number of digits.
 * The other checking steps (e.g., contains duplication) will be done by other functions
 *
 * @return the valid number of digits of the given number
 * Otherwise, return -1.
 */
int countNumDigits(int number)
{

}

/**
 * Task2
 *
 * function: checkContainDigitZero checks whether a given number contains digit 0
 * @param number: an integer (e.g., 1234, 1045)
 *
 * Note: This function only checks whether a given number contains digit 0
 * The other checking steps will be done by other functions
 * 
 * return false if the number is negative
 *
 * @return true if the number contains at least one 0 digit
 * Otherwise, return false.
 */
bool checkContainDigitZero(int number)
{

}

/**
 * Task3
 *
 * function: checkDuplicateDigit checks whether a given number contains duplicate digits
 * @param number: an integer (e.g., 1234, 1145)
 *
 * Note: This function only checks whether a given number contains duplicate digits
 * The other checking steps will be done by other functions
 * 
 * For this function, you can assume that the input number is a non-negative integer
 *
 * @return true if the number contains duplicate digits
 * Otherwise, return false.
 */
bool checkDuplicateDigit(int number)
{
}

/**
 * Task4
 * 
 * function: countBullsCows finds the number of bulls and cows according to the
 * specified guess and answer numbers.
 * @param guess: the guess number to check
 * @param answer: the secret number to compare
 * @param bulls: the number of bulls (digits at the correct position)
 * @param cows: the number of cows (digits at the incorrect position)
 *
 * This function does not "return" a value, but instead will update the parameters
 * bulls and cows, which are passed by reference, with the calculated values.
 *
 * Note: We assume all the checking steps are done before calling this function,
 * so we don't need to repeat the checking steps here
 *
 */
void countBullsCows(int numDigits, int guess, int answer, int &bulls, int &cows)
{
}

