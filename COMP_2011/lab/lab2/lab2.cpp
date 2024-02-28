#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Welcome to your second C++ lab!" << endl;
    cout << "In this program, let us determine whether an input integer is a perfect square." << endl;
    cout << "If the input is negative, it is invalid." << endl;
    cout << "If the input is non-negative, it may or may not be a perfect square." << endl;
    cout << "If the input is a perfect square, let's find its non-negative integer square root and exit the program." << endl;
    cout << endl;

    /////////////////////////////////////////////////
    // TODO: Complete the code below
    // Your Code Here
    bool perfect_square = false;

    do {
    cout << "Please enter an integer number: ";
    int number; cin >> number;
    cout << number << endl;
    int root = sqrt(number);
    if (number < 0){
        cout << "The input number is invalid." << endl;
    }
    
    else
        if (root*root == number){
            perfect_square = true;
            cout << "The input number is a perfect square. Its non-negative integer square root is " << root << "." << endl;
            cout << "The program ends.";}
        else
            cout << "The input number is not a perfect square." << endl;
            cout << endl;



    }
    while (perfect_square != true);


    /////////////////////////////////////////////////
    
    return 0;
}