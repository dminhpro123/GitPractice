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

//checkwin
bool checkWin(string board[maxBoardX][maxBoardY], bool playerTurn){
	string tick;
	if (playerTurn) {
		tick = "X";
	}
	else {
		tick = "O";
	}
	for (int i=0; i < maxBoardX; i++){
    	if(board[i][0]==(board[i][1]) && board[i][1]==(board[i][2]))
    	{
    	    if(board[i][0].compare(tick)){
    	    	return true;
			}
    	}
	}
	
	for(int i=0; i < maxBoardY; i++)
 	{
    	if (board[0][i]==(board[1][i]) && board[1][i]==(board[2][i]))
    	{
    	    if(board[0][i].compare(tick)){
    	    	return true;
			}
    	}
 	}
 	if(board[0][0]==(board[1][1]) && board[1][1]==(board[2][2])){
    	if(board[0][0].compare(tick)){
    		return true;
		}
 	}

 	if(board[0][2]==(board[1][1]) && board[1][1]==(board[2][0]))
 	{
 	   if(board[0][2].compare(tick)){
    		return true;
		}
 	}
	return false;	
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
    		
			inputDir(x, y,chessBoard);
    		
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		
    		drawChessPlay(chessBoard);
			
			if(checkWin(chessBoard, playerTurn)){
    			cout<< player1Name + " win";
    			break;
			}
    		playerturn = !playerturn;
		}else if(!playerturn){
			cout << player2Name + " turn :\n";
			
    		int x;
    		int y;
    		
    		inputDir(x, y, chessBoard);
    		
    		playerTurn(chessBoard, x, y, playerturn);
    		cout << "\n";
    		
    		drawChessPlay(chessBoard);
    		
    		if(checkWin(chessBoard, playerTurn)){
    			cout<< player2Name + " win";
    			break;
			}
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