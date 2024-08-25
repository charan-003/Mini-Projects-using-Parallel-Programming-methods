#include <iostream>
#include <vector>
#include <thread>

using namespace std;

bool oddd(int i) {
    return i % 2 != 0;
}

void process_odd_numbers(vector<int>& nums, int start, int end, vector<int>& output) {
    for (int i = start; i < end; ++i) {
        if (oddd(nums[i])) {
            output.push_back(nums[i]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    vector<int> output1, output2;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int mid = n / 2;

    thread t1(process_odd_numbers, ref(nums), 0, mid, ref(output1));
    thread t2(process_odd_numbers, ref(nums), mid, n, ref(output2));

    t1.join();
    t2.join();

    output1.insert(output1.end(), output2.begin(), output2.end());

    cout << "Output: ";
    for (size_t i = 0; i < output1.size(); ++i) {
        cout << output1[i] << " ";
    }
    cout << endl;

    return 0;
}
