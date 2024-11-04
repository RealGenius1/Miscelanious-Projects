/*MP3.cpp Spencer Thomas TODO: Add Date
TODO: Create description
*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void clearBoard(char board[]);
bool hasThreeInARow(char board[], char playerMark);
int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
void XFirstGame(char board[], string player1Name, string player2Name, int &ties, int &p1Wins, int &p2Wins);
void OFirstGame(char board[], string player1Name, string player2Name, int &ties, int &p1Wins, int &p2Wins);
bool hasLegalMove(char board[]);

// grid size
const int n = 9;

// Player 1's mark
const char X = 'X';

// Player 2's mark
const char O = 'O';

int main()
{
    int numTies = 0;
    int numPlayer1Win = 0;
    int numPlayer2Win = 0;

    int input1;

    string player1Name;
    string player2Name;

    char grid[n];

    clearBoard(grid);

    cout << "Greetings Professor Falken, would you like to play a game?" << endl
         << "Name of Player 1: ";
    getline(cin, player1Name);
    cout << "Name of Player 2: ";
    getline(cin, player2Name);

    while (true)
    {
        XFirstGame(grid, player1Name, player2Name, numTies, numPlayer1Win, numPlayer2Win);
        displayGameStats(numTies, numPlayer1Win, numPlayer2Win);
        cout << "Nice game Professor Falken, would you like to play again? (any input to play again, -1 to quit)";
        cin >> input1;
        cin.clear();
        cin.ignore();
        if (input1 == -1)
        {
            break;
        }
        clearBoard(grid);

        OFirstGame(grid, player1Name, player2Name, numTies, numPlayer1Win, numPlayer2Win);
        displayGameStats(numTies, numPlayer1Win, numPlayer2Win);
        cout << "Nice game Professor Falken, would you like to play again? (any input to play again, -1 to quit)";
        cin >> input1;
        cin.clear();
        cin.ignore();
        if (input1 == -1)
        {
            break;
        }
    }
}

/*
Function to reset the grid at the end of each game
@param board game board to be reset after the calling of this function
*/
void clearBoard(char board[])
{
    for (int i = 0; i < n; i++)
    {
        board[i] = i + '1';
    }
}

/*
Function to check if there is a player has won the game by checking for 3 in a row
@param board game board to be checked for 3 in a row
@param playerMark the player that needs to be checked: 'X' or 'O'
@returns true if there is a win, false otherwise
*/
bool hasThreeInARow(char board[], char playerMark)
{
    // Check for diagonals
    if (board[6] == board[4] && board[4] == board[2] && board[6] == playerMark)
    {
        return true;
    }
    else if (board[0] == playerMark && board[0] == board[4] && board[4] == board[8])
    {
        return true;
    }
    // check for up down (0,3,6) & (1,4,7) & (2,5,8)
    for (int j = 0; j < 3; j++)
    {
        if (board[j] == playerMark && board[j] == board[j + 3] && board[j + 3] == board[j + 6])
        {
            return true;
        }
    }
    // check the lefts and rights (0,1,2) & (3,4,5) & (6,7,8)
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == playerMark && board[i] == board[i + 1] && board[i + 1] == board[i + 2])
        {
            return true;
        }
    }
    // end condition
    return false;
}

/*
Function to get the input of the player, it won't check whether the move is valid, just get the input
@param playerName the name of the player whose turn it is
@returns 1-9 based on the input of the player, which corresponds to a square on the board.
*/
int getPlayerInput(string playerName)
{
    cout << "Hello " << playerName << " please input what square you want to mark: ";
    int input;
    cin >> input;
    if (cin.fail() || input <= 0 || input > 9)
    {
        cin.clear();
        cin.ignore();
        cout << "Please input a valid number genius" << endl;
        getPlayerInput(playerName);
    }
    return input;
}

/*
Checks whether or not the given move is legal
@param board the current game board to be checked
@param location the desired game move
@returns true if there is no player mark in the given location, false otehrwise
*/
bool isLegalMove(char board[], int location)
{
    return board[location - 1] != X && board[location - 1] != O;
}

/*
Function that will check for a tie
@param board the current game board to be checked
@returns true if there is a legal move, false if the game is now tied
*/
bool hasLegalMove(char board[])
{
    for (int i = 0; i < n; i++)
    {
        if (board[i] != X && board[i] != O)
        {
            return true;
        }
    }
    return false;
}

/*
Places a mark on the board
@param board the current game board to recieve the mark
@param playerMark the players mark to indicate what player is playing 'X' or 'O'
@param location the location on the board that the mark needs to be placed
*/
void placeMarkOnBoard(char board[], char playerMark, int location)
{
    board[location - 1] = playerMark;
}

/*
Displays the game board for the players
@param board the current game board to be displayed
*/
void displayBoard(char board[])
{
    cout << endl
         << " " << board[6] << " | " << board[7] << " | " << board[8]
         << endl
         << "---+---+---"
         << endl
         << " " << board[3] << " | " << board[4] << " | " << board[5]
         << endl
         << "---+---+---"
         << endl
         << " " << board[0] << " | " << board[1] << " | " << board[2] << endl
         << endl;
}

/*
Displays the game stats for the players
@param ties the number of ties in this game session
@param player1Score the number of games player 1 has won this game session
@param player2Score the number of games player 2 has won this game session
*/
void displayGameStats(int ties, int player1Score, int player2Score)
{
    cout << "The game has been tied: " << ties << " times" << endl
         << "X has won: " << player1Score << " times" << endl
         << "O has won: " << player2Score << " times" << endl;
}

/*
Function to handle a game when X places first
@param board the game board that is to be played upon
@param player1Name the name of player 1
@param player2Name the name of player 2
@param ties a reference to an integer storing the number of ties this game session
@param p1Wins a reference to an integer storing the number of games player 1 has won this game session
@param p2Wins a reference to an integer storing the number of games player 2 has won this game session
*/
void XFirstGame(char board[], string player1Name, string player2Name, int &ties, int &p1Wins, int &p2Wins)
{
    int input;
    displayBoard(board);
    cout << "Welcome to the game of tic-tac-toe, " << player1Name << " will move first!" << endl;
    while (true)
    {
        // Player 1's turn section
        // Get the input of player 1, it's a loop to check for legal moves
        do
        {
            input = getPlayerInput(player1Name);
            if (!isLegalMove(board, input))
            {
                cout << "Hey genius, that wasn't a legal move, let's try this again" << endl;
            }
        } while (!isLegalMove(board, input));

        placeMarkOnBoard(board, X, input);

        displayBoard(board);
        if (hasThreeInARow(board, X))
        {
            cout << "CONGRATULATIONS! " << player1Name << " HAS WON THE GAME!!" << endl;
            p1Wins++;
            return;
        }

        if (!hasLegalMove(board))
        {
            cout << "TIE" << endl
                 << "A strange game. It ends in a tie. The only winning move is not to play."
                 << "How about a nice game of chess?" << endl;
            ties++;
            return;
        }

        // Player 2's turn section
        // Get the input of player 2, it's a loop to check for legal moves
        do
        {
            input = getPlayerInput(player2Name);
            if (!isLegalMove(board, input))
            {
                cout << "Hey genius, that wasn't a legal move, let's try this again" << endl;
            }
        } while (!isLegalMove(board, input));

        placeMarkOnBoard(board, O, input);

        displayBoard(board);
        if (hasThreeInARow(board, O))
        {
            cout << "CONGRATULATIONS! " << player2Name << " HAS WON THE GAME!!" << endl;
            p2Wins++;
            return;
        }

        if (!hasLegalMove(board))
        {
            cout << "TIE" << endl
                 << "A strange game. It ends in a tie. The only winning move is not to play."
                 << "How about a nice game of chess?" << endl;
            ties++;
            return;
        }
    }
}

/*
Function to handle a game when O places first
@param board the game board that is to be played upon
@param player1Name the name of player 1
@param player2Name the name of player 2
@param ties a reference to an integer storing the number of ties this game session
@param p1Wins a reference to an integer storing the number of games player 1 has won this game session
@param p2Wins a reference to an integer storing the number of games player 2 has won this game session
*/
void OFirstGame(char board[], string player1Name, string player2Name, int &ties, int &p1Wins, int &p2Wins)
{
    int input;
    displayBoard(board);
    cout << "Welcome to the game of tic-tac-toe, " << player2Name << " will move first!" << endl;
    while (true)
    {
        // Player 2's turn section
        // Get the input of player 2, it's a loop to check for legal moves
        do
        {
            input = getPlayerInput(player2Name);
            if (!isLegalMove(board, input))
            {
                cout << "Hey genius, that wasn't a legal move, let's try this again" << endl;
            }
        } while (!isLegalMove(board, input));

        placeMarkOnBoard(board, O, input);

        displayBoard(board);
        if (hasThreeInARow(board, O))
        {
            cout << "CONGRATULATIONS! " << player2Name << " HAS WON THE GAME!!" << endl;
            p2Wins++;
            return;
        }

        if (!hasLegalMove(board))
        {
            cout << "TIE" << endl
                 << "A strange game. It ends in a tie. The only winning move is not to play."
                 << "How about a nice game of chess?" << endl;
            ties++;
            return;
        }

        // Player 1's turn section
        // Get the input of player 1, it's a loop to check for legal moves
        do
        {
            input = getPlayerInput(player1Name);
            if (!isLegalMove(board, input))
            {
                cout << "Hey genius, that wasn't a legal move, let's try this again" << endl;
            }
        } while (!isLegalMove(board, input));

        placeMarkOnBoard(board, X, input);

        displayBoard(board);
        if (hasThreeInARow(board, X))
        {
            cout << "CONGRATULATIONS! " << player1Name << " HAS WON THE GAME!!" << endl;
            p1Wins++;
            return;
        }

        if (!hasLegalMove(board))
        {
            cout << "TIE" << endl
                 << "A strange game. It ends in a tie. The only winning move is not to play."
                 << "How about a nice game of chess?" << endl;
            ties++;
            return;
        }
    }
}