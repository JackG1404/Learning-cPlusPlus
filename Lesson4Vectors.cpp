#include <iostream>
#include <vector>
using namespace std;

// Entry point of the program
int main() {

    
	// Vector to store paces
    vector<double> paces;
	// Variable to control the loop for logging runs
    char choice = 'y';

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

		// 'paces' is the vector (list) we made, '.' is the dot operator to access functions, 'push_back' adds an item to the end of the vector
        paces.push_back(pace);

        cout << "Log another run? (y/n): ";
        cin >> choice;
    }

	// Display run history by iterating over the vector
    if (paces.size() > 0) {
        cout << "\nRun history:\n";
        for (int i = 0; i < paces.size(); i++) {
            cout << i + 1 << ": " << paces[i] << " min/km\n";
        }
    }
    else {
        cout << "No runs logged.\n";
    }

	// Return 0 to indicate successful completion
    return 0;
}
