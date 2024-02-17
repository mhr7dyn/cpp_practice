#include <iostream>
using namespace std;

int main() {

    cout << "Welcome to your first C++ lab!" << endl;
    cout << "In this program, let's pretend you want to buy C++ learning materials." << endl;
    cout << "After fixing the codes below, compare this program output with the sample output to verify your work." << endl;
    cout << endl;

    int balance;
    cout << "Please enter the amount of money you have: ";
    cin >> balance;


    // TODO 1: Fix the line below. It currently will print "You have500HKD." if your input was 500.
    cout << "You have" << balance << "HKD." << endl;


    cout << endl;
    cout << "You decide to buy the textbook for 100 HKD." << endl;


    // TODO 2: Fix the line below. It currently does not subtract balance by 100 correctly.
    balance - 100;


    cout << "Remaining balance: " << balance << " HKD." << endl;
    cout << endl;


    // TODO 3: Fix the three lines below. They are not in the correct order.
    // Hint: Use Alt+Up/Down to move the current line(s) up or down.
    cout << "You decide to buy a notebook for 20 HKD." << endl;
    cout << "Remaining balance: " << balance << " HKD." << endl;
    balance = balance - 20;


    cout << endl;
    cout << "Because you need money, you would like to sell your pencil." << endl;
    int price;
    cout << "Please enter the price for your pencil: ";
    cin >> price;


    // TODO 4: Fix the if statement below.
    // If the pencil's price is higher than 50, the selling fails.
    // Hint: To edit the same word in multiple places, select the word and use Ctrl+D / Cmd+D.
    if (balance <= 50)
        cout << "The price " << balance << " is too high, you could not sell your pencil." << endl;
    else
        balance = balance + price;


    cout << "Remaining balance: " << balance << " HKD." << endl;
    cout << endl;


    cout << "Lastly, you try to buy a new laptop for 2000 HKD." << endl;


    // TODO 5: Fix the if statement below. 
    // Currently if the user does not have enough money, it is still subtracted.
    // Hint: C++ is strict with curly braces.
    if (balance < 2000)
        cout << "You don't have enough money left." << endl;
    else
        cout << "You have enough money left, you can purchase the laptop." << endl;
        balance = balance - 2000;


    cout << "Remaining balance: " << balance << " HKD." << endl;

    return 0;
}