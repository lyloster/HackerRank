#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x, removeInd, rangeS, rangeE;
    vector<int> v;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    cin >> removeInd >> rangeS >> rangeE;

    v.erase(v.begin()+(removeInd - 1));
    v.erase(v.begin()+(rangeS-1), v.begin()+(rangeE-1));

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}
