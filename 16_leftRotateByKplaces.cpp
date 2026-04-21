#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================   
🔹 LEFT ROTATE BY K PLACES
============================================
Problem:
Given an array of size n and an integer k, move every element k positions to the left,
and move the first k elements to the end of the array.              
Example:
Input:  arr = [1, 2, 3, 4, 5], k = 2
Output: [3, 4, 5, 1, 2]
Approach: 1 brute force approach
1. Store the first k elements in a temporary array. 
2. Shift elements from index k..n-1 k steps left.
3. Copy the stored k elements to the end of the array.
Edge Case:
- If n == 0 or k == 0, return the array as it is.   
- Time Complexity: O(n)
- Space Complexity: O(k)

Approach: 2 using reverse
1. Reverse the first k elements.
2. Reverse the remaining n-k elements.
3. Reverse the entire array.    
- Time Complexity: O(n)
- Space Complexity: O(1)
*/      

// method 1 brute force approach
// vector<int> leftRotateByKPlaces(vector<int> &arr, int n, int k){

//     if(n == 0 || k == 0) return arr;

//     k = k % n; // Handle cases where k > n

//     vector<int> temp(k); // Temporary array to store first k elements

//     // Step 1: Store the first k elements
//     for(int i = 0; i < k; i++){
//         temp[i] = arr[i];
//     }

//     // Step 2: Shift elements from index k..n-1 k steps left
//     for(int i = k; i < n; i++){
//         arr[i - k] = arr[i];
//     }

//     // Step 3: Copy the stored k elements to the end of the array
//     for(int i = n - k; i < n; i++){
//         arr[i] = temp[i - (n - k)];
//     }

//     return arr;
// }

// method 2 using reverse (optimal)
vector<int> leftRotateByKPlaces(vector<int> &arr, int n, int k){

    if(n == 0 || k == 0) return arr;

    k = k % n; // Handle cases where k > n

    // Step 1: Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: Reverse the remaining n-k elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: Reverse the entire array
    reverse(arr.begin(), arr.end());

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

    // Step 3: Input k
    int k;
    cout << "Enter number of places to rotate (k): ";
    cin >> k;

    // Step 4: Left rotate by k places
    leftRotateByKPlaces(arr, n, k);

    // Step 5: Print result
    cout << "Array after left rotation by " << k << " places: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}