#include <iostream>
#include <pthread.h>

using namespace std;

int nums[100], output[100];  // Arrays to store input and output
int outputIndex = 0;  // Index to track the position in the output array
int n, num_threads;

// Function to check if a number is odd
bool oddd(int i) {
    return i % 2 != 0;}

    
void* processs(void* arg) {
    int thread_id = (long)arg;
    int thread_size = n / num_threads;
    int start_index = thread_id * thread_size;
    int end_index = start_index + thread_size;


    if (thread_id == num_threads - 1) {
        end_index = n;
    }

    for (int i = start_index; i < end_index; ++i) {
        if (oddd(nums[i])) {
            output[outputIndex++] = nums[i]; 
        }
    }

    return NULL;
}

int main() {
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the number of threads: ";
    cin >> num_threads;

    pthread_t threads[num_threads];

    // Create threads
    for (long i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, processs, (void*)i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the output array
    cout << "Output: ";
    for (int i = 0; i < outputIndex; ++i) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
