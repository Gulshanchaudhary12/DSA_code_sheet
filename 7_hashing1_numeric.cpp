#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    /*
    ============================================
    🔹 ARRAY HASHING (Frequency Count)
    ============================================
    - Used when range of numbers is SMALL & FIXED
    - Index → number itself
    - Value → frequency of that number
    */

    // Step 1: Input size of array
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    vector<int> arr(n);
    cout << "Enter elements (values between 0 and 12): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Precompute frequency using hashing
    int hash[13] = {0};   // supports numbers from 0 to 12

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;   // increase frequency
    }

    /*
    Example:
    arr = [1, 2, 2, 3, 1]

    hash[1] = 2
    hash[2] = 2
    hash[3] = 1
    */

    // Step 4: Take number of queries
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    // Step 5: Answer queries
    while(q--){
        int number;
        cout << "Enter number to find frequency: ";
        cin >> number;

        cout << "Frequency of " << number << " is: " 
             << hash[number] << endl;
    }

    return 0;
}