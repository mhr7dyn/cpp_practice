#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int extractInt(const char src[], int &index, int &depth)
{
    int finalInt = 0;
    if (src[index] == '\0' || src[index] == '{') 
        return 0;
    else if (src[index] <= '9' && src[index] >= '0')
    {
        int digit = src[index] - '0';
        int nextDigit = extractInt(src, ++index, depth);
        depth++;
        finalInt = digit*pow(10,depth-2) + nextDigit;
        return digit*pow(10,depth-2) + nextDigit;
    }
    return finalInt;
}


void repeatString(char str[], int repeat_times, char repeated_str[])
{
    if(repeat_times < 1) 
        return;
    else
        repeated_str = strcat(repeated_str, str);
        repeatString(str, --repeat_times, repeated_str);
}


void recursiveDecode(const char src[], int &index, char decoded[])
{
    int depth = 1;
    
    if (src[index] == '}' || src[index] == '\0')
        return;
    
    if (src[index]>='0' && src[index]<='9')
        {
            char deep_src[1000]= {};
            int repeat_times = extractInt(src, index, depth);
            recursiveDecode(src, ++index, deep_src);
            repeatString(deep_src, repeat_times, decoded);
        }
    if ((src[index] >= 'a' && src[index] <= 'z') || 
        (src[index] >= 'A' && src[index] <= 'Z') )
        {
            //char currentChar = src[index];
            char currentChar[2];
            currentChar[0] = src[index];
            currentChar[1] = '\0';
            strcat(decoded,currentChar);  
        }
    recursiveDecode(src,++index,decoded);
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
