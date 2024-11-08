#include "Recursive.h"
using namespace std;

template <typename Item_Type>
int linear_search(const vector<Item_Type>& items, const Item_Type& target, size_t pos_first) {
	//Base case: all vector positions have been checked	
	if (pos_first == items.size()) {
		return -1; //Target not found
	}

	//recursive call to check the next index
	int result = linear_search(items, target, pos_first + 1);

	//If target is found, in recursive call, return that index
	if (result != -1) {
		return result; //return the last position that target was found at
	}

	else if (items[pos_first] == target) {
		return pos_first; // target found at current position
	}

	return -1; //Target wasn't found
}

int main() {
	vector<int> items = { 1, 2, 3, 4, 3, 3, 1, 5, 2 };
	int target = 3;
	int last_position = linear_search(items, target, 0);
	if (last_position != -1) {
		cout << "Last occurence of " << target << " is at index: " << last_position << endl;
	}
	else {
		cout << target << " was not found in the vector." << endl;
	}
	return 0;
}
