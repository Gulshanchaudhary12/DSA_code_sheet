#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


/*
============================================
🔹 BUBBLE SORT (Optimized)
============================================
- Repeatedly compares adjacent elements
- Pushes largest element to the end
- Uses swap if elements are in wrong order
- Optimized using "didSwap" flag
*/

void bubble_sort(vector<int> &arr, int n){

    // Outer loop → number of passes
    for(int i = n - 1; i >= 0; i--){

        // Flag to check if any swap happened
        int didSwap = 0;

        // Inner loop → compare adjacent elements
        for(int j = 0; j <= i - 1; j++){

            // Swap if elements are in wrong order
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }

        // Optimization: if no swap → already sorted
        if(didSwap == 0){
            break;
        }

        // Debug line (optional)
        // cout << "Pass completed\n";
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

    // Step 4: Call bubble sort
    bubble_sort(arr, n);

    // Step 5: Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}