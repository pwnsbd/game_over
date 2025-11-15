#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	 
	int guessedNumber;
	int tryCount = 3;
	cout << "\t Guess my number \n" << endl;
	srand(static_cast <unsigned int>(time(0)));
	int randomNumber = rand() % 21 + 1;
	cout << "Whats your guess ? \nYou have 3 try to guess the number " << endl;
	cout << "Guess number between 1-21 : " << endl;

	while (tryCount > 0)
	{
		cin >> guessedNumber;
		if (randomNumber == guessedNumber)
		{
			cout << "\n you guessed it right!!" << endl;
			break;
		}
		else {
			tryCount--;
			cout << "The guess was wrong :(" << endl;
			cout << "Remaining guess left : " << tryCount << endl;
			cout << "Whats your guess ? \nYou have 3 try to guess the number " << endl;
			cout << "Guess number between 1-21 : " << endl;
		}
		
	}
	cout << "The Number was : " << randomNumber << endl;
	cout << "\n Thank you for playing the game!!" << endl;
	return 0;
}