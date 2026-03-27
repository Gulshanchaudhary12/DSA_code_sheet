#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {

    /*
    ============================================
    🔹 HASHING USING MAP (Frequency Count)
    ============================================
    - Used when values are large / unknown range
    - Automatically handles any integer (no size limit)
    - Keys → array elements
    - Values → frequency
    */

    // Step 1: Input size of array
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Input array elements
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Step 3: Precompute using map
    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;   // increase frequency
    }

    /*
    Example:
    arr = [1, 2, 2, 3]

    mpp[1] = 1
    mpp[2] = 2
    mpp[3] = 1
    */

    // Step 4: Number of queries
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    // Step 5: Answer queries
    while(q--){
        int number;
        cout << "Enter number to find frequency: ";
        cin >> number;

        cout << "Frequency of " << number << " is: " << mpp[number] << endl;
    }

    return 0;
}