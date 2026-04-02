#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 QUICK SORT (Divide & Conquer)
============================================
- Pick a pivot element
- Place it at correct position
- Elements smaller → left side
- Elements greater → right side
*/

int partition(vector<int> &arr, int low, int high){

    int pivot = arr[low];   // choose first element as pivot
    int i = low;
    int j = high;

    while(i < j){   // ✅ FIXED condition

        // Move i forward until element > pivot
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }

        // Move j backward until element <= pivot
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }

        // Swap if i < j
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot at correct position
    swap(arr[low], arr[j]);

    return j;   // return pivot index
}


// Recursive Quick Sort
void qs(vector<int> &arr, int low, int high){

    if(low < high){

        int pIndex = partition(arr, low, high);

        // Sort left part
        qs(arr, low, pIndex - 1);

        // Sort right part
        qs(arr, pIndex + 1, high);
    }
}


// Wrapper function
void quickSort(vector<int> &arr, int n){
    qs(arr, 0, n - 1);
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

    // Step 4: Call merge sort (FIXED)
    quickSort(arr, n);   // ✅ correct function call

    // Step 5: Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}