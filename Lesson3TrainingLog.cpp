#include <iostream>
using namespace std;

// Entry point of the program
int main() {

    // Variable to control the loop for logging runs
    char choice = 'y';

    // Variables to track the number of runs, total pace, best pace, and worst pace
    int runCount = 0;
    double paceSum = 0.0;

    // Initialize best and worst pace with extreme values
    double bestPace = 0.0;
    double worstPace = 0.0;

    // Loop to log multiple runs
    while (choice == 'y' || choice == 'Y') {

        // Variables to hold distance and time for each run
        double distanceKm;
        double timeMinutes;

        //  Prompt user for distance and time
        cout << "Enter distance (km): ";
        cin >> distanceKm;

        cout << "Enter time (minutes): ";
        cin >> timeMinutes;

        // Validate input
        if (distanceKm <= 0 || timeMinutes <= 0) {
            cout << "Invalid input.\n";
            continue;
        }

        // Calculate pace
        double pace = timeMinutes / distanceKm;
        cout << "Pace: " << pace << " min/km\n";

        // Update statistics
        runCount++;
        paceSum += pace;

        // Update best and worst pace
        if (runCount == 1) {
            bestPace = pace;
            worstPace = pace;
        }
        else {
            if (pace < bestPace) bestPace = pace;
            if (pace > worstPace) worstPace = pace;
        }

        // Ask user if they want to log another run
        cout << "Log another run? (y/n): ";
        cin >> choice;
    }

    // Output summary statistics
    if (runCount > 0) {
        double averagePace = paceSum / runCount;

        cout << "\nSummary:\n";
        cout << "Runs logged: " << runCount << "\n";
        cout << "Average pace: " << averagePace << " min/km\n";
        cout << "Fastest pace: " << bestPace << " min/km\n";
        cout << "Slowest pace: " << worstPace << " min/km\n";
    }
    else {
        cout << "No runs logged.\n";
    }

    // Return 0 to indicate successful completion
    return 0;
}