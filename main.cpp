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

char user_choice(){
    char choice;

    cout << "Enter your choice 'X' or 'O': ";
    cin >> choice;

    while (choice != 'X' || choice != 'O'){
        cout << "Invalid input. Try again." << endl;
        cout << "Enter your choice 'X' or 'O': ";
        cin >> choice;
    }

    if (choice == 'x') choice = 'X';
    if (choice == 'o') choice = 'O';
    
    return choice;
}

int main(){
    print_board();
    return 0;
}