#include<iostream>
#include<stdio.h>

using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

//Function to print board
void print_board(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << board[i][j];
            if(j<2){ cout << " | "; }
        }
        cout << endl;
        if(i<2){ cout << "--+---+--" << endl; }
    }
    cout << endl;
}

//Function to get user's choice X or O
void get_player_symbol(char &p1, char &p2){

    cout << "Player 1, choose your symbol (X or O): ";
    cin >> p1;

    if (p1 == 'x') p1 = 'X';
    if (p1 == 'o') p1 = 'O';

    while (p1 != 'X' && p1 != 'O'){
        cout << "Invalid input. Try again." << endl;
        cout << "Enter your choice 'X' or 'O': ";
        cin >> p1;

        if (p1 == 'x') p1 = 'X';
        if (p1 == 'o') p1 = 'O';
    }

    p2 = (p1 == 'X') ? 'O' : 'X';
}

//Taking game input from user
int user_input(char &player){
    int input;

    cout << "Enter the number where you want to mark " << player << " : ";
    cin >> input;

    while (input<1 || input>9){
        cout << "Invalid Input. Try again." << endl;
        cout << "Enter number between 1 and 9: " << endl;
        cin >> input;
    }

    return input;
}

//Function to display players move
bool give_user_input(int n, char p){
    while (n<1 || n>9){
        cout << "Invalid Position" << endl;
        return false;
    }

    int row = (n-1)/3;
    int col = (n-1)%3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken!" << endl;
        return false;
    }

    board[row][col] = p;

    return true;
}

int main(){
    char player1, player2;
    get_player_symbol(player1, player2);
    bool is_game_over = false;
    int turn = 0;           //even - Player1 , odd - Player2

    while(!is_game_over && turn < 9){
        print_board();

        char current_player = (turn%2 == 0) ? player1 : player2;
        
        int move = user_input(current_player);
        bool valid = give_user_input(move, current_player);

        if(!valid){
            continue;
        }

        turn++;
    }

    print_board();
    cout << "Game Over";
    
    return 0;
}