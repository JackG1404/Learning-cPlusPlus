#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<double> fingerStrengthLogs;

	// Variable to control the loop for logging finger strength values
	char choice = 'y';

	// Loop to log multiple finger strength values
	while (choice == 'y' || choice == 'Y') {
		// Prompt user for finger strength value
		double strengthValue;
		//  Prompt user for finger strength value (kg)
		cout << "Enter finger strength value (kg): ";
		cin >> strengthValue;
		if (strengthValue <= 0) {
			cout << "Invalid input.\n";
			continue;
		}

		// Pushes the strength value to the back of the queue, so that it can be looped over later
		fingerStrengthLogs.push_back(strengthValue);
		cout << "Log another finger strength value? (y/n): ";
		cin >> choice;
	}
		
	// Display finger strength log history by iterating over the vector
	if (fingerStrengthLogs.size() > 0) {
		cout << "\nPrevious lifts:\n";
			// looping back over the list
			for (int i = 0; i < fingerStrengthLogs.size(); i++) {
				cout << i + 1 << ":" << fingerStrengthLogs[i] << "kg\n";
			}
	
	}
	else
	{
		cout << "\n No lifts logged";
	}

	return 0;
}