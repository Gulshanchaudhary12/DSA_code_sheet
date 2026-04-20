#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 LEFT ROTATE BY ONE PLACE
============================================
Problem:
Given an array of size n, move every element one position to the left,
and move the first element to the last position.

Example:
Input:  [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]

Approach:
1. Store arr[0] in a temporary variable.
2. Shift elements from index 1..n-1 one step left.
3. Put the stored element at arr[n-1].

Edge Case:
- If n == 0, return the array as it is.

- Time Complexity: O(n)
- Space Complexity: O(1)
*/
vector<int> leftRotateByOnePlace(vector<int> &arr, int n){

    if(n == 0) return arr;

    int firstElement = arr[0];  // Store the first element

    // Shift all elements to the left
    for(int i = 1; i < n; i++){
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = firstElement;   // Place the first element at the end

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

    // Step 3: Left rotate by one place
    vector<int> rotatedArr = leftRotateByOnePlace(arr, n);

    // Step 4: Print result
    cout << "Array after left rotation by one place: ";
    for(int i = 0; i < n; i++){
        cout << rotatedArr[i] << " ";
    }

    return 0;
}