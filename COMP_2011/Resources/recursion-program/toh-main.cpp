#include <iostream> 	/* File: toh-main.cpp */	
using namespace std;	

void tower_of_hanoi(int, char, char, char);

int main()	
{
    int n;

    while (cin >> n)
    	tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}
