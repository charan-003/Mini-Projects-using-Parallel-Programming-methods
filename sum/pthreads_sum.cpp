/*
#include <iostream>
#include <pthread.h>

using namespace std;

// Example thread function
void* my_thread_function(void* arg) {
    int* my_arg = (int*)arg;  // Cast argument to expected type
    cout << "Thread is running with argument: " << *my_arg << endl;

    // Perform some task...
    
    pthread_exit(NULL);  // Exit the thread
}

int main() {
    pthread_t thread;  // Declare a pthread variable to hold the thread ID
    int arg = 42;  // Example argument to pass to the thread

    // Create the thread
    pthread_create(&thread, NULL, my_thread_function, (void*)&arg);

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    cout << "Thread has completed." << endl;

    return 0;
}

*/

#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

int *nums, *sums;

void* sum_func(void* arg) {
    int* range = (int*)arg;
    int start = range[0], end = range[1], id = range[2];
    int local_sum = 0;

    for (int i = start; i < end; i++) 
        local_sum += nums[i];

    sums[id] = local_sum;  // Store the local sum after the loop ends

    delete[] range;  // Free the memory for the range array
    pthread_exit(NULL);  // Exit the thread
}


int main() {
    int n;
    cout << "Number of elements: ";
    cin >> n;

    nums = new int[n];
    cout << "Eter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    // splitting the probelm into parts
    int threads_count = 4;
    int segment_size = n / threads_count;  // Declare segment_size as an int
    pthread_t threads[threads_count];
    sums = new int[threads_count];

    // giving each thread the work

for (int i = 0; i < threads_count; i++) {
    int* range = new int[3];
    range[0] = i * segment_size; // where to start

    if (i == threads_count - 1) { // where to stop
        range[1] = n; 
    } else {
        range[1] = (i + 1) * segment_size; 
    }

    range[2] = i;  // Set the thread ID to find which thread did the sum
    pthread_create(&threads[i], NULL, sum_func, (void*)range);
}


    for (int i = 0; i < threads_count; i++) 
        pthread_join(threads[i], NULL);
        // This function ensures that the main thread waits for all worker threads to complete before proceeding. This is crucial because we need all parts of the array summed before we can compute the final total.


    int total_sum = 0;
    for (int i = 0; i < threads_count; i++) 
        total_sum += sums[i];

    cout << "Total sum: " << total_sum << endl;

    delete[] nums;
    delete[] sums;
    return 0;
}
