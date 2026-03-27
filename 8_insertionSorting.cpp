#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 INSERTION SORT
============================================
- Picks one element and places it at correct position
- Works like sorting playing cards
- Left part is always sorted
*/

void insertion_sort(vector<int> &arr, int n){

    // Outer loop → picks element one by one
    for(int i = 0; i <= n - 1; i++){

        int j = i;

        // Shift element to correct position in sorted part
        while(j > 0 && arr[j - 1] > arr[j]){

            // Swap adjacent elements
            swap(arr[j - 1], arr[j]);

            j--;   // move backward
        }
    }
}

int main(){

    // Step 1: Take number of elements
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Create vector
    vector<int> arr(n);

    // Step 3: Input elements
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 4: Call insertion sort
    insertion_sort(arr, n);

    // Step 5: Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}