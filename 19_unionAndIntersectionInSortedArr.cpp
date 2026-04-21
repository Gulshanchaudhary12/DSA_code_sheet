#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 UNION AND INTERSECTION OF TWO SORTED ARRAYS
============================================
Problem:
Given two sorted arrays, find their union and intersection.
Example:
Input:  arr1 = [1, 3, 4, 5, 7], arr2 = [2, 3, 5, 6]
Output: Union = [1, 2, 3, 4, 5, 6, 7], Intersection = [3, 5]
Approach: Two-pointer technique
1. Use two pointers to traverse both arrays.
2. Compare elements at each pointer and decide the next step.
- Time Complexity: O(m + n)
- Space Complexity: O(1) for intersection, O(m + n) for union
*/      

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2, int m, int n){
    vector<int> unionArr;
    int i = 0, j = 0;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            unionArr.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]){
            unionArr.push_back(arr2[j]);
            j++;
        }
        else{
            unionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    // Add remaining elements from either array
    while(i < m){
        unionArr.push_back(arr1[i]);
        i++;
    }
    while(j < n){
        unionArr.push_back(arr2[j]);
        j++;
    }
    return unionArr;
}

vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int m, int n){
    vector<int> intersection;
    int i = 0, j = 0;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersection;
}

int main(){
    int m, n;
    cout << "Enter the size of the first array: "; 
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    cout << "Enter the size of the second array: "; 
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    
    vector<int> unionArr = findUnion(arr1, arr2, m, n);
    vector<int> intersection = findIntersection(arr1, arr2, m, n);
    
    cout << "Union: ";
    for(int num : unionArr){
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Intersection: ";
    for(int num : intersection){
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}