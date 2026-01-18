#include <iostream>
#include <vector>

// This is my horrible attempt at bubble sort from memory

// okay it actually works lol

int main() {

	// hardcoded list of numbers to sort
	std::vector<int> NumList = {4, 33, 12, 2, 71, 16, 28, 99};

	// outer loop that runs 'n' times
	for (int i = 0; i < NumList.size(); i++) {
		// inner loop that compares numbers next to each other, and swaps them if they are out of order
		// each time the outer loop runs, the largest unsorted number is placed at the end of the list
		// so the inner loop can ignore the last 'i' amount of numbers which are already sorted
		// so the '-1 - i' in the loop condition
		// the '-1' is because we are comparing pairs of numbers, so we stop one number before the end
		for (int j = 0; j < NumList.size() - 1 - i; j++) {
			// compare adjacent numbers
			if (NumList[j] > NumList[j + 1])
			{
				// swap the numbers with temp variable
				int temp = NumList[j + 1];
				NumList[j + 1] = NumList[j];
				NumList[j] = temp;
			}
		}
	}
	// print sorted list by looping back through it and printing each element
	for (int i = 0; i < NumList.size(); i++) {
		std::cout << NumList[i] << std::endl;
	}
	return 0;
}