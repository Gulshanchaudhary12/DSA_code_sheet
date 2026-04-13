#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 SECOND LARGEST ELEMENT
============================================
- Keep track of largest and second largest
*/

int secondLargest(vector<int> &arr, int n){

    int largest = arr[0];
    int slargest = INT_MIN;

    for(int i = 1; i < n; i++){

        // New largest found
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }

        // Update second largest
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }

    return slargest;
}


/*
============================================
🔹 SECOND SMALLEST ELEMENT
============================================
- Keep track of smallest and second smallest
*/

int secondSmallest(vector<int> &arr, int n){

    int smallest = arr[0];
    int ssmallest = INT_MAX;

    for(int i = 1; i < n; i++){

        // New smallest found
        if(arr[i] < smallest){
            ssmallest = smallest;   // ✅ FIXED
            smallest = arr[i];
        }

        // Update second smallest
        else if(arr[i] > smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }

    return ssmallest;
}


/*
============================================
🔹 RETURN BOTH VALUES
============================================
*/

vector<int> getSecondOrderElements(int n, vector<int> &arr){

    int slargest = secondLargest(arr, n);
    int ssmallest = secondSmallest(arr, n);

    return {slargest, ssmallest};
}

int main(){

    // Step 1: Input size
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Edge case check
    if(n < 2){
        cout << "Not enough elements";
        return 0;
    }

    // Step 2: Input array
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Find results
    int slargest = secondLargest(arr, n);
    int ssmallest = secondSmallest(arr, n);

    // Step 4: Output
    cout << "Second Largest: " << slargest << endl;
    cout << "Second Smallest: " << ssmallest << endl;

    return 0;
}