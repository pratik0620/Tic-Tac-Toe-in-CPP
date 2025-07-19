#include<iostream>
#include<stdio.h>

using namespace std;

//Function to print board
void print_board(){
    int index[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << index[i][j];
            if(j<2){ cout << " | "; }
        }
        cout << endl;
        if(i<2){ cout << "--+---+--" << endl; }
    }
}

//Function to get user's choice X or O
char user_choice(){
    char choice;

    cout << "Enter your choice 'X' or 'O': ";
    cin >> choice;

    if (choice == 'x') choice = 'X';
    if (choice == 'o') choice = 'O';

    while (choice != 'X' && choice != 'O'){
        cout << "Invalid input. Try again." << endl;
        cout << "Enter your choice 'X' or 'O': ";
        cin >> choice;

        if (choice == 'x') choice = 'X';
        if (choice == 'o') choice = 'O';
    }

    return choice;
}

//Taking game input from user
int user_input(){
    int index[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int input;

    cout << "Enter the number where you want to mark: ";
    cin >> input;

    while (input<1 || input>9){
        cout << "Invalid Input. Try again." << endl;
        cout << "Enter number between 1 and 9: " << endl;
        cin >> input;
    }

    return input;
}

int main(){
    print_board();
    return 0;
}