#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int extractInt(const char src[], int& index, int& depth) {
    /*
    **************************Task-1***************************
    TODO: Given a string consisting of numeric charaters and English letters (e.g,"10{aaaa}"), return the integer value of the numeric charater(s) (e.g, 10 in this case) with recursive approach.

    Input:
        const char src[]: char array
        int& index: the index of array
        int& depth: the recursion depth
    Output:
        return the int value of the the numeral in the char array
    */
}


void repeatString(char str[], int repeat_times, char repeated_str[]) {
    /*
    **************************Task-2***************************
    TODO: implement a function to Recursively repeat the input string
    Input:
        char str[]: char array
        int repeat_times: the repeated times of str
        char repeated_str[]: the repeated char array to be return
    Output:
        void, str string is copied into char repeated_str
    */
}


void recursiveDecode(const char src[], int& index, char decoded[])
{
    /*
    **************************Task-3***************************
    TODO: implement a function to Recursively generate a new string by removing
          the braces and repeat the string inside braces.
    Input:
        char src[]: char array
        int& index: the index of array
        char decoded[]: the decoded string to be return
    Output:
        void, the decoded string is copied into char decoded[]
    */
}

// Driver program
int main()
{
    char s[1000]={};
    char decoded[1000] = {};
    int index = 0;

    //cout << "input string: " << endl;
    cin >> s;
    recursiveDecode(s, index, decoded);
    //cout << "output string: " << endl;
    cout << decoded << endl;
    return 0;
}
