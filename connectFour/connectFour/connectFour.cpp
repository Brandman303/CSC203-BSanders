#include <iostream>
using namespace std;

void displayGrid();//formatted string to display a connect four grid
bool gameOver(); //checks if there is a winner
void createGridRow(); //this is used by displayGrid to produce a row
void dropDisk(); // this lets player drop a disk in chosen column
void startingGridArray(int grid[][7], int const rows, int const cols);
void printGridArray(int grid[][7], int const rows, int const cols);// to traverse the array and print the grid to see if game is working correctly
int main() {
	int numDisks = 42;
	int const rows = 6;
	int const cols = 7;
	int grid[rows][cols];
	startingGridArray(grid, rows, cols);
	printGridArray(grid, rows, cols);
	
	

}
void startingGridArray(int grid[][7], int const rows, int const cols) {
	
	for (int i = 0; i < rows; i++) { //builds the initial grid 0 are empty 1 is a disk
		for (int j = 0; j < cols; j++) {
			grid[i][j] = 0;
		}
	}
}
void printGridArray(int grid[][7], int const rows, int const cols) {

	for (int i = 0; i < rows; i++) { //prints out the initial grid
		for (int j = 0; j < cols; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
