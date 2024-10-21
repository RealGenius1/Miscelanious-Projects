/*MP-2.cpp Spencer Thomas 10/9/2024
TODO: Create description
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

char getInput(); //Get the input from the user
bool isWinningScore(int value); //checking if they won the game
bool isTurnPointsLost(int die1value, int die2value); //See if they rolled only one 1 
bool isGameScoreLost(int die1value, int die2value); //See if they rolled snake eyes
int rollDie(); //Literally just a random number generator to get a dice roll

void playerTurn(); //Just doing the player turn in an organized place
void computerTurn(); //Literally just doing the computer turn for you

//STATIC VARIBLES
//They might not need to be static, but it doesn't break anything to make them just in case
static int scoreHuman = 0; //humans score
static int scoreRobot = 0; //computers score
static int die1, die2; //the die rolls
static bool hasWon = false; //a boolean to check for winning for use of while loops
static char input; // just the input variable
static bool humanWon; //This is a boolean for use at the end to know who won.

int main() {

    srand(time(0)); //giving a unique seed for the random number generator every run

    //A slight pause before the game starts so it can wait for player readiness
    cout << "Please take your turn (Press any button to continue)";
    cin >> input;

    input = NULL; //slight thing for a basic if check

    //the game loop
    while(!hasWon){

        //an if check just so that it doesn't print the first time after I have the start check
        if (input != NULL){
            cout << endl <<"Now it is time for the player turn" << endl;
        }

        playerTurn();
        
        cout << endl << "Now it is time for the computer turn" << endl;

        computerTurn();
    }

    //CASE WHERE HUMAN WINS
    if(humanWon){
        cout << "CONGRATULATIONS -- YOU HAVE WON THE GAME WITH A SCORE OF: " << scoreHuman;
    }
    //CASE WHERE ROBOT WINS
    else {
        cout << "SO SORRY - You lost to the robot, your score: " << scoreHuman;
    }

}

//will return a defined input value out of the user based on many cases
char getInput() {
    char c;

    while(true){
        cout << "Please input 'R' to roll again or 'E' to end your turn: ";
        cin >> c;
        if(c == 'R' || c == 'r'){
            return 'r';
        } else if (c == 'E' || c == 'e'){
            return 'e';
        } else {
            cout << "Invalid input, please try again" << endl;
        }
    }

}

//Check if the passed value is >= 100
bool isWinningScore(int value) {
    return value >= 100;
}

//check if it rolled at least one 1
bool isTurnPointsLost(int die1value, int die2value) {
    return (die1value == 1 || die2value == 1);
}

//this will check if it rolled snake eyes
bool isGamePointsLost(int die1value, int die2value) {
    return (die1value == 1 && die2value == 1);
}

//rolls a random number between 1 and 6 and returns it
int rollDie() {
    //doing wonky math to make the random number be in range
    return 1 + rand() % (( 6 + 1 ) - 1);
}

//A function to handle the player turn
void playerTurn() {

    input = 'r'; //lets just make sure it's working for the for loop
    int tempScore = 0; //the tempscore to be added at the end (added at end in case you whammy)

    while(input == 'r'){

        die1 = rollDie();
        die2 = rollDie();
        cout << "You rolled " << die1 << " and " << die2 << endl;

        //CASE 1: LOSE THE GAME POINTS
        if (isGamePointsLost(die1, die2)){
            tempScore = scoreHuman = 0;
            cout << "SO SORRY YOU HAVE LOST EVERYTHING" << endl;
            return;
        }
        //CASE 2: YOU ONLY LOSE THE TURN
        else if(isTurnPointsLost(die1, die2)) {
            tempScore = 0;
            cout << "So sorry, but you have lost all points for this turn" << endl;
            return;
        } 
        //CASE 3: YOU DONT HAVE TO LOSE POINTS
        else {
            tempScore += die1 + die2;
        }

        input = getInput();
    }

    //at the end of the turn, update the actual score for the round
    scoreHuman += tempScore;
    
    //check if the human won the game
    if(isWinningScore(scoreHuman)){
        hasWon = humanWon = true;
    }
}

//A function to handle the computers AI
void computerTurn() {

    int tempScore = 0; //the tempscore to be added at the end (added at end in case you whammy)

    while(tempScore <= 20 && !isWinningScore(scoreRobot + tempScore)){

        die1 = rollDie();
        die2 = rollDie();
        cout << "The computer rolled " << die1 << " and " << die2 << endl;

        //CASE 1: YOU ONLY LOSE THE TURN
        if(isTurnPointsLost(die1, die2) && !isGamePointsLost(die1, die2)) {
            tempScore = 0;
            return;
        } 
        //CASE 2: LOSE THE GAME POINTS
        else if (isGamePointsLost(die1, die2)){
            tempScore = scoreRobot = 0;
            return;
        }
        //CASE 3: YOU DONT HAVE TO LOSE POINTS
        else {
            tempScore += die1 + die2;
        }
    }
    
    //at the end, update the game score
    scoreRobot += tempScore;

    //check if the robot won
    if(isWinningScore(scoreRobot)){
        hasWon = true;
        humanWon = false;
    }
}