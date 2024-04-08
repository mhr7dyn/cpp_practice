#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int extractInt(const char src[], int &index, int &depth)
{
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

    //    if (!(src[index]=='0'||src[index]=='1'||src[index]=='2'||src[index]=='3'||src[index]=='4'||src[index]=='5'||src[index]=='6'||src[index]=='7'||src[index]=='8'||src[index]=='9'))
    //         return 0;
    if (src[index] == '\0')
    {
        return 0; //begore iy was 1
    }
    if (src[index] == '{')
    {

        return 0;
    }
    if (src[index] >= '0' && src[index] <= '9')
    {

        int x = src[index] - '0'; // store x

        int y = extractInt(src, ++index, depth);
        depth++; // depth only starts changing when  reach the end.
        // so in 1234.  4 is at depth 1. 3 at 2 , and so on.

        return y + x * pow(10, depth - 1);
    }

    return extractInt(src, ++index, depth);
}

void repeatString(char str[], int repeat_times, char repeated_str[])
{
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
    if (repeat_times < 1)
        return;
    else
    {
        repeated_str = strcat(repeated_str, str);
        
        repeatString(str, repeat_times - 1, repeated_str);
    }
}

void recursiveDecode(const char src[], int &index, char decoded[])
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
    int depth=0;
    if (src[index]=='\0')
    {
        return;
    }
    if (src[index]=='}')
    {
        return;
    }
    if (src[index]>='0' && src[index]<='9')
    {
        int x=extractInt(src,index,depth);
        //cout<<index<<endl;
        //abc2{dd}
        char inner_string[1000]={};
        recursiveDecode(src,++index,inner_string);
        repeatString(inner_string,x,decoded);



    }
    if (isalpha(src[index]))
    {
        strncat(decoded,&src[index],1);
    }
    recursiveDecode(src,++index,decoded);
    
}

// Driver program
int main()
{
    char s[1000] = {};
    char decoded[1000] = {};
    int index = 0;

   

    //cout << "input string: " << endl;
    cin >> s;
    recursiveDecode(s, index, decoded);

    //cout << "output string: " << endl;
    cout << decoded << endl;
    return 0;
}
