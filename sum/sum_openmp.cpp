#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n, num;
    int sum = 0;

    cout << "Enter the number of elements: ";
    cin >> n; // Taking input for the number of elements

    int *nums = new int[n]; // Dynamically allocating array to store the elements

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> nums[i];
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += nums[i]; // Each thread adds its element to the sum
    }

    cout << "The sum of the numbers is: " << sum << endl;

    delete[] nums; // Freeing dynamically allocated memory
    return 0;
}


// /opt/homebrew/opt/gcc/bin/g++-14 -fopenmp -o sum_openmp sum_openmp.cpp
