//Hangman

#include <iostream>
#include <vector>
#include <String>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;
vector<string> assignWords(vector<string> wordVec);
void userGuess(char &userGuess);

int main()
{
	const int MAX_WRONG = 8;

	vector<string> words;
	words = assignWords(words);
	

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	int wrong = 0;
	string soFAR(THE_WORD.size(), '-');
	string used = "";

	cout << "/t/t Welcome to Hangman!\n";

	while ((wrong < MAX_WRONG) && (soFAR != THE_WORD))
	{
		cout << "\nYou tried " << wrong << " moves.";
		cout << "\nRemain moves left " << (MAX_WRONG - wrong) << ":)";
		cout << "\nLetter used : ";
		for (auto use : used)
		{
			cout << use;
		}
		cout << "\nThe word so far : " << soFAR << endl;
		char guess;
		userGuess(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "You already have guessed " << guess << endl;
			userGuess(guess);
		}
		
		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			for (int i = 0; i < THE_WORD.size(); i++)
			{
				if (THE_WORD[i] == guess)
				{
					soFAR[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " was a wrong guess";
			++wrong;
		}

	}
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou Lost";
	}
	else
	{
		cout << "\nYou Won!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	cout << "\n THANK YOU FOR PLAYING!!" << endl;

	return 0;
}

vector<string> assignWords(vector<string> wordVec) {
	wordVec.push_back("AMAZING");
	wordVec.push_back("JAPANESE");
	wordVec.push_back("GAMERS");
	return wordVec;
}

void userGuess(char &guess) {
	cout << "Whats your guess ? ";
	cin >> guess;
	guess = toupper(guess);
	return;
}