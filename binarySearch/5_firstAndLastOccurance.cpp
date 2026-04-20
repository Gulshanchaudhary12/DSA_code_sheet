#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
    ============================================================
    🔹 FIRST AND LAST OCCURRENCE IN A SORTED ARRAY (BINARY SEARCH)
    - Given a sorted array, find the first and last index of target `x`.
    - If `x` is not present, return {-1, -1}.
    - Example: arr = [1, 2, 2, 3], x = 2  →  {1, 2}
    ============================================================
*/

/**
 * @brief Finds the first (leftmost) index of `x` in a sorted array.
 *
 * Revision notes:
 * - This is a modified binary search.
 * - In standard binary search, search may stop when `arr[mid] == x`.
 * - Here, when `arr[mid] == x`, we store `mid` and continue searching left
 *   (`high = mid - 1`) to find an earlier occurrence.
 *
 * Why initialize `first = -1`?
 * - `-1` represents "not found".
 * - If `x` is never matched, the function returns `-1`.
 *
 * Search logic:
 * - `arr[mid] == x` → save `mid`, move left.
 * - `arr[mid] < x`  → move right (`low = mid + 1`).
 * - `arr[mid] > x`  → move left (`high = mid - 1`).
 *
 * Preconditions:
 * - `arr` must be sorted in non-decreasing order.
 * - `n` should be equal to `arr.size()` (or a valid searchable length).
 *
 * @param arr Sorted input array.
 * @param n Number of elements considered in `arr`.
 * @param x Target value.
 * @return First index of `x`, or `-1` if not found.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

int firstOccurance(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int first = -1;   // default (not found)

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] == x){
            first = mid;

            // Move left to find earlier occurrence
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurance(vector<int> &arr, int n, int x){

    int low = 0, high = n - 1;
    int last = -1;   // default (not found)

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] == x){
            last = mid;

            // Move right to find later occurrence
            low = mid + 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return last;
}
pair<int, int> firstAndLastOccurance(vector<int> &arr, int n, int x){

    int first = firstOccurance(arr, n, x);
    if(first == -1){
        // x not found in the array, so no need to search for last occurrence.
        return {-1, -1};
    }
    int last = lastOccurance(arr, n, x);

    return {first, last};
}

int main(){
    int n;
    cout<< "number of elements ";
    cin>> n;

    // input array
    vector<int> arr(n);
    cout<< "Element of an array: ";
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int x;
    cout<< "Element to find: ";
    cin>> x;

    pair<int, int> ans = firstAndLastOccurance(arr, n, x);
    cout<< "First Occurrence: " << ans.first << endl;
    cout<< "Last Occurrence: " << ans.second << endl;

    return 0;
}