#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void isInS (const set<int>& s, int x);

int main() {
    int x, y, n;
    bool inS;
    set<int> s;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        cin >> y;
        
        if(x==1){
            s.insert(y);
        }else if(x==2){
            s.erase(y);
        }else{
            isInS(s, y);
        }
    }
    return 0;
}

void isInS (const set<int>& s, int x){
    set<int>::iterator it = s.find(x);
    if(it != s.end()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}



