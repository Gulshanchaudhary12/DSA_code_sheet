#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 BINARY SEARCH (RECURSIVE)
============================================
- Works only on SORTED array
- Divide search space into halves
*/

int bs(vector<int> &nums, int low, int high, int target){

    // Base case: element not found
    if(low > high) return -1;

    int mid = (low + high) / 2;

    // Element found
    if(nums[mid] == target){
        return mid;
    }

    // Search in right half
    else if(target > nums[mid]){
        return bs(nums, mid + 1, high, target);
    }

    // Search in left half
    else{
        return bs(nums, low, mid - 1, target);   // ✅ FIXED
    }
}


// Wrapper function
int search(vector<int> &nums, int target){
    return bs(nums, 0, nums.size() - 1, target);
}

int main(){

    // Step 1: Input size
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input sorted array
    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Input target
    int target;
    cout << "Enter target: ";
    cin >> target;

    // Step 4: Search
    int index = search(arr, target);

    // Step 5: Output
    if(index != -1){
        cout << "Element found at index: " << index;
    }
    else{
        cout << "Element not found";
    }

    return 0;
}