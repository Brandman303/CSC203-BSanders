#include <iostream>
using namespace std;

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
	for (int i = 0; i < 6; i++) { //traverses grid and checks for four in a row 
		for (int j = 0; j < 7; j++) {
			if (grid[i][j] != 0) {
				counter++; //this is just if there is any 4 disks in the array which isnt right
				if (counter == 4) {//maybe a switch statement would be more appropriate for determining the row and check?
					return true;
				}
			}
		}

	}
}
