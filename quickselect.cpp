/*
 * quickselect.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: user
 */
/*******************************************************************************
 * Name          : quickselect.cpp
 * Author        : Jason Salazar
 * Date          : 04/11/2022
 * Description   : Implements the quickselect algorithm found on page 160 in
 *                 Algorithms, 3e by Anany Levitin.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

size_t lomuto_partition(int array[], size_t left, size_t right) {
    // TODO
    // DO NOT change the function header in any way.
	int pivotValue = array[left];
	size_t e = left;
	for (size_t x = left + 1; x <= right; x++) {
		if (array[x] < pivotValue) {
			e += 1;
			swap(array[e], array[x]);
		}
	}
	swap(array[left], array[e]);
    return e;
}

int quick_select(int array[], size_t left, size_t right, size_t k) {
    // TODO
    // DO NOT change the function header in any way.
	if (k < 0 || k > right - left + 1) {
		return -1;
	}

 size_t index = lomuto_partition(array, left, right);

if(index == k + left - 1)
 return array[index];

if (index - left > k - 1)
	return quick_select(array, left, index - 1, k);
else
	return quick_select(array, index + 1, right, k - index + left - 1);

}

int quick_select(int array[], const size_t length, size_t k) {
    return quick_select(array, 0, length - 1, k);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <k>" << endl;
        return 1;
    }

    int k;
    istringstream iss;
    iss.str(argv[1]);
    if ( !(iss >> k) || k <= 0 ) {
        cerr << "Error: Invalid value '" << argv[1] << "' for k." << endl;
        return 1;
    }

    cout << "Enter sequence of integers, each followed by a space: " << flush;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    iss.clear();
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    int num_values = values.size();
    if (num_values == 0) {
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }
    // TODO - error checking k against the size of the input

    // TODO - call the quick_select function and display the result
int *i = &values[0];
int sizeOfValue = values.size();

if(sizeOfValue == 1 && k > sizeOfValue){
	cerr << "Error: Cannot find the smallest element " << k << " with only "
			<< sizeOfValue << " values. " << endl;
	return 1;
} else if (k > sizeOfValue) {

	cout << "Smallest element " << k << ": "
			<< quick_select(i, 0, sizeOfValue - 1, k) << endl;
}

   return 0;
}
