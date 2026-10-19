// MyAquaponicsHelperApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

using namespace std;
//Constants that will be used in feed calculation
const int GREENS_FEED = 50;
const int VEGGIE_FEED = 100;
int main()
{
    string plantType; //Varaiable I want to sue in future if statement to automatically calculate feed needs without displaying both types. 
    int growingSpace;
    string growersName;
    int gallonsUsed;



    cout << "Hello welcome to my aquaponics helper program!\n";
    //Next lines are gathering info
    cout << "What is your name?" << endl;
    cin >> growersName;
    cout << "What are we growing today? Please type out either veggies or greens?" << endl;
    cin >> plantType;
    cout << "How many square feet of growing space are we using?" << endl;
    cin >> growingSpace;
    cout << "How many gallons of water are we using for this system?" << endl;
    //Output for information gathered from the user.
    cin >> gallonsUsed;
    cout << " " << endl;
    cout << "Hello " << growersName << "!" << endl;
    cout << "Today we are growing " << plantType << " in " << growingSpace << " square feet using " << gallonsUsed << " gallons of water." << endl;

    //This is my calcualation for feed per square foot of growing space.
    cout << "If you are growing veggies, you will need " << VEGGIE_FEED * growingSpace << " grams of feed." << endl;
    cout << "If you are growing greens, you will need " << GREENS_FEED * growingSpace << " grams of feed." << endl;


    return 0;
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
