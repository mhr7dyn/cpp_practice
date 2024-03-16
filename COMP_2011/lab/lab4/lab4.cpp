#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

const int MAX_PATH_LENGTH = 100;

/* TODO TASK 2: Implement the tear_cards function. 
                The array card is the original array, card_torn is the array after tearing,
                org_size is the number of elements the array card has.
                For example, if card is [2, 3, 5, 7], after the function finishes, the card_torn array
                should be [2, 3, 5, 7, 2, 3, 5, 7] */
void tear_cards(const int card[], int card_torn[], int org_size){
    /* your code */
    for (int i=0; i<8; i++) {
        if (i<4) card_torn[i] = card[i];
        else card_torn[i] = card[i-4];
    }
}

/* TODO TASK 3: Implement the rotate_cards function. 
                The function should be able to finish the job of rotating the first 'size' elements 
                of the array 'card' for 'times' times.
                For example, rotate_cards(my_card, 7, 3) means rotate the first 7 elements of array
                my_card for 3 times */
void rotate_cards(int card[], int size, int times){
    /* your code */
    int temp, first_card;
    for (int i = 0; i < times; i++) {
        first_card = card[0];
        
        for (int j = 0; j < size-1; j++) {
            card[j] = card[j + 1];    
        }
        card[size - 1] = first_card;
    }
}

/* TODO TASK 4: Implement the throw_cards function. 
                The array card is the original array, card_final is the array after throwing,
                size is the number of cards after throwing, age is the age of the player. */
void throw_cards(const int card[], int card_final[], int size, int age){
    /* your code */
    
    bool Even = (age % 2 == 0);

    int removeIndex = Even ? 0 : 1;

    int j = 0; // Index for the final array (card_final)
    for (int i = 0; i <= size; i++) {
        // Handle edge case: if i == removeIndex, skip copying
        if (i == removeIndex) {
        continue;
        }
        card_final[j++] = card[i]; // Copy element and increment j for the next position
    }

}

/* OPTIONAL TODO: You can rewrite this rotate_remove function to enhance your understanding of 1D-array.
                However, there's no bonus for it ^^ Enjoy. */
void rotate_remove(int card[], int size){
    int left_card_num = size;
    while( left_card_num > 1 ){
        //move the top card to the bottom
        rotate_cards(card, left_card_num, 1);
        //remove the now top card
        left_card_num -= 1;
        for( int i = 0; i < left_card_num; i ++ ){
            card[i] = card[i + 1];
        }
    }
}

// --------------!! WARNING: DO NOT EDIT THIS FUNCTION !!--------------
void output_card(string step, const int card[], int size){
    cout << step << ": ";
    for( int i = 0; i < size; i ++ ){
        cout << card[i] << " ";
    }
    cout << endl;
}

int main(){
    int card[4];
    int year, age;
    cout << "Welcome to Lab4! Let's do some real magic!" << endl;
    cout << "Please enter the file you put your secrets in: ";
    char file_path[MAX_PATH_LENGTH];
    cin >> file_path;
    cout << file_path << endl;
    ifstream fin(file_path);

    //Step1: initialize by reading the player's input file
    /* TODO TASK 1: Read secret file from the player. */
    /* TODO TASK 1.1: You need to check if the file can be opened, if not, output the error message.*/
    /* your code */
    // Check if the file can be opened
    if (!fin) {
        cout << "-1";
        return 0;
    }


    /* TODO TASK 1.2: Read and initialize the array representing card, player's year of study and age
                    You should be aware that the cards, year and age may appear in random order.
                    In the array, the 0th element represent the number on the top card, 
                    1st element is the number on the second top card, etc. */
    char type_of_information;
    int counter = 0;
    int cardCounter = 0;
    int ageCounter = 0;
    char temp;
    while( fin >> type_of_information ) {
        /* your code */

        if (type_of_information == 'c')
        {
            for (int i = 0; i <= 3; i++) fin >> card[i];
        }
        else if (type_of_information == 'a') fin >> age;

        else fin >> year;
    } 
    
    fin.close();

    // --------------!! WARNING: DO NOT EDIT THE CODE BELOW !!--------------
    //Step2: tear the cards and duplicate
    int card_torn[8];
    tear_cards(card, card_torn, 4);
    output_card("torn", card_torn, 8);

    //Step3: rotate based on the player's year of study
    rotate_cards(card_torn, 8, year);
    output_card("rotate by year of study", card_torn, 8);

    //Step4: hide the fourth card
    int hidden_card = card_torn[3];
    int card_after[7] = {card_torn[0], card_torn[1], card_torn[2], card_torn[4], card_torn[5], card_torn[6], card_torn[7]};
    output_card("hide the fourth", card_after, 7);

    //Step5: if the player's age is even, throw away the first card; else throw away the second card
    int card_final[6];
    throw_cards(card_after, card_final, 6, age);
    output_card("thrown by age", card_final, 6);

    //Step6: rotate based on the magic spell
    rotate_cards(card_final, 6, 7);
    output_card("rotate by spell", card_final, 6);
    
    //Step7: move the top card to the bottom and then remove the now top card, until there's only one card left
    rotate_remove(card_final, 6);

    //Step8: compare the hidden card and the last card left
    if( hidden_card != card_final[0] )
        cout << "Your hidden card ["<< hidden_card << 
                "] and the last card [" << card_final[0] << "] do not match";
    else {
        cout << "Your hidden card ["<< hidden_card << 
                "] and the last card [" << card_final[0] << "] match perfectly!";
    }
    return 0;
}