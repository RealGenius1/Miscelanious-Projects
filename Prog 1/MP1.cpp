/*MP-1.cpp Spencer Thomas 9/27/2024
Code will take the number of donuts in normal and fancy, then also apple fritters
This will calculate the total price
Then it will take payment input than calculate change in the denominations required
*/
#include <iostream>
#include <iomanip>

using namespace std;


//Test 1; 1,1,1,3.33
int main() {
    //initialize many variables
    int dollars, quarters, dimes, nickels, pennies;
    int numNorm;
    int numFancy;
    int numFritters;
    double cost = 0;
    double payment = 0;
    double change = 0;
    //I have some constants for the costs cuz I don't want to remember them and *technically* it makes it better
    const double costNormOne = .75;
    const double costNormDozen = 7.99;
    const double costFancyOne = .85;
    const double costFancyDozen = 8.49;
    const double costFritter = 1.5;
    const double taxRate = 1.075;
    //get the inputs from the user
    cout << "Number of regular donuts ordered: ";
    cin >> numNorm;
    cout << "Number of fancy donuts ordered: ";
    cin >> numFancy;
    cout << "Number of apple fritters ordered: ";
    cin >> numFritters;
    //calculate cost by converting to dozens. It's a long line of code, but it works and I didn't want 5 lines of adding
    cost = (((double) ((int)numNorm / 12) * costNormDozen) + ((numNorm % 12) * costNormOne) + ((double)((int)(numFancy / 12) * costFancyDozen)) + ((numFancy % 12) * costFancyOne) + (numFritters * costFritter));
    // Calculate tax
    cost *= taxRate;
    //now I need to truncate and I'm gonna do it weird cuz it works and I can't just setprecision cuz I need the real number to be that way
    cost *= 100;
    cost = (int) (cost + .5);
    cost /= 100;
    //Now I need to print cost. using an inline if to make sure it has a leading 0
    cost > 0 ? cout << "Customer Owes $" << cost << endl : cout << "Customer Owes $0" << cost << endl;
    //Now I need payment input
    cout << "Customer Pays: $";
    cin >> payment;
    //now I do the change calculation
    change = (double) (payment - cost);
    //now I do the change given math. OH BOY HERE WE GO
    pennies = (change+.005) * 100;
    cout << pennies << endl;

    dollars = pennies / 100;
    pennies %= 100;
    cout << pennies << endl;
    quarters = pennies / 25;
    pennies %= 25;
        cout << pennies << endl;

    dimes = pennies / 10;
    pennies %= 10;
        cout << pennies << endl;

    nickels = pennies / 5;
    pennies %= 5;
        cout << pennies << endl;


    //Now It's time for printing, keep your seat buckled boys it's gonna be a close one
    if(change != 0){
        //Same concept as last time but this time for change
         change > 0 ? cout << "Change Owed is $" << change << " - " : cout << "Changed owed is $0" << change << " - ";
        if(dollars != 0){
            cout << dollars << " dollars";
        } if (quarters != 0){
            cout << ", " << quarters << " quarters";
        } if (dimes != 0){
            cout << ", " << dimes << " dimes";
        } if (nickels != 0){
            cout << ", " << nickels << " nickels";
        } if (pennies != 0){
            cout << ", " << pennies << " pennies";
        }
        cout << ".";
    } else {
        cout << "Exact payment recieved - no change owed.";
        return 1;
    }
    
}