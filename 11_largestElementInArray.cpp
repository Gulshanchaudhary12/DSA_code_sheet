#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 FIND LARGEST ELEMENT IN ARRAY
============================================
- Traverse the array
- Keep track of maximum value
*/

int largestElement(vector<int> &arr, int n){

    // Step 1: Assume first element is largest
    int largest = arr[0];

    // Step 2: Traverse array
    for(int i = 1; i < n; i++){

        // Step 3: Update if bigger element found
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    return largest;
}

int main(){

    // Step 1: Input size
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

    // Step 4: Call function
    int result = largestElement(arr, n);

    // Step 5: Print result
    cout << "Largest element: " << result;

    return 0;
}

