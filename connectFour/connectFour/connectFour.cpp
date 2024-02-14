#include <iostream>
using namespace std;
bool gameOverCheckHelper(int grid[][7], int counter, int row, int col);
void displayGrid();//formatted string to display a connect four grid
bool gameOverCheck(int grid[][7], int numDisk); //checks if there is a winner
void createGridRow(); //this is used by displayGrid to produce a row
void dropDisk(int grid[][7], int numDisk, int colChoice); // this lets player drop a disk in chosen column
void startingGridArray(int grid[][7], int const rows, int const cols);
void printGridArray(int grid[][7], int const rows, int const cols);// to traverse the array and print the grid to see if game is working correctly
int main() {
	int numDisk = 42;
	int const rows = 6;
	int const cols = 7;
	int grid[rows][cols];
	int colChoice;
	int gameOver = false;
	startingGridArray(grid, rows, cols);
	printGridArray(grid, rows, cols);
	do {
		cout << "enter the column number you would like to drop your disk into: " << endl;
		cin >> colChoice;
		dropDisk(grid, numDisk, colChoice);
		printGridArray(grid, rows, cols);
		gameOver = gameOverCheck(grid, numDisk); //could probably squeeze this into the conditional statement and eliminate gameOver variable
	} while (gameOver != true);
	cout << "Game Over";
	

}
void startingGridArray(int grid[][7], int const rows, int const cols) {
	
	for (int i = 0; i < rows; i++) { //builds the initial grid 0 are empty 1 is a disk
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

void dropDisk(int grid[][7], int numDisk, int col) { //maybe pass by reference for numDisk
	numDisk--; // I think this will need to be pass by reference or something else to directly change num disk
	for (int i = 5; i >= 0; i--) {
		if (grid[i][col] < 1) {
			grid[i][col] = 1;
			break;
		}
	}
}

bool gameOverCheck(int grid[][7], int numDisk) {
	int counter = 0;
	if (numDisk <= 0) {
		return true;
	}
	// Traverses and checks each row to check for four in a row horizontal.
	for (int i = 0; i < 6; i++) { //traverses row 
		for (int j = 0; j < 7; j++) { //traverses columns
			if (grid[i][j] != 0) {
				counter++;
				if (counter == 4) {//maybe a switch statement would be more appropriate for determining the row and check?
					return true;
				}
			}
		}
		counter = 0; // this resets the check for each row
	}
	//may need to hard check counter back to zero here
	//traverses each column to check for four in a row vertically
	for (int j = 0; j < 7; j++) { //traverse columns
		for (int i = 0; i < 6; i++) { //traverse rows
			if (grid[i][j] != 0) {
				counter++;
				if (counter == 4) {
					return true;
				}
			}
		}
		counter = 0;
	}
}
//may need to add col argument
bool gameOverCheckHelper(int grid[][7], int counter, int row, int col) { //recursively finds diagnol win
	if (row < 0 || col < 0) { //evaluate what should return, just stoping recursion for now
		return (counter == 4) ? true : false;
	}
	
	for (int i = row; i >= 0; i--) { // may need this in gameovercheck to intialize the loop then in recursive just move up and over 1 check 4 times
		for (int j = col; j >= 0; j--) {
			if (grid[i][j] != 0) {
				counter++;
				//row--;
				//col--; //moves up left then change bottom to check diagnol.
				gameOverCheckHelper(grid, counter, row, col);
			}
		}
	}
}

bool diagonalGameOverCheck(int grid[][7], int counter, int row, int col) { //needs prototype
	row--;
	col--;
	if (row < 0 || col < 0) {
		return (counter == 4) ? true : false;
	}
	if (counter == 4) {
		return true;
	}
	if (grid[row][col] != 0) {
		counter++;
		diagonalGameOverCheck(grid, counter, row, col);
	}
	else {
		return false;
	}

}
