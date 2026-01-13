#include <iostream>
using namespace std;

int main() {

    // Declare variables for distance and time, and a choice variable for future use
    double distanceKm;
    double timeMinutes;
    char choice = 'y';

    // Loop to allow multiple pace calculations (validates for upper and lower case 'y')
    while (choice == 'y' || choice == 'Y') {

        // Prompt user for input of their distance
        cout << "Enter distance (km): ";
        cin >> distanceKm;

        // Prompt user for input of their time
        cout << "Enter time (minutes): ";
        cin >> timeMinutes;

        // Validate input, makes sure that distance and time are positive numbers
        if (distanceKm <= 0 || timeMinutes <= 0) {
            cout << "Distance and time must be positive numbers.\n";

            // Lets the user continue to the next iteration of the loop, in the case of an error
            continue;
        }

        // Calculate pace
        double pace = timeMinutes / distanceKm;

        // Output the pace
        cout << "Pace: " << pace << " min/km.\n";

        // Outputs the pace, and gives feedback based on the pace
        if (pace < 5.0)
            cout << "Great pace!\n";
        else if (pace < 6.0)
            cout << "Good pace.\n";
        else
            cout << "Good for building endurance!\n";

        // Ask user if they want to calculate another pace
        cout << "Would you like to calculate another pace? (y/n): ";
        cin >> choice;

    }


    // Return 0 to indicate successful completion
    return 0;
}
