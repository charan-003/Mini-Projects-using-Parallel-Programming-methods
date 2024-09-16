#include <iostream>
#include <omp.h>

using namespace std;

// Function to check if a number is odd
bool oddd(int i) {
    return i % 2 != 0;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int nums[n], output[n]; 

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];  
    }

    int outputIndex = 0;

    // Parallelizing the loop to find odd numbers
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        if (oddd(nums[i])) {
            // Using a critical section to ensure only one thread writes at a time
            #pragma omp critical
            {
                output[outputIndex] = nums[i];
                outputIndex++;
            }
        }
    }

    // Print the output array
    cout << "Output: ";
    for (int i = 0; i < outputIndex; ++i) {
        cout << output[i] << " ";  
    }
    cout << endl;

    return 0;
}

//opt/homebrew/opt/gcc/bin/g++-14 -fopenmp -o odd_openmp odd_openmp.cpp