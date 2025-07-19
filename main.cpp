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

int main(){
    print_board();
    return 0;
}