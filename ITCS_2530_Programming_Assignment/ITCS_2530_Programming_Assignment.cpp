// MyAquaponicsHelperApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//hello

using namespace std;


//Constants that will be used in feed calculation
const int GREENS_FEED = 50;
const int VEGGIE_FEED = 100;
const double Juvenile_Warm_Fish_Feed = .05;
const double Adult_Warm_Fish_Feed = .025;
const double Juvenile_Cold_Fish_Feed = .06;
const double Adult_Cold_Fish_Feed = .015;
int main() {
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
	int fishType; //Variable to be used in if statement to determine what type of fish the user is growing in their system.
	double waterTemp; //Variable to be used in if statement to determine if the water temperature is within the correct range for the type of fish the user is growing.
	int userActivity; //Variable to be used in switch statement to determine what the user wants to do with the program.
	
    string cropType; //Variable to be used in if statement to determine what type of crop the user is growing in their system.
	double waterPH; //Variable to be used in if statement to determine if the water PH is within the correct range for the type of fish the user is growing.
	int fishLifeStage; //Variable to be used in if statement to determine what stage of life the fish are in and what type of feed they need.
    cout << "Hello, welcome to my aquaponics helper program!\n" << endl; //friendly introduction banner
    cout << "What is the name of this aquaponic system?" << endl;
    getline(cin, systemName);
    cout << " " << endl;

    cout << systemName << "? Great name! Lets get some information about your system!\n" << endl;

        //Info about fish portion of app
    cout << "What type of fish are you growing in your system? Type 1 for warm-water fish, 2 for cold-water fish." << endl;
    cin >> fishType;
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

    cout << "What are we growing today? Please enter 1 for Vegetables, 2 for greens." << endl;
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

    if (plantType == "1")
        cropType = "Vegetables";
	else (cropType = "Greens");
	cout << "Great! Now lets get some infomation about your water quality." << endl;
	cout << "What is the current water temperature in your system?" << endl;
	cin >> waterTemp;
	if (waterTemp);
	else {
		cout << "Please enter a number for water temperature." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> waterTemp;
	}
	cout << "What is the current water PH in your system?" << endl;

	cin >> waterPH;
	if (waterPH);
	else {
		cout << "Please enter a number for water PH." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> waterPH;
	}

    cout << "Please select from the following options:\n" << endl;
    cout << "1. Calculate fish feed needs for your system.\n" << endl;
    cout << "2. Calculate plant feed needs.\n" << endl;
    cout << "3. Check water quality\n" << endl;
    cout << "4. Write report\n" << endl;
	cin >> userActivity;


    switch (userActivity) {
    case 1:
        cout << "What life stage are your fish in? Type 1 for juvenile, 2 for adult." << endl;
        cin >> fishLifeStage;
        if (fishLifeStage == 1 && fishType == 1) {
            double juvenileWarmFishFeed = totalBiomas * Juvenile_Warm_Fish_Feed;
            cout << "You are growing warm-water fish in the juvenile stage and need " << juvenileWarmFishFeed << " grams of feed." << endl;
        }
        else if (fishLifeStage == 2 && fishType == 1) {
            double adultWarmFishFeed = totalBiomas * Adult_Warm_Fish_Feed;
            cout << "You are growing warm-water fish in the adult stage and need " << adultWarmFishFeed << " grams of feed." << endl;
        }
        else if (fishLifeStage == 1 && fishType == 2) {
            double juvenileColdFishFeed = totalBiomas * Juvenile_Cold_Fish_Feed;
            cout << "You are growing cold-water fish in the juvenile stage and need " << juvenileColdFishFeed << " grams of feed." << endl;
        }
        else {
            double adultColdFishFeed = totalBiomas * Adult_Cold_Fish_Feed;
            cout << "You are growing cold-water fish in the adult stage and need " << adultColdFishFeed << " grams of feed." << endl;
        }
        break;


    case 2:
        if (plantType == "1") {
            cout << "You are growing vegetables and need " << veggieFeed << " grams of feed." << endl;
        }
        else
            cout << "You are growing cool-season crops and need " << greensFeed << " grams of feed." << endl;
        break;
    case 3:
        if (fishType == 1) {
            if (waterTemp <= 70 || waterTemp >= 85) {
                cout << "Warning: The water temperature is outside the optimal range for warm-water fish." << endl;
            }
            else {
                cout << "The water temperature is within the optimal range for warm-water fish." << endl;
            }
            if (fishType == 2) {
                if (waterTemp <= 55 || waterTemp >= 65) {
                    cout << "Warning: The water temperature is outside the optimal range for cold-water fish." << endl;
                }
                else {
                    cout << "The water temperature is within the optimal range for cold-water fish." << endl;
                }
            }
            if (waterPH <= 6.5 || waterPH >= 7.0) {
                cout << "Warning: The water PH is outside the optimal range for fish." << endl;
            }
            else {
                cout << "The water PH is within the optimal range for fish." << endl;
            }
            break;
    case 4:
        cout << "Generating report..." << endl;

        cout << " " << endl;
        cout << " " << endl;
        //Output for the data collected and calculated.
        cout << fixed << setprecision(2);
        cout << setw(30) << setfill('*') << systemName << " Report*********************" << endl;
        cout << "Fish in system:" << setw(38) << setfill('.') << fishCount << endl;
        cout << "Average weight of fish:" << setw(32) << setfill('.') << fishAvgWeight << endl;
        cout << "System's total biomass:" << setw(33) << setfill('.') << totalBiomas << endl;

        cout << "System is currently growing:" << setw(33) << setfill('.') << cropType << endl;
        cout << "Square feet used for growing:" << setw(24) << setfill('.') << growingSpace << endl;
        cout << "Total gallons of water used:" << setw(25) << setfill('.') << gallonsUsed << endl;
        cout << "Recommended amount of plant feed for veggies:" << setw(13) << setfill('.') << veggieFeed << endl;
        cout << "Recommended amount of plant feed for greens:" << setw(14) << setfill('.') << greensFeed << endl;
    default:
        cout << "Invalid selection. Please try again." << endl;
        break;
        }
    }

    
    //Sending data to report.txt
    outData.open("report.txt");
    outData << setw(30) << setfill('*') << systemName << " Report*********************" << endl;
    outData << "Fish in system:" << setw(38) << setfill('.') << fishCount << endl;
    outData << "Average weight of fish:" << setw(29) << setfill('.') << fishAvgWeight << endl;
    outData << "System's total biomass:" << setw(30) << setfill('.') << totalBiomas << endl;
    outData << "System is currently growing:" << setw(33) << setfill('.') << cropType << endl;
    outData << "Square feet used for growing:" << setw(24) << setfill('.') << growingSpace << endl;
    outData << "Total gallons of water used:" << setw(25) << setfill('.') << gallonsUsed << endl;
    outData << "Recommended amount of plant feed for veggies:" << setw(10) << setfill('.') << veggieFeed << endl;
    outData << "Recommended amount of plant feed for greens:" << setw(11) << setfill('.') << greensFeed << endl;

    outData.close();

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu