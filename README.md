Just for me to add to daily and try to not be a bum of a "programmer"

# (1) First Program in C++ (12/01/2026)
~~~c++
#include <iostream>
using namespace std;

// Main function: Entry point of the program
int main() {

	// Ensure these are doubles, otherwise the division will be integer division
    double timeMinutes = 52;
    double distanceKm = 10;

	// Calculate and print the pace in minutes per kilometer
    cout << (timeMinutes / distanceKm) << "\n";

	// Return 0 to indicate successful completion
    return 0;
}
~~~
Hardcoding a pace and a time, which I then used to calculate the pace of the run.


# (2) Second Program in C++ (12/01/2026)
~~~c++
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
~~~
Added input and validation, and console feedback based on the pace, all within a loop so the user can log multiple runs.


# (3) Third Program in C++ (13/01/2026)
~~~c++
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
~~~
Added summary of best, worst, and average pace over several runs.
