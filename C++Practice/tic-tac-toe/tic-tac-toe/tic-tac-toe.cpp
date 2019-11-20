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
	 
void playerTurn(string board[3][3], int x, int y, bool playerTurn){
	if(playerTurn){
		for (int i = 0; i <= 2; i++){
			for(int j = 0; j <= 2; j++){
				if(x == i && y == j){
					board[i][j] = "X";
				}
			}
		}
	}else{
		for (int i = 0; i <= 2; i++){
			for(int j = 0; j <= 2; j++){
				if(x == i && y == j){
					board[i][j] = "O";
				}
			}
		}
	}
	
}

int main()
{
	string chess;
    string chessBoard[3][3];
    string player1Name;
	string player2Name;
	bool playerturn = true;
	int varCount = 0;
    	
    cout << "Welcome To Tic-tac-toe game! Play with your way!\nIf you find any problem, please contact john.nguyen@gameloft.com\n";
    cout << "SELECT YOUR MODE (a - PLAY GAME, OTHERS - EXIT GAME):\n";
    string inputText;
    cin >> inputText;
	
	cout << "Enter Player 1 Name: ";
	cin >> player1Name;
	cout << "\n";
	cout << "Enter Player 2 Name: ";
	cin >> player2Name;   	
    	

	chessDrawStart(chessBoard);
	
	while(varCount <9){
		if(playerturn){
    		cout << player1Name + " turn :\n";
    		int x;
    		int y;
    		cout << "input x: ";
    		cin >> x;
    		cout << "input y: ";
    		cin >> y;
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		chessDraw(chessBoard);
    		!playerturn;
		}
		if(!playerturn){
			cout << player2Name + " turn :\n";
    		int x;
    		int y;
    		cout << "input x: ";
    		cin >> x;
    		cout << "input y: ";
    		cin >> y;
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		chessDraw(chessBoard);
    		!playerturn;
		}
		cout << "\n";
		cout << "var count: " << varCount;
		
	}
	
	
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
