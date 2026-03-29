#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 MERGE SORT (Divide & Conquer)
============================================
- Divide array into two halves
- Sort both halves recursively
- Merge sorted halves
*/

void merge(vector<int> &arr, int low, int mid, int high){

    vector<int> temp;   // temporary array

    int left = low;        // starting index of left half
    int right = mid + 1;   // starting index of right half

    // Step 1: Merge both halves in sorted order
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Step 2: Copy remaining elements (if any)
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // Step 3: Copy sorted temp back to original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}


// Recursive function
void ms(vector<int> &arr, int low, int high){

    // Base case → single element
    if(low >= high) return;

    int mid = (low + high) / 2;

    // Divide
    ms(arr, low, mid);
    ms(arr, mid + 1, high);

    // Conquer (merge)
    merge(arr, low, mid, high);
}


// Wrapper function
void mergeSort(vector<int> &arr, int n){
    ms(arr, 0, n - 1);
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
    mergeSort(arr, n);   // ✅ correct function call

    // Step 5: Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}