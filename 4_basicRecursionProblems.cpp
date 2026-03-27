#include<iostream>
using namespace std;

void f1(int i,int n){ // print name 5 times
    if (i > n) return;
    cout << "raj"<<endl;
    f1(i+1, n);

}

void f2(int i, int n){ // print linearly from 1 to N
    if(i > n) return;
    cout << i<<endl;
    f2(i+1, n);
}
void f3(int i, int n){  // print N to 1
    if ( i< 1) return;
    cout << i<<endl;
    f3(i-1,n);
}

void f4(int i, int n){ // print linearly from 1 to N but by backtracking
    if(i < 1) return;
    f4(i-1, n);
    cout << i << endl;
}

void f5(int i, int n){  // print from N to 1 by backtracking
    if(i > n) return;
    f5(i+1, n);
    cout << i << endl;
}


int main(){
    int n;
    cout<< "enter the number: ";
    cin >>n;
    // f1(1,n);
    // f2(1,n);
    // f3(n,n);
    // f4(n,n);
    // f5(1,n);
}