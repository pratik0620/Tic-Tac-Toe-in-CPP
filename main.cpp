#include<iostream>
#include<stdio.h>

using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

//Function to print board
void print_board(){
    cout << "====================" << endl;
    cout << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << board[i][j];
            if(j<2){ cout << " | "; }
        }
        cout << endl;
        if(i<2){ cout << "--+---+--" << endl; }
    }
    cout << endl;
    cout << "====================" << endl;
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

    cout << endl;
    cout << "Enter the number where you want to mark " << player << " : ";
    cin >> input;
    cout << endl;

    while (input<1 || input>9){
        cout << "Invalid Input. Try again." << endl;
        cout << "Enter number between 1 and 9: ";
        cin >> input;
        cout << endl;
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
        cout << endl;
        return false;
    }

    board[row][col] = p;

    return true;
}

//Function to check win
bool check_win(){
    //Check for row
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
    }
    
    //Check for column
    for(int j=0; j<3; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            return true;
        }
    }

    //Check for diagonal
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){ return true; }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){ return true; }

    return false;
}

//Function to check draw
bool check_draw(int n){
    if(n==9){
        return true;
    } else {
        return false;
    }
}

//Function to reset board
void reset_board(){
    char count = '1';
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = count++;
        }
    }
}

int main(){

    bool play = true;
    char ch;
    char player1, player2;
    bool is_game_over = false;
    int turn = 0;           //even - Player1 , odd - Player2

    while (play){
        get_player_symbol(player1, player2);

        while(!is_game_over && turn < 9){
            print_board();

            char current_player = (turn%2 == 0) ? player1 : player2;
            
            int move = user_input(current_player);
            bool valid = give_user_input(move, current_player);

            if(!valid){
                continue;
            }

            is_game_over = check_win();
            if (!is_game_over) {
                turn++;
                is_game_over = check_draw(turn);
            } 
        }

        print_board();

        cout << endl;
        cout << "Game Over" << endl;
        cout << endl;

        if(check_win()){
            cout << "Winner is " << ((turn%2 == 0) ? player1 : player2) << endl;
        } else if (check_draw(turn)) {
            cout << "It is a draw." << endl;
        }
        
        cout << endl;
        cout << "====================" << endl;
        cout << "Do you want to continue playing ? (Y/N): ";
        cin >> ch;
        if(ch == 'N' || ch == 'n') { play = false; }

        //Reset Everything
        reset_board();
        is_game_over = false;
        turn = 0; 
    }

    cout << endl;
    cout << "====================" << endl;
    cout << "Game Ended" << endl;
 
    return 0;
}