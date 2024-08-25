#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Apply the scaling directly in the loop
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
