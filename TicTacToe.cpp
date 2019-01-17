#include <iostream>
using namespace std;

bool isWon(char, char[][3]); 
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

bool isWon(char C, char board[][3]) {

	if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && (board[0][0] != ' ')) { //checking contents of row 1
			return true;
		}
	
	else if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && (board[0][0] != ' ')) { //checking contents of column 1
			return true;
	}

	else if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && (board[1][0] != ' ')) { //checking contents of row 2
			return true;

	}

	else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && (board[0][1] != ' ')) { // checking contents of column 2
			return true;
		}

	else if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && (board[2][0] != ' ')) { // checking contents of row 3
		return true;
		}
	
	else if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && (board[0][2] != ' ')) { // checking contents of column 3
			return true;
		}
	

	// now time to do diagonals check
	else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' ')) { // checking contents diagonal L to R
			return true;
	}

	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != ' ')) { // checking contents of diagonal R to L
			return true;
		}
	else {
		return false;
	}
}

bool isDraw(char board[][3]) {
	if ((board[0][0] != ' ') && (board[0][1] != ' ') && (board[0][2] != ' ') && (board[1][0] != ' ') && (board[1][1] != ' ') && (board[1][2] != ' ') && (board[2][0] != ' ') && (board[2][1] != ' ') && (board[2][2] != ' ')) {
		return true;
	}
}

	void displayBoard(char board[][3]) {
	cout << "-------------\n";
	cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n";
	cout << "-------------\n";
	cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n";
	cout << "-------------\n";
	cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n";
	cout << "-------------\n";
	}

	void makeAMove(char board[][3], char C) {
			int thisRow;
			int thisColumn;
			cout << "Enter a row (0, 1, 2) for player " << C << " : ";
			cin >> thisRow;
			cout << "Enter a column (0, 1, 2) for player " << C << " : ";
			cin >> thisColumn;
			if ((board[thisRow][thisColumn] == 'X') || (board[thisRow][thisColumn] == 'O')) { //checking contents of row 1
				cout << "This cell is already occupied. Try a different cell.\n";
			}
			else {
				board[thisRow][thisColumn] = C;
		}
		}	
	// if space is occupied print This cell is already occupied. Try a different cell. then re-loop }	

int main() {
	
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}