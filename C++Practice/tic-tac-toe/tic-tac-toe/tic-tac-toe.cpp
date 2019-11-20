#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int maxBoardX = 3;
const int maxBoardY = 3;

//draw chess when start
void drawChessStart(string board[maxBoardX][maxBoardY]) {
	for (int i = 0; i < maxBoardX; i++){
		for(int j = 0; j < maxBoardY; j++){
			board[i][j] = i+'0';
			board[i][j] += j+'0';
			cout << board[i][j] +"\t";
		}
		cout << "\n";
	}
}

//draw chess when play
void drawChessPlay(string board[maxBoardX][maxBoardY]){
	for (int i = 0; i < maxBoardX; i++){
		for(int j = 0; j < maxBoardY; j++){
			cout << board[i][j] +"\t";
		}
		cout << "\n";
	}
	
}

//update player turn	 
void playerTurn(string board[maxBoardX][maxBoardY], int x, int y, bool playerTurn){
	if(playerTurn){
		for (int i = 0; i < maxBoardX; i++){
			for(int j = 0; j < maxBoardY; j++){
				if(x == i && y == j){
					board[i][j] = "X";
				}
			}
		}
	}else{
		for (int i = 0; i < maxBoardX; i++){
			for(int j = 0; j < maxBoardY; j++){
				if(x == i && y == j){
					board[i][j] = "O";
				}
			}
		}
	}
	
}


//bool checkWin(string board[3][3]){
//	for (int i=0; i<=2; i++){
//    	if(board[i][0].compare(board[i][1]) && board[i][1].compare(board[i][2]))
//    	{
//    	    return true;
//    	}
//	}
//	
//	for(int i=0; i<=2; i++)
// 	{
//    	if (board[0][i].compare(board[1][i]) && board[1][i].compare(board[2][i]))
//    	{
//    	    return true;
//    	}
// 	}
// 	if(board[0][0].compare(board[1][1]) && board[1][1].compare(board[2][2])){
//    	return true;
// 	}
//
// 	if(board[0][2].compare(board[1][1]) && board[1][1].compare(board[2][0]))
// 	{
// 	   return true;
// 	}
//	return false;	
//}

bool checkWinVertical(String board[maxBoardX][maxBoardY], int x, int y){
	for(int i = 0; i < maxBoardX; i++){
		
	}
	
}

void inputDir(int &x, int &y,string board[maxBoardX][maxBoardY]){
	string inputText;
	cout << "input your chess: ";
	cin >> inputText;
	
	//convert string to int
	stringstream degree(inputText);
	int var = 0;
	degree >> var;
	
	x = var/10;
	if(x < 0 || x >= maxBoardX){
		cout << "please input again, your direction must >=0 && <=2";
		inputDir(x, y, board);
	}
	
	y = var%10;
	if(y < 0 || y >= maxBoardY){
		cout << "please input again, your direction must >=0 && <=2";
		inputDir(x, y, board);
	}
//	if(board[x][y].compare("X") || board[x][y].compare("O") ){
//		cout << "please input again, your direction has been inputed";
//		inputDir(x, y, board);
//	}
}

int main()
{

    string chessBoard[maxBoardX][maxBoardY];
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
    	

	drawChessStart(chessBoard);
	
	while(varCount <9){
		if(playerturn){
    		cout << player1Name + " turn :\n";
    		
    		int x;
    		int y;
    		
//    		cout << "input x: ";
//    		cin >> x;
//    		cout << "input y: ";
//    		cin >> y;
			inputDir(x, y,chessBoard);
    		
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		
    		drawChessPlay(chessBoard);
//    		if(checkWin(chessBoard)){
//    			cout<< player1Name + " win";
//    			break;
//			}
    		playerturn = !playerturn;
		}else if(!playerturn){
			cout << player2Name + " turn :\n";
			
    		int x;
    		int y;
    		
//    		cout << "input x: ";
//    		cin >> x;
//    		cout << "input y: ";
//    		cin >> y;
    		
    		inputDir(x, y, chessBoard);
    		
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		
    		drawChessPlay(chessBoard);
//    		if(checkWin(chessBoard)){
//    			cout<< player2Name + " win";
//    			break;
//			}
    		playerturn = !playerturn;
		}
		
		cout << "\n";
		cout << "var count: " << varCount << "\n";
		
		if(varCount == maxBoardX*maxBoardY-1){
			cout<< "\t\tdraw!!!";
		}
		varCount++;		
	}		
	cout << "\n a";
}


