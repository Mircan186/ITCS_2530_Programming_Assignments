// MyAquaponicsHelperApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
//Constants that will be used in feed calculation
const int GREENS_FEED = 50;
const int VEGGIE_FEED = 100;
int main()
{
    //Declaring Variable

    string plantType; //Varaiable I want to sue in future if statement to automatically calculate feed needs without displaying both types. 
    int growingSpace;
    string systemName;
    int gallonsUsed;
    int fishCount;
    double fishAvgWeight;
    double totalBiomas; //Based off fish count and fish weight. Derived value
    double veggieFeed;
    double greensFeed;
    ofstream  outData;



    cout << "Hello, welcome to my aquaponics helper program!\n" << endl; //friendly introduction banner
    cout << "What is the name of this aquaponic system?" << endl;
    getline(cin, systemName);
    cout << " " << endl;

    cout << systemName << "? Great name! Now let's get some information about your fish.\n" << endl;
    
    //Info about fish portion of app
    //Ask use for Fish count
    cout << "About how many fish are in your system currently?" << endl;
    if (cin >> fishCount);
    else {
        cout << "Please input a correct number of fish." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> fishCount;
    }
    //Ask user for fish weight.
    cout << "What is the average weight of the fish in your system?" << endl;

    if (cin >> fishAvgWeight);
    else {
        cout << "Please input a correct number for average fish weight." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> fishAvgWeight;
    }
    //Finds the total biomass for the system
    totalBiomas = fishAvgWeight * fishCount;


    //Info about plant portion of system

    cout << "What are we growing today? Please type out either veggies or greens?" << endl;
    cin >> plantType;
    cout << "How many square feet of growing space are we using?" << endl;
    if (cin >> growingSpace);
    else {
        cout << "Please enter a number for the amount of growing space." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> growingSpace;
    }
    cout << "How many gallons of water are we using for this system?" << endl;
    //Output for information gathered from the user.
    if (cin >> gallonsUsed);
    else {
        cout << "Please enter a number for gallons on water used." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> gallonsUsed;
    }
    cout << " " << endl;

    //This is my calcualation for feed per square foot of growing space.
    veggieFeed = VEGGIE_FEED * growingSpace;
    greensFeed = GREENS_FEED * growingSpace;
    cout << "If you are growing veggies, you will need " << veggieFeed << " grams of feed." << endl;
    cout << "If you are growing greens, you will need " << greensFeed << " grams of feed." << endl;

    cout << " " << endl;
    cout << " " << endl;
    //Output for the data collected and calculated.
    cout << fixed << setprecision(2);
    cout << setw(30) << setfill('*') << systemName << " Report*********************" << endl;
    cout << "Fish in system:" << setw(38) << setfill('.') << fishCount << endl;
    cout << "Average weight of fish:" << setw(32) << setfill('.') << fishAvgWeight << endl;
    cout << "System's total biomass:" << setw(33) << setfill('.') << totalBiomas << endl;
    cout << "System is currently growing:" << setw(30) << setfill('.') << plantType << endl;
    cout << "Square feet used for growing:" << setw(24) << setfill('.') << growingSpace << endl;
    cout << "Total gallons of water used:" << setw(25) << setfill('.') << gallonsUsed << endl;
    cout << "Recommended amount of plant feed for veggies:" << setw(13) << setfill('.') << veggieFeed << endl;
    cout << "Recommended amount of plant feed for greens:" << setw(14) << setfill('.') << greensFeed << endl;
    
    
    //Sending data to report.txt
    outData.open("report.txt");
    outData << setw(30) << setfill('*') << systemName << " Report*********************" << endl;
    outData << "Fish in system:" << setw(38) << setfill('.') << fishCount << endl;
    outData << "Average weight of fish:" << setw(29) << setfill('.') << fishAvgWeight << endl;
    outData << "System's total biomass:" << setw(30) << setfill('.') << totalBiomas << endl;
    outData << "System is currently growing:" << setw(30) << setfill('.') << plantType << endl;
    outData << "Square feet used for growing:" << setw(24) << setfill('.') << growingSpace << endl;
    outData << "Total gallons of water used:" << setw(25) << setfill('.') << gallonsUsed << endl;
    outData << "Recommended amount of plant feed for veggies:" << setw(10) << setfill('.') << veggieFeed << endl;
    outData << "Recommended amount of plant feed for greens:" << setw(11) << setfill('.') << greensFeed << endl;

    outData.close();

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

