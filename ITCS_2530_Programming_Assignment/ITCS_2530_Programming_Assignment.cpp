// MyAquaponicsHelperApp.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

// Enum for fish water type
enum FishWaterType { WARM_WATER = 1, COLD_WATER = 2 };

// Constants used in feed calculation
const double JUVENILE_WARM_FISH_FEED = 0.05;
const double ADULT_WARM_FISH_FEED = 0.025;
const double JUVENILE_COLD_FISH_FEED = 0.06;
const double ADULT_COLD_FISH_FEED = 0.015;
const int DAYS = 7;

// Function prototypes
void setColor(int color);
void welcomeBanner();
string getValidString(string prompt);
int getValidInt(string prompt, int minVal, int maxVal);
double getValidDouble(string prompt, double minVal, double maxVal);
double plantFeed(int growingSpace, int plantType);
void trackWeeklyFeed(double dailyFeed[], string dayNames[], int size);
void userMenu();
void saveReport(string systemName, int fishCount, double fishAvgWeight, double totalBiomass, string cropType, int growingSpace, int gallonsUsed, double weeklyTotal);

int main()
{
    setColor(9); // Light blue text
    welcomeBanner();

    // System info variables
    string systemName;
    int userFishType;
    FishWaterType waterType;
    int fishCount;
    double fishAvgWeight;
    double totalBiomass;

    int userPlantType;
    string cropType;
    int growingSpace;
    int gallonsUsed;

    double waterTemp;
    double waterPH;

    // Arrays for 7-day feeding tracker
    string dayNames[DAYS] = { "Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7" };
    double dailyFeed[DAYS] = { 0, 0, 0, 0, 0, 0, 0 };
    double weeklyTotal = 0.0;

    // Get system name
    systemName = getValidString("What is the name of this aquaponic system?\n");
    cout << "\n" << systemName << "? Great name! Let's get some information about your system!\n\n";

    // Get fish info
    userFishType = getValidInt("What type of fish are you growing? (1 = Warm-water, 2 = Cold-water): ", 1, 2);
    if (userFishType == 1) {
        waterType = WARM_WATER;
    }
    else {
        waterType = COLD_WATER;
    }

    fishCount = getValidInt("About how many fish are in your system currently? ", 1, 100000);
    fishAvgWeight = getValidDouble("What is the average weight of the fish (in grams)? ", 0.1, 50000.0);
    totalBiomass = fishAvgWeight * fishCount;

    // Get plant info
    userPlantType = getValidInt("\nWhat are we growing today? (1 = Vegetables, 2 = Greens): ", 1, 2);
    if (userPlantType == 1) {
        cropType = "Vegetables";
    }
    else {
        cropType = "Greens";
    }

    growingSpace = getValidInt("How many square feet of growing space are we using? ", 1, 10000);
    gallonsUsed = getValidInt("How many gallons of water are we using for this system? ", 1, 100000);

    // Get water quality info
    cout << "\nGreat! Now let's get some information about your water quality.\n";
    waterTemp = getValidDouble("What is the current water temperature (F) in your system? ", 32.0, 120.0);
    waterPH = getValidDouble("What is the current water pH in your system? ", 0.0, 14.0);

    bool runMenu = true;
    int userActivity;

    do {
        cout << endl;
        setColor(11);
        userMenu();
        setColor(9);

        userActivity = getValidInt("Enter your choice (1-6): ", 1, 6);
        cout << endl;

        switch (userActivity) {
        case 1: {
            int fishLifeStage = getValidInt("What life stage are your fish in? (1 = Juvenile, 2 = Adult): ", 1, 2);
            double neededFeed = 0.0;

            // Use enum in switch to calculate feed
            switch (waterType) {
            case WARM_WATER:
                if (fishLifeStage == 1) {
                    neededFeed = totalBiomass * JUVENILE_WARM_FISH_FEED;
                    cout << fixed << setprecision(2);
                    cout << "Warm-water juvenile fish need " << neededFeed << " grams of feed per day.\n";
                }
                else {
                    neededFeed = totalBiomass * ADULT_WARM_FISH_FEED;
                    cout << fixed << setprecision(2);
                    cout << "Warm-water adult fish need " << neededFeed << " grams of feed per day.\n";
                }
                break;

            case COLD_WATER:
                if (fishLifeStage == 1) {
                    neededFeed = totalBiomass * JUVENILE_COLD_FISH_FEED;
                    cout << fixed << setprecision(2);
                    cout << "Cold-water juvenile fish need " << neededFeed << " grams of feed per day.\n";
                }
                else {
                    neededFeed = totalBiomass * ADULT_COLD_FISH_FEED;
                    cout << fixed << setprecision(2);
                    cout << "Cold-water adult fish need " << neededFeed << " grams of feed per day.\n";
                }
                break;
            }
            break;
        }

        case 2:
            cout << fixed << setprecision(2);
            if (userPlantType == 1) {
                cout << "You are growing vegetables and need " << plantFeed(growingSpace, 1) << " grams of plant feed.\n";
            }
            else {
                cout << "You are growing greens and need " << plantFeed(growingSpace, 2) << " grams of plant feed.\n";
            }
            break;

        case 3:
            setColor(14); // Yellow for warnings
            // Check temp using enum
            if (waterType == WARM_WATER) {
                if (waterTemp < 70 || waterTemp > 85) {
                    cout << "Warning: Water temperature (" << waterTemp << " F) is outside the optimal range (70-85 F) for warm-water fish.\n";
                }
                else {
                    cout << "Water temperature is within the optimal range for warm-water fish.\n";
                }
            }
            else if (waterType == COLD_WATER) {
                if (waterTemp < 55 || waterTemp > 65) {
                    cout << "Warning: Water temperature (" << waterTemp << " F) is outside the optimal range (55-65 F) for cold-water fish.\n";
                }
                else {
                    cout << "Water temperature is within the optimal range for cold-water fish.\n";
                }
            }

            // Check pH
            if (waterPH < 6.4 || waterPH > 6.9) {
                cout << "Warning: Water pH (" << fixed << setprecision(1) << waterPH << ") is outside the optimal range (6.4 - 6.9).\n";
                while (waterPH < 6.4 || waterPH > 6.9) {
                    if (waterPH < 6.4) {
                        cout << "Add 1 ml of pH Up and remeasure.\n";
                    }
                    else {
                        cout << "Add 1 ml of pH Down and remeasure.\n";
                    }
                    waterPH = getValidDouble("Enter new pH reading: ", 0.0, 14.0);
                }
                cout << "Water pH is back within the optimal range!\n";
            }
            else {
                cout << "Water pH is within the optimal range for fish.\n";
            }
            setColor(9);
            break;

        case 4:
            // Add up the array before printing report
            weeklyTotal = 0.0;
            for (int i = 0; i < DAYS; i++) {
                weeklyTotal += dailyFeed[i];
            }

            setColor(10); // Green for report
            cout << "Generating report...\n\n";
            cout << fixed << setprecision(2);
            cout << "========================================================\n";
            cout << "           " << systemName << " - System Report\n";
            cout << "========================================================\n";
            cout << left << setw(40) << setfill('.') << "Fish in system" << right << setw(16) << fishCount << endl;
            cout << left << setw(40) << setfill('.') << "Average weight of fish (g)" << right << setw(16) << fishAvgWeight << endl;
            cout << left << setw(40) << setfill('.') << "System's total biomass (g)" << right << setw(16) << totalBiomass << endl;
            cout << left << setw(40) << setfill('.') << "Current crop type" << right << setw(16) << cropType << endl;
            cout << left << setw(40) << setfill('.') << "Growing space (sq ft)" << right << setw(16) << growingSpace << endl;
            cout << left << setw(40) << setfill('.') << "Water volume (gallons)" << right << setw(16) << gallonsUsed << endl;
            cout << left << setw(40) << setfill('.') << "Veggie feed needed (g)" << right << setw(16) << plantFeed(growingSpace, 1) << endl;
            cout << left << setw(40) << setfill('.') << "Greens feed needed (g)" << right << setw(16) << plantFeed(growingSpace, 2) << endl;
            cout << left << setw(40) << setfill('.') << "Weekly fish feed logged (g)" << right << setw(16) << weeklyTotal << endl;
            cout << setfill(' ') << "========================================================\n";

            saveReport(systemName, fishCount, fishAvgWeight, totalBiomass, cropType, growingSpace, gallonsUsed, weeklyTotal);
            setColor(9);
            break;

        case 5:
            trackWeeklyFeed(dailyFeed, dayNames, DAYS);
            break;

        case 6:
            cout << "Exiting My Aquaponics Helper. Happy growing!\n";
            runMenu = false;
            break;
        }
    } while (runMenu);

    setColor(7); // Back to normal white text
    return 0;
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void welcomeBanner()
{
    cout << "**************************************************\n";
    cout << "*                                                *\n";
    cout << "*          Welcome to My Aquaponics Helper       *\n";
    cout << "*                                                *\n";
    cout << "**************************************************\n\n";
}
// Get non-empty string input
string getValidString(string prompt)
{
    string text;
    cout << prompt;
    getline(cin, text);
    while (text == "") {
        cout << "Input cannot be empty. Please try again: ";
        getline(cin, text);
    }
    return text;
}
// Get valid integer input
int getValidInt(string prompt, int minVal, int maxVal)
{
    int num;
    cout << prompt;
    while (!(cin >> num) || num < minVal || num > maxVal) {
        cout << "Invalid input. Please enter a whole number between " << minVal << " and " << maxVal << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    return num;
}
// Get valid double input
double getValidDouble(string prompt, double minVal, double maxVal)
{
    double num;
    cout << prompt;
    while (!(cin >> num) || num < minVal || num > maxVal) {
        cout << "Invalid input. Please enter a number between " << minVal << " and " << maxVal << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    return num;
}
// Calculate plant feed
double plantFeed(int growingSpace, int plantType)
{
    const int VEGGIE_FEED = 100;
    const int GREENS_FEED = 50;
    if (plantType == 1) {
        return VEGGIE_FEED * growingSpace;
    }
    else if (plantType == 2) {
        return GREENS_FEED * growingSpace;
    }
    return 0.0;
}
// Record 7 days of fish feed into array
void trackWeeklyFeed(double dailyFeed[], string dayNames[], int size)
{
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        dailyFeed[i] = getValidDouble("Enter amount of feed (in grams) for " + dayNames[i] + ": ", 0.0, 10000.0);
        total += dailyFeed[i];
    }
    double avgFeed = total / size;
    cout << fixed << setprecision(2);
    cout << "\n--- Weekly Feeding Log ---\n";
    for (int i = 0; i < size; i++) {
        cout << dayNames[i] << ": " << dailyFeed[i] << " grams\n";
    }
    cout << "Total feed given over 7 days: " << total << " grams\n";
    cout << "Average daily feed: " << avgFeed << " grams\n";
}
void userMenu()
{
    cout << "Please select from the following options:\n";
    cout << "1. Calculate fish feed needs for your system\n";
    cout << "2. Calculate plant feed needs\n";
    cout << "3. Check water quality\n";
    cout << "4. View and save system report\n";
    cout << "5. Track weekly fish feeding\n";
    cout << "6. Exit program\n";
}
// Save report to report.txt
void saveReport(string systemName, int fishCount, double fishAvgWeight, double totalBiomass, string cropType, int growingSpace, int gallonsUsed, double weeklyTotal)
{
    ofstream outData;
    outData.open("report.txt");
    if (!outData) {
        cout << "Error saving report to file.\n";
        return;
    }
    outData << fixed << setprecision(2);
    outData << "========================================================\n";
    outData << "           " << systemName << " - System Report\n";
    outData << "========================================================\n";
    outData << left << setw(40) << setfill('.') << "Fish in system" << right << setw(16) << fishCount << endl;
    outData << left << setw(40) << setfill('.') << "Average weight of fish (g)" << right << setw(16) << fishAvgWeight << endl;
    outData << left << setw(40) << setfill('.') << "System's total biomass (g)" << right << setw(16) << totalBiomass << endl;
    outData << left << setw(40) << setfill('.') << "Current crop type" << right << setw(16) << cropType << endl;
    outData << left << setw(40) << setfill('.') << "Growing space (sq ft)" << right << setw(16) << growingSpace << endl;
    outData << left << setw(40) << setfill('.') << "Water volume (gallons)" << right << setw(16) << gallonsUsed << endl;
    outData << left << setw(40) << setfill('.') << "Veggie feed needed (g)" << right << setw(16) << plantFeed(growingSpace, 1) << endl;
    outData << left << setw(40) << setfill('.') << "Greens feed needed (g)" << right << setw(16) << plantFeed(growingSpace, 2) << endl;
    outData << left << setw(40) << setfill('.') << "Weekly fish feed logged (g)" << right << setw(16) << weeklyTotal << endl;
    outData << setfill(' ') << "========================================================\n";
    outData.close();
    cout << "Report saved to report.txt!\n";
}