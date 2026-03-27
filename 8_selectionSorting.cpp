#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 SELECTION SORT
============================================
- Repeatedly selects the smallest element
- Places it at the correct position
- Works in-place (no extra space)
*/

// Function to perform selection sort
// vector<int> &arr → passed by reference (no copy, original array gets sorted)
void selection_sort(vector<int> &arr, int n){

    // Outer loop → selects position where correct element should go
    for(int i = 0; i <= n - 2; i++){

        // Assume current index has minimum element
        int mini = i;

        // Inner loop → find actual minimum element in remaining array
        for(int j = i; j <= n - 1; j++){
            if(arr[j] < arr[mini]){
                mini = j;   // update index of minimum element
            }
        }

        // Swap the found minimum element with current position
        swap(arr[i], arr[mini]);
    }
}

int main(){

    // Step 1: Take number of elements
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Create vector of size n
    vector<int> arr(n);

    // Step 3: Input elements
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 4: Call selection sort function
    selection_sort(arr, n);

    // Step 5: Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}