#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
============================================
🔹 FIBONACCI USING RECURSION
============================================
- f(n) = f(n-1) + f(n-2)
- Base case:
    f(0) = 0
    f(1) = 1
*/

int fibonacci(int n){  // void function can't return

    // Base case
    if(n <= 1){
        return n;
    }

    // Recursive call
    return fibonacci(n - 1) + fibonacci(n - 2);
}


/*
============================================
🔹 FIBONACCI SERIES (Print 0 → n terms)
============================================
- Calls fibonacci() for each index
- Prints full series
*/
void printFibonacciSeries(int n){

    cout << "Fibonacci Series: ";

    for(int i = 0; i < n; i++){
        cout << fibonacci(i) << " ";
    }
}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = fibonacci(n);

    cout << "Fibonacci number at position " << n 
         << " is: " << result <<endl;

    // Print full series
    printFibonacciSeries(n);



    return 0;
}