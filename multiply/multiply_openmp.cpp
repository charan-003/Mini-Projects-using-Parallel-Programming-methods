#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int nums[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Parallelize the scaling operation
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        nums[i] = nums[i] * 2;
    }

    cout << "Scaled numbers: ";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// /opt/homebrew/opt/gcc/bin/g++-14 -fopenmp -o multiply_openmp multiply_openmp.cpp