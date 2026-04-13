#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 REMOVE DUPLICATES (Sorted Array)
============================================
- Uses Two Pointer Technique
- Only works for SORTED array
*/

int removeDuplicates(vector<int> &arr, int n){

    if(n == 0) return 0;

    int i = 0;   // last unique element index

    for(int j = 1; j < n; j++){

        // If new unique element found
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;   // new size
}



int main(){

    // Step 1: Input size
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array (MUST BE SORTED)
    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Remove duplicates
    int newSize = removeDuplicates(arr, n);

    // Step 4: Print result
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newSize; i++){
        cout << arr[i] << " ";
    }

    cout << "\nNew size: " << newSize;

    return 0;
}