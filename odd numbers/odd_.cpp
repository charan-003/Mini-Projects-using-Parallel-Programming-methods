#include <iostream>
#include <vector>

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
    for (int i = 0; i < n; ++i) {
        if (oddd(nums[i])) {
            output[outputIndex] = nums[i];  
            outputIndex++;
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
