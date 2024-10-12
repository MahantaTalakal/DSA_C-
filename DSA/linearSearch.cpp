#include <iostream>
using namespace std;

int main() {
    int n;

    // Ask the user for the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Input elements into the array
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Ask the user for the element to search
    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform linear search
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    // If the element was not found
    if(!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
