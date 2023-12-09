// tictactoe-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int space[3][3] = { {00,01,02},{10,11,12},{20,21,22} };



int main()
{


	string PlayerChoiceXO;
	do
	{
	cout << "Choose to start as X or O";
	cin >> PlayerChoiceXO;
	if (PlayerChoiceXO == "X") {
		cout << "You chose X";
	}
	else if (PlayerChoiceXO == "O") {
		cout << "You chose O";
	}
	} while (PlayerChoiceXO != "X" && PlayerChoiceXO != "O");

	cout << "Close the console";


}


void drawBoard() {
	cout << "    |    |    \n";
	cout << "    |    |    \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << "    |    |    \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << "    |    |    \n";
	cout << "    |    |    \n";
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
