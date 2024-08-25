#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

vector<int> nums; 
int num_threads;


void* operation(void* rank) {
    int thread_id = (long)rank;
    int n = nums.size();
    int elements_per_thread = n / num_threads;
    int start_index = thread_id * elements_per_thread;
    int end_index = start_index + elements_per_thread;

    // Handle extra elements for the last thread
    if (thread_id == num_threads - 1) {
        end_index = n;  // Last thread takes care of any remaining elements
    }

    for (int i = start_index; i < end_index; ++i) {
        nums[i] = nums[i] * 2;  // Multiply each element by 2
    }

    return NULL;
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        nums.push_back(value);  
    }

    cout << "Enter the number of threads: ";
    cin >> num_threads;

    pthread_t threads[num_threads];  

    // Create threads
    for (long i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, operation, (void*)i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    cout << "Scaled numbers: ";
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
