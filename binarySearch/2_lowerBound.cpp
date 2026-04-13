#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 LOWER BOUND
============================================
- Finds first index where value >= x
- If not found → returns n (out of bounds)
- Works only on SORTED array
- Question-- search insert position is also a lower bound 
*/

int lowerBound(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int ans = n;   // default (if no element >= x)

    while(low <= high){

        int mid = low + (high - low) / 2;   // safe mid

        // Possible answer
        if(arr[mid] >= x){
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

    // Step 4: Find lower bound
    int index = lowerBound(arr, n, x);

    // Step 5: Output
    if(index < n){
        cout << "Lower Bound index: " << index 
             << " (Value: " << arr[index] << ")";
    }
    else{
        cout << "No element >= " << x;
    }

    return 0;
}