#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int n, num, sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n; // taking input from the user

    for (int i = 0; i < n; i++) {
        cout << "Enter elements " << i + 1 << ": ";
        cin >> num;
        sum = sum + num;

    }

    cout << "The sum of the numbers is: " << sum << endl;
    return 0;


}