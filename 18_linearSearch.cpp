#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 LINEAR SEARCH
============================================
Problem:
Given an array of size n and a target element, find the index of the target element in the array.
Example:
Input:  arr = [1, 2, 3, 4, 5], target = 3
Output: 2
Approach: Traverse the array and compare each element with the target.
- Time Complexity: O(n)
- Space Complexity: O(1)
*/      

int linearSearch(vector<int> &arr, int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1; // Element not found
}

int main(){
    int n, target;
    cout << "Enter the size of the array: "; 
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    int result = linearSearch(arr, n, target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;

}