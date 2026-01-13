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