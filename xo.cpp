#include <iostream>
#include <string>
using namespace std;

// row & column number of the spaces
char structure[3][3] = { {'1','2','3'} , {'4','5','6'} , {'7','8','9'} };
int row, column;
char token = 'x';
bool tie = false;
// struct to store the players name
struct players {
	string player1name;
	string player2name;
} gamers;
// draw the game structure



void draw() {
	system("color 0E");
	cout << "\t\t======================================================================== \n";
	cout << "\t\t|                                                                      |\n";
	cout << "\t\t| ____________________________________________________________________ |\n";
	cout << "\t\t|                                                                      |\n";
	cout << "\t\t|                  Welcome to TIC TAC TOE GAME :)                      |\n";
	cout << "\t\t| ____________________________________________________________________ |\n";
	cout << "\t\t|                                                                      |\n";
	cout << "\t\t======================================================================== \n\n";
	// reads the players name
	cout << "Enter the name of the first player :";

	getline(cin, gamers.player1name);

	cout << "Enter the name of the second player :";

	getline(cin, gamers.player2name);

	//checks who will play first
	cout << gamers.player1name << " is Player1 (x)! \n";
	cout << gamers.player2name << " is Player2 (o)!  \n\n";

	// outputs the struct


 }

void gamestruct() {





	cout << "    |       |   \n";
	cout << " " << structure[0][0] << "  |  " << structure[0][1] << "    |  " << structure[0][2] << "\n";
	cout << "____|_______|_____\n";
	cout << "    |       |   \n";
	cout << " " << structure[1][0] << "  |  " << structure[1][1] << "    |  " << structure[1][2] << "\n";
	cout << "____|_______|_____\n";
	cout << "    |       |   \n";
	cout << " " << structure[2][0] << "  |  " << structure[2][1] << "    |  " << structure[2][2] << "\n";
	cout << "    |       |   \n\n";


}
void logic()
{
	int input ;

	if (token == 'x') {
		cout << gamers.player1name << " Please enter its place:";
		cin >> input;
	}
	if (token == 'o') {
		cout << gamers.player2name << " Please enter its place:";
		cin >> input;
	}
	// checks if invalid input;
	if (input < 1 || input > 9) {
		cout << "Invalid !! Please enter a number between (0 - 9).\n";
		logic(); // ask again for the input
		return;
	}

	row = (input - 1) / 3;
	column = (input - 1) % 3;

	  // checks if the selected spot is available
	if (structure[row][column] != 'x' && structure[row][column] != 'o') {
		structure[row][column] = token; // place the token
		token = (token == 'x') ? 'o' : 'x'; // Switch turn
	}
	else {
		cout << "\nThis place isn't empty!\n\n";
		logic();
		return;
	}
	

	}
/// set the conditions for players to win & wether the game is still going on or it's a draw
bool winlose() {
	// set the conditions for players to win the match

	for (int i = 0; i < 3; i++) {
		//conditions for horizental and vertical pairs
		if (structure[i][0] == structure[i][1] && structure[i][0] == structure[i][2] || structure[0][i] == structure[1][i] && structure[0][i] == structure[2][i]) {

			return true;
		}
	   }
	     // checks the diagonals
		if (structure[0][0] == structure[1][1] && structure[1][1] == structure[2][2] || structure[0][2] == structure[1][1] && structure[1][1] == structure[2][0]) {

			return true;
		}
	
	// checks if the game is still going on

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (structure[i][j] != 'x' && structure[i][j] != 'o') {

				return false;
			}
		}
	}
	tie = true;
	return false;
}
// reset the gameboard
void resetboard() {
	char origin = '1';

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			structure[i][j] = origin++; //reset the elements again
		}
	}
	tie = false; // reset the tie
	token = 'x'; // reset the game to the player1
}

int main() {

	char answer;
	draw();
     do{
		 resetboard();
		
	// keep iterating tell one of them win or the game is over
	while (!winlose() && !tie) {
		//outputs the structure of the game
		gamestruct();
		logic();
		
	}
	gamestruct();
	if (tie) {
		cout << "\n It's a draw :( !\n\n";
		
	}
	else if (token == 'x') {
		cout << gamers.player2name << " WINS !, Congratulations :)\n\n";

	}
	else {
		cout << gamers.player1name << " WINS !, Congratulations :)\n\n";

	}
	cout << "Do you want to Play again :) (y/n) :";
	     cin >> answer;
	     cout<<"\n";

	 } while (answer == 'y' || answer == 'Y');

	 cout << "\nThanks For Playing! GoodBye :) \n";

	return 0;
}
