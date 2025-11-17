// Tic-Tac-Toe

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


const char pieces[] = { 'X', 'O' };

void instruction();
void displayBoard(const vector<char>& board);
int askNumber(string prompt);
void pieceToBoard(vector<char>& board, int index,char playerChoice);
void playerTurn(vector<char>& board, int playerChoice);
void computerTurn(vector<char>& board, int playerChoice);
void wonStatus(const vector<char>& board, bool& won);
bool squareOccupied(const vector<char>& board, int index);


int main()
{
    const int NUM_SQR = 9;
    bool won = false;
    int turnInt = -1;
    int turnCount = 0;
    string whoWon = "";
    vector<char> board(NUM_SQR, ' ');

    cout << "\t\tWelcome to playing tic-tac-toe\n";
    instruction();

 
    int playerEntered = askNumber("Please Enter 0-1 to get X or O assigned : ");
    char playerPiece = pieces[playerEntered];
    char compPiece = pieces[(playerEntered == 0 ? 1 : 0)];
    cout << "You Entered " << playerEntered << ". So the piece assigned to you is " << playerPiece<< endl;
    cout << "So the piece assigned to computer is " << compPiece << endl;

    while (turnCount < NUM_SQR && !won)
    {
        playerTurn(board, playerPiece);
        wonStatus(board, won);
        if (won) {
            whoWon = "player";
            break;
        }
        turnCount++;
        if (turnCount == NUM_SQR) 
        {
            whoWon = "Tie"; break;
        }
        


        computerTurn(board, compPiece);
        wonStatus(board, won);
        if (won) {
            whoWon = "Computer";
            break;
        }
        turnCount++;
        if (turnCount == NUM_SQR)
        {
            whoWon = "Tie"; break;
        }
        
        
    }

    if (whoWon != "Tie") {
        cout << whoWon << ", won the game!!" << endl;
    }
    else {
        cout << "Its a tie :)" << endl;
    }
    cout << "Thank you for playing the game!!\n";

    return 0;
}

void instruction() {
    cout << "\t\tChoose a box number to place your piece\n";
    cout << "\t\tTop left:\n\t\t1 -> 2 -> 3\n";
    cout << "\t\t4 -> 5 -> 6\n";
    cout << "\t\t7 -> 8 -> 9\n";
}


void displayBoard(const vector<char>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
               
        if(i%3 == 0)
        {
            cout << "\t\t\t \n";
            
        }
        cout << "| " << board[i] << " |";
        
    }
    cout << "\t\t\t \n";

}

int askNumber(string prompt)
{
    int numberEntered = 0;
    cout << prompt;
    cin >> numberEntered;
    return numberEntered;
}

void pieceToBoard(vector<char>& board, int index, char piece)
{
    //adding peice to board
    board[index-1] = piece;
    displayBoard(board);
}

void playerTurn(vector<char>& board, int playerChoice)
{
    int playerEntered=0;
    while (true) {
        cout << "Please choose a suare where piece is not placed" << endl;
        playerEntered = askNumber("Which sqr box would you like to choose? 1 - 9 : ");
        if (squareOccupied(board, playerEntered)) break;
        cout << "Please choose a square box that is not choosen\n";
    }
    pieceToBoard(board, playerEntered, playerChoice);
}

void computerTurn(vector<char>& board, int piece)
{
    srand(static_cast<unsigned int> (time(0)));
    int compChoice;
    while (true)
    {
        compChoice = (rand() % 9) + 1;
        if (squareOccupied(board, compChoice)) break;
    }
    cout << "Computer choose " << compChoice << endl;
    pieceToBoard(board, compChoice, piece);
}

void wonStatus(const vector<char>& board, bool& won)
{
    if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[0] == 'O' && board[1] == 'O' && board[2] == 'O'))
    {
        won = true;
    }else if ((board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O'))
    {
        won = true;
    }
    else if ((board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O'))
    {
        won = true;
    }
    else if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O'))
    {
        won = true;
    }
    else if ((board[2] == 'X' && board[4] == 'X' && board[6] == 'X') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
    {
        won = true;
    }
}

bool squareOccupied(const vector<char>& board, int index) {
    
    return board[index-1] == ' ' ? true : false;
}