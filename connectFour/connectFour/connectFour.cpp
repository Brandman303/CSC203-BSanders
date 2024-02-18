#include <iostream>

using namespace std;

void displayGrid(const int rows, const int cols, int grid[][7]);//formatted string to display a connect four grid
bool gameOverCheck(int grid[][7], int numDisk); //checks if there is a winner
void createGridRow(const int cols, int grid[][7]); //this is used by displayGrid to produce a row
void displayBottom();
void dropDisk(int grid[][7], int& numDisk, int colChoice, bool playerTurn); // this lets player drop a disk in chosen column
void startingGridArray(int grid[][7], int const rows, int const cols);
void printGridArray(int grid[][7], int const rows, int const cols);// to traverse the array and print the grid to see if game is working correctly

/*
* To-Do: 
* need to add a check for correctly entered numbers
* move numbers over to 1-7 instead of 0-6 so it is easier for the users
* implement display bottom
* cleanup comments and code
* add documentation.
*/
int main() {
	int numDisk = 42;
	int const rows = 6;
	int const cols = 7;
	int grid[rows][cols];
	int colChoice;
	bool gameOver = false; 
	bool playerTurn = true;
	startingGridArray(grid, rows, cols);
	displayGrid(rows, cols, grid);

	do {
		cout << "enter the column number you would like to drop your disk into: " << endl;
		cin >> colChoice;
		dropDisk(grid, numDisk, colChoice, playerTurn);
		createGridRow(cols, grid);
		gameOver = gameOverCheck(grid, numDisk); //could probably squeeze this into the conditional statement and eliminate gameOver variable
		if (gameOver != true) {
			playerTurn = !playerTurn;
		}
	} while (gameOver != true);
	cout << "Game Over" << endl;
	if (numDisk != 0) {
		(playerTurn == true) ? cout << "P1 wins!" : cout << "P2 Wins!";
	}
	else {
		cout << "Draw!";
	}
}

void displayGrid(const int rows, const int cols, int grid[][7]) {
	string line = "|";
	string space = " ";

	for (int i = 0; i < rows; i++) {
		cout << endl;
		for (int j = 0; j < cols; j++) {
			cout << line << space;
		}
		cout << line << endl;
	}
}

void createGridRow(const int cols, int grid[][7]) {
	string line = "|";
	string space = " ";
	string blue = "B"; //P1 is Blue
	string green = "G";//P2 is Green

	for (int i = 0; i < 6; i++) {
		cout << endl;
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 1) {
				cout << line << blue;
			}
			else if (grid[i][j] == 2) {
				cout << line << green;
			}
			else {
				cout << line << space;
			}
		}
		cout << line << endl;
	}

	 
}

void displayBottom();

void startingGridArray(int grid[][7], int const rows, int const cols) {
	
	for (int i = 0; i < rows; i++) { 
		for (int j = 0; j < cols; j++) {
			grid[i][j] = 0;

		}
	}
	//grid[1][0] = 1; this is a test to see where 1 will be
}

void printGridArray(int grid[][7], int const rows, int const cols) {

	for (int i = 0; i < rows; i++) { //prints out the initial grid
		for (int j = 0; j < cols; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void dropDisk(int grid[][7], int& numDisk, int col, bool playerTurn) {
	numDisk--;
	for (int i = 5; i >= 0; i--) {
		if (grid[i][col] < 1) {
			(playerTurn == true) ? grid[i][col] = 1 : grid[i][col] = 2;
			break;
		}
	}
}

bool gameOverCheck(int grid[][7], int numDisk) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != 0) {
				if (grid[i][j] == grid[i][j + 1] &&
					grid[i][j + 1] == grid[i][j + 2] &&
					grid[i][j + 2] == grid[i][j + 3]) {
					return true;
				}
			}
		}
	}
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 3; i++) {
			if (grid[i][j] != 0) {
				if (grid[i][j] == grid[i + 1][j] &&
					grid[i + 1][j] == grid[i + 2][j] &&
					grid[i + 2][j] == grid[i + 3][j]) {
					return true;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != 0) {
				if (grid[i][j] == grid[i + 1][j + 1] &&
					grid[i + 1][j + 1] == grid[i + 2][j + 2] &&
					grid[i + 2][j + 2] == grid[i + 3][j + 3]) {
					return true;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 6; j > 2; j--) {
			if (grid[i][j] != 0) {
				if (grid[i][j] == grid[i + 1][j - 1] &&
					grid[i + 1][j - 1] == grid[i + 2][j - 2] &&
					grid[i + 2][j - 2] == grid[i + 3][j - 3]) {
					return true;
				}
			}
		}
	}
	if (numDisk <= 0) {
		return true;
	}
	return false;
}
