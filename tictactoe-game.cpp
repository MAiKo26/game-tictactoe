// tictactoe-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm> 
#include <cctype>
#include <cstdlib> 
#include <ctime> 
using namespace std;

string input[3][3] = {
		{" ", " ", " "},
		{" ", " ", " "},
		{" ", " ", " "}
}; 
bool Playing = true;
string PlayingValue = "Y";
bool valid = false;
int Round = 0;
string PlayerChoiceXO = "";
bool GameOver;
string ComputerXO = "";


void drawBoard() {
	

	cout << "     |     |     \n";
	cout << "  "<<input[0][0]<<"  |  "<<input[0][1]<<"  |  "<<input[0][2]<<"  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  "<<input[1][0]<<"  |  "<<input[1][1]<<"  |  "<<input[1][2]<<"  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  "<<input[2][0]<<"  |  "<<input[2][1]<<"  |  "<<input[2][2]<<" \n";
	cout << "     |     |     \n";

	// Add Line Through drawBoard once GameOver " \x1B[9mThis text has a line-through effect.\x1B[0m"

}


void Input() {
	string PlayerInput;
	cout << "Give the coordinates of your move (From 1 Top Right until 9 Bottom Right ) :";
	bool invalid;

	do
	{
		invalid = false;
		cin >> PlayerInput;
		if (PlayerInput == "1" && input[0][0] == " ") input[0][0] = PlayerChoiceXO;
		else if (PlayerInput == "2" && input[0][1] == " ") input[0][1] = PlayerChoiceXO;
		else if (PlayerInput == "3" && input[0][2] == " ") input[0][2] = PlayerChoiceXO;
		else if (PlayerInput == "4" && input[1][0] == " ") input[1][0] = PlayerChoiceXO;
		else if (PlayerInput == "5" && input[1][1] == " ") input[1][1] = PlayerChoiceXO;
		else if (PlayerInput == "6" && input[1][2] == " ") input[1][2] = PlayerChoiceXO;
		else if (PlayerInput == "7" && input[2][0] == " ") input[2][0] = PlayerChoiceXO;
		else if (PlayerInput == "8" && input[2][1] == " ") input[2][1] = PlayerChoiceXO;
		else if (PlayerInput == "9" && input[2][2] == " ") input[2][2] = PlayerChoiceXO;
		else {
			std::cout << "Invalid input. Please enter a number between 1 and 9 and it needs to be empty :";
			invalid = true;
		}

	} while (invalid);

}

void ComputerPlay() {
	bool invalid;
	cout << "Computer Calculating his move ..." << endl;
	do
	{
		invalid = true;
		srand(static_cast<unsigned int>(std::time(0)));

		int randomX = rand() % 3 + 1;
		int randomY = rand() % 3 + 1;

		if (input[randomX][randomY] == " ") {
			input[randomX][randomY] = ComputerXO;
			invalid = false;
		}


		

	} while (invalid);
	

}

string capitalize(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);
	return result;
}


void CalculateResult() {
	if (GameOver && Round == 5) { 
	cout << "It's a Draw ! " << endl; 
	drawBoard();
	}
	else {
		int Row1counterX = 0;
		int Row2counterX = 0;
		int Row3counterX = 0;
		int Row1counterO = 0;
		int Row2counterO = 0;
		int Row3counterO = 0;
		int Diagonal1CounterX = 0;
		int Diagonal2CounterX = 0;
		int Diagonal1CounterO = 0;
		int Diagonal2CounterO = 0;

		// Diagonal Win

		for (int i = 0; i < 3; i++) {
			for (int j = 2; j == 0; j--) {
				if (input[i][j] == "X") {
					Diagonal2CounterX++;
				}
				if (input[i][j] == "O") {
					Diagonal2CounterO++;
				}
			}
			if (input[i][i] == "X") {
				Diagonal1CounterX++;
			}
			if (input[i][i] == "O") {
				Diagonal1CounterO++;
			}
		}

		// Same Line Win


		for (int i = 0; i < 3; i++) {
			if (input[0][i] == "X") {
				Row1counterX++;
			}
			if (input[1][i] == "X") {
				Row2counterX++;
			}
			if (input[2][i] == "X") {
				Row3counterX++;
			}
			if (input[0][i] == "O") {
				Row1counterO++;
			}
			if (input[1][i] == "O") {
				Row2counterO++;
			}
			if (input[2][i] == "O") {
				Row3counterO++;
			}
		}
		if (Row1counterX == 3 || Row2counterX == 3 || Row3counterX == 3) {
			cout << "PLAYER X WON CONGRATZ!" << endl;
			drawBoard();
			GameOver = true;
		}
		if (Row1counterO == 3 || Row2counterO == 3 || Row3counterO == 3) {
			cout << "PLAYER O WON CONGRATZ!" << endl;
			drawBoard();
			GameOver = true;
		}
	}

}


int main()
{

	while (Playing) {
		GameOver = false;

		do
		{
			cout << "Please Enter either X or O : ";
			cin >> PlayerChoiceXO;
			PlayerChoiceXO = capitalize(PlayerChoiceXO);
			if (PlayerChoiceXO == "X") {
				cout << "You chose X, so you start First" << endl ;
				ComputerXO = "O";
			}
			else if (PlayerChoiceXO == "O") {
				cout << "You chose O, so you play Second" << endl ;
				ComputerXO = "X";
			}
		} while (PlayerChoiceXO != "X" && PlayerChoiceXO != "O");

		cout << "==============================================" << endl ;
		cout << "Game Started" << endl ;
		cout << "==============================================" << endl ;
		cout << "" << endl;

		
		while (!GameOver) {
			Round++;
			cout << "Round " << Round << endl;
			if (Round == 5) {
				GameOver = true; 
				if (PlayerChoiceXO == "X") {
					drawBoard();
					Input();
				}
				else {
					ComputerPlay();
					drawBoard();
				}
			}else{
				if (PlayerChoiceXO == "X") {
					Input();
					drawBoard();
					CalculateResult();
					if (!GameOver) {
						ComputerPlay();
						drawBoard();
						CalculateResult();
					}
				}
				else {
					ComputerPlay();
					drawBoard();
					CalculateResult();
					if(!GameOver){
						Input();
						drawBoard();
						CalculateResult();
					}
				}
			}
			
			cout << "==============================================" << endl;
			

			
		}

		cout << Round;
		
		


		cout << "Do You want to play again ? Y or N :";
		cin >> PlayingValue;
		PlayingValue = capitalize(PlayingValue);

		if (PlayingValue != "Y" && PlayingValue != "N") {
			valid = true;
		}
		while (valid) {
			cout << "Please enter a Valid choice, Y or N :";
			cin >> PlayingValue;
			PlayingValue = capitalize(PlayingValue);
			if (PlayingValue == "Y" || PlayingValue == "N") {
				valid = false;
			}
		}

		if (PlayingValue == "Y") {
			Playing = true;
		}
		else if (PlayingValue == "N") {
			Playing = false;
		}
	}
	

	cout << "Goodbye ! Thank you for playing";


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
