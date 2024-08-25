#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n; // Taking input from the user

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> nums[i];
    }

    int sum1 = 0, sum2 = 0;
    int mid = n / 2;

 
    auto sum_first_half = [&nums, &sum1, mid]() {
        for (int i = 0; i < mid; ++i) {
            sum1 += nums[i];
        }
    };

    auto sum_second_half = [&nums, &sum2, mid, n]() {
        for (int i = mid; i < n; ++i) {
            sum2 += nums[i];
        }
    };

    thread t1(sum_first_half);
    thread t2(sum_second_half);

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    // Calculate the total sum
    int total_sum = sum1 + sum2;

    cout << "The sum of the numbers is: " << total_sum << endl;

    return 0;
}
