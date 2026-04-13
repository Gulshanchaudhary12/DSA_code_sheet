#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 CHECK IF ARRAY IS SORTED (Ascending)
============================================
- Compare each element with previous one
- If any element is smaller than previous → NOT sorted
*/

bool isSorted(int n, vector<int> &a){

    // Traverse array from index 1
    for(int i = 1; i < n; i++){

        // If current element is smaller → not sorted
        if(a[i] < a[i - 1]){
            return false;
        }
    }

    // If no violation found → sorted
    return true;
}



int main(){

    // Step 1: Input size
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Check sorted
    if(isSorted(n, arr)){
        cout << "Array is sorted";
    }
    else{
        cout << "Array is NOT sorted";
    }

    return 0;
}