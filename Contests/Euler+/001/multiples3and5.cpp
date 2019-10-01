#include <iostream>
using namespace std;

int findMultiple3 (int n);
int findMultiple5 (int n);
int findMultiple15 (int n);

int main(){
    int n;
    cin >> n;

    while(cin>>n){
    //account for rounding down
    n= n-1;
    //closed form of the sum of i
    //(n*(n+1))/2 
    //with n adjusted for multiples of 3 and 5
    //and first multiple in common subtracted 
    //to account for repeats in the sums of 3 and 5
    long mult3 = n/3;
    long mult5 = n/5;
    long mult15 = n/15;
    long result = 3*(mult3*(mult3+1)/2)+5*(mult5*(mult5+1)/2)-15*(mult15*(mult15+1)/2);
    cout << result << endl;

    }

    return 0;
}


