#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	int ourNumber;
	int tryCount = 3;


	cout << "\t Computer Guesses your number \n" << endl;
	cout << "\t Lets choose a number for computer to guess. between 1-21 : ";
	cin >> ourNumber;;
	srand(static_cast <unsigned int>(time(NULL)));

	while (tryCount > 0)
	{
		cout << "Whats the guess of the computer? \n" << endl;
		cout << "Guessing number between 1-21 : ";
		
		int randomGuessed = rand() % 21 + 1;
		
		cout << "computers guessed number is : " << randomGuessed << endl;
		if (randomGuessed == ourNumber)
		{
			cout << "\n The guessed is right!!" << endl;
			break;
		}
		else {
			tryCount--;
			cout << "The guess was wrong :(" << endl;
			cout << "Remaining guess left : " << tryCount << endl;
		}

	}
	cout << "The Number was : " << ourNumber << endl;
	cout << "\n Thank you for playing the game!!" << endl;
	return 0;
}