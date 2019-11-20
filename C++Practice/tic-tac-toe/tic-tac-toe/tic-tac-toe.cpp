// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void chessDrawStart(string board[3][3]) {
	for (int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			board[i][j] = "a";
			cout << board[i][j] +"\t";
		}
		cout << "\n";
	}
}

void chessDraw(string board[3][3]){
	for (int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			cout << board[i][j] +"\t";
		}
		cout << "\n";
	}
	
}
	 
void player1Turn(string board[3][3], int x, int y){
	for (int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			if(x == i && y == j){
				board[i][j] = "X";
			}
		}
	}
}

void player2Turn(string board[3][3], int x, int y){
	for (int i = 0; i <= 2; i++){
		for(int j = 0; j <= 2; j++){
			if(x == i && y == j){
				board[i][j] = "O";
			}
		}
	}
}

int main()
{
    std::cout << "Hello World!\n";
    string chess;
    string chessBoard[3][3];
    chessDrawStart(chessBoard);
    bool playerturn = true;
    if(playerturn){
    	player1Turn(chessBoard, 1, 1);
    	cout << "\n";
    	chessDraw(chessBoard);
    	!playerturn;
	}else if(!playerturn){
		player1Turn(chessBoard, 2, 1);
		cout << "\n";
		chessDraw(chessBoard);
    	!playerturn;
	}
	cout << "\n";
	cout << "a";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
