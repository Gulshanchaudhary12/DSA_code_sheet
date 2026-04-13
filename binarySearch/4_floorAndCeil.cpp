#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


/*
============================================
🔹 FLOOR
============================================
- Largest element ≤ x
*/

int findFloor(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int ans = -1;   // default (no floor)

    while(low <= high){

        int mid = low + (high - low) / 2;

        // Possible answer
        if(arr[mid] <= x){
            ans = arr[mid];

            // Move right to find larger possible floor
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}


/*
============================================
🔹 CEIL
============================================
- Smallest element ≥ x
*/

int findCeil(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int ans = -1;   // default (no ceil)

    while(low <= high){

        int mid = low + (high - low) / 2;

        // Possible answer
        if(arr[mid] >= x){
            ans = arr[mid];

            // Move left to find smaller possible ceil
            high = mid - 1;
        }
        else{
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

    // Step 3: Input value
    int x;
    cout << "Enter value x: ";
    cin >> x;

    // Step 4: Find floor & ceil
    int floorVal = findFloor(arr, n, x);
    int ceilVal = findCeil(arr, n, x);

    // Step 5: Output
    cout << "Floor: " << floorVal << endl;
    cout << "Ceil: " << ceilVal << endl;

    return 0;
}