#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector <long> fib(long n);
//void printVec(const vector<int>& v);
long long evenFibSum (const vector<long>& fib, long n);

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        vector<long> fibonacciNums = fib(n);
        //printVec(fibonacciNums);
        long long sum = evenFibSum(fibonacciNums, n);
        cout << sum << endl;
    }

    
    
    return 0;
}


vector <long> fib(long n){
    vector <long> fibNums;
    fibNums.push_back(1);
    fibNums.push_back(2);
    long sum;
    for(int i = 2; fibNums[i-1] <= n; i++){

        sum = fibNums[i-1] + fibNums[i-2];
        fibNums.push_back(sum);
        }
    
    return fibNums;

}

// void printVec(const vector<int>& v){
//     cout << "in print" << endl;
//     for(int i = 0; i < v.size(); i++){
//         cout << v[i] << "\t";
//     }
//     cout << endl;
// }

long long evenFibSum (const vector<long>& fib, long n){
    long long evenSum = 0;
    for(int i = 0; i < fib.size(); i++){
        if(fib[i] <= n && fib[i]%2==0){
            evenSum += fib[i];
        }
    }
    return evenSum;
}
