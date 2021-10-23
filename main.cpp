// author: nate alberti
// date: october 2021
// purpose: displays all prime numbers
// between a given high and low boundary

#include <iostream>
#include <cmath>
using namespace std;

int * initialize_unknown(int size);
int index_of_first_unknown(int size, int *array);
void cross_out(int size, int array[], int factor);
void circle_unknowns(int size, int array[]);
int * circled_numbers(int &size, int *array);
void print_array(int size, int *array, int low);
void set_boundaries(int &low, int &high);


int main() {

    bool again = false;

    do {

        // print welcoming information
        cout << "---------" << endl;
        cout << "THE SIEVE OF ERATOSTHENES" << endl;
        cout << "---------" << endl << endl;

        int low;
        int high;
        set_boundaries(low, high);

        // set up and initializations
        int size = high;
        int height = size;
        double sqrt_height = sqrt(height);
        int *numbers = initialize_unknown(size);
        int first_unknown = index_of_first_unknown(size, numbers);

        // find first unknown
        // while first unknown is less than sqrt of height
        // circle it
        // cross out the multiples of first unknown
        while(first_unknown < sqrt_height) {
            first_unknown = index_of_first_unknown(size, numbers);
            *(numbers+first_unknown) = 0;
            cross_out(size, numbers, first_unknown);
        }

        // first unknown is now greater than sqrt of height
        // circle all the remaining unknown numbers
        circle_unknowns(size, numbers);
        int *primes = circled_numbers(size, numbers);
        cout << endl << endl;

        // final output
        cout << "--FINAL ARRAY--" << endl;
        print_array(size, primes, low);

        // asking to loop
        cout << endl << "do you wish to repeat the program? (y/n): ";
        char c;
        cin >> c;
        if(c == 121) {
            again = true;
        }
        else {
            again = false;
        }
    } while(again);

    return 0;
}

// return the address to an array initialized to -1's
// except for index 0 and 1 which are initialized to 1's
int *initialize_unknown(int size) {
    int *array = new int[size];

    // crossing out 0 and 1
    *(array) = 1;
    *(array+1) = 1;

    // initializing rest of array to -1
    for(int i = 2; i < size; i++) {
        *(array+i) = -1;
    }

    return array;
}

// returns the index of the first unknown number (marked -1)
int index_of_first_unknown(int size, int *array) {
    for(int i = 0; i < size; i++) {
        if(*(array+i) == -1) {
            return i;
        }
    }

    return 999;
}

// crosses out (marks as a 1) every multiple of the given factor
// in the array
void cross_out(int size, int *array, int factor) {
    *(array+factor) = 0;
    for(int i = 2; i*factor < size; i++) {
         *(array+(i*factor)) = 1;
    }
}

// circles (marks as a 0) every number marked as an
// unknown (-1)
void circle_unknowns(int size, int *array) {
    for(int i = 0; i < size; i++) {
        if(*(array+i) == -1)
            *(array+i) = 0;
    }
}

// returns a new array of all the circled numbers
// (marked as 0) in the given array
int * circled_numbers(int &size, int *array) {
    int len = 0;
    for(int i = 0; i < size; i++) {
        if(*(array+i) == 0) {
            len++;
        }
    }

    int *primes = new int[len];

    int e = 0;
    for(int i = 0; i < size; i++) {
        if(*(array+i) == 0) {
            *(primes+e) = i;
            e++;
        }
    }

    size = len;
    return primes;
}

// prints the array index and the value of the element at that index
void print_array(int size, int *array, int low) {
    cout << endl;
    cout << "index\tprime" << endl;
    for(int i = (low); i < (size); i++) {
        cout << to_string(i) + "\t\t" + to_string(array[i]) << endl;
    }
}

void set_boundaries(int &low, int &high) {
    do {
        cout << "Enter a high boundary (positive integer): ";
        cin >> high;
    } while(high < 1);

    do {
        cout << "Enter a low boundary (positive integer): ";
        cin >> low;
    } while(low < 0 && low > high);

    cout << endl << endl;

}