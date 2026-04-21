#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 MOVE ALL ZEROS TO END
============================================
Problem:
Given an array of size n, move all zeros to the end of the array while maintaining the relative order of non-zero elements.
Example:
Input:  arr = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
Approach: Two-pointer technique
1. Use two pointers: one for iterating through the array and another for placing non-zero elements.
2. Iterate through the array and place all non-zero elements at the beginning.
3. Fill the remaining positions with zeros.
- Time Complexity: O(n)
- Space Complexity: O(1)

Approach: Using extra space (brute force approach)
1. Create a temporary array to store non-zero elements. 
2. Copy non-zero elements back to the original array.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/      

// method 1 using extra space (brute force approach)
vector<int> moveAllZeroesToEnd(vector<int> &arr, int n){
    vector<int> temp;
    // Step 1: Place all non-zero elements in temp
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    // step 2: Copy non-zero elements back to arr
    int nz = temp.size(); // number of non-zero elements
    for(int i = 0; i < nz; i++){
        arr[i] = temp[i];
    }

    // Step 3: Fill remaining positions with zeros
    for(int i = nz; i < n; i++){
        arr[i] = 0;
    }

    return arr;
} 

// method 2 using two-pointer technique (optimal approach)
vector<int> moveAllZeroesToEnd(vector<int> &arr, int n){
    int j = -1; // Pointer for the last non-zero element
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            j = i; // Mark the position of the first zero
            break;
        }
    }
    // there are no zeros in the array
    if(j == -1) return arr;
    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]); // Swap non-zero element with the first zero
            j++; // Move the pointer to the next zero
        }
    }
    return arr;
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

    // Step 3: Move all zeros to end
    moveAllZeroesToEnd(arr, n);

    // Step 4: Print result
    cout << "Array after moving all zeros to end: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
} 