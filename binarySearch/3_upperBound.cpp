#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 UPPER BOUND
============================================
- Finds first index where value > x
- If not found → returns n
- Works only on SORTED array
*/

int upperBound(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int ans = n;   // default (no element > x)

    while(low <= high){

        int mid = low + (high - low) / 2;

        // Possible answer
        if(arr[mid] > x){
            ans = mid;

            // Try to find smaller index on left
            high = mid - 1;
        }
        else{
            // Move to right
            low = mid + 1;
        }
    }

    return ans;
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
    int x;
    cout << "Enter value x: ";
    cin >> x;

    // Step 4: Find upper bound
    int index = upperBound(arr, n, x);

    // Step 5: Output
    if(index < n){
        cout << "Upper Bound index: " << index 
             << " (Value: " << arr[index] << ")";
    }
    else{
        cout << "No element > " << x;
    }

    return 0;
}