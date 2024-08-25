#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void scale_vector(vector<int>& nums, int start, int end) {
    for (int i = start; i < end; ++i) {
        nums[i] = nums[i] * 2;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int mid = n / 2;

    thread t1(scale_vector, ref(nums), 0, mid);
    thread t2(scale_vector, ref(nums), mid, n);

    t1.join();
    t2.join();

    cout << "Scaled numbers: ";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
