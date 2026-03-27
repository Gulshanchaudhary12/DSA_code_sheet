#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void printAllDivisors(int n){
    vector<int> ls;

    // O(sqrt(n))
    for (int i = 1; i<= sqrt(n); i++){
        if (n % i == 0){
            ls.push_back(i);
            if((n/i != i)){
                ls.push_back(n/i);
            }
        }
    }

    // O(no of factors * log(no of factors)): n is the number of factors
    sort(ls.begin(), ls.end());
    // O(number of factors)
    for(auto it: ls) cout << it << " ";
}

int main (){
    printAllDivisors(36);

    return 0;
}