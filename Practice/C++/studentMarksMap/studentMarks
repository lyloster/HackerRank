#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void isInM (map<string,int>& m, string s);

int main() {
    int n, opt, val;
    map<string, int> m;
    string s;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> opt;
        cin >> s;
        if(opt == 1){
            cin >> val;
            //adds s-val pair
            //if s is in map, adds val to old val
            //adds only first occurance of s-val
            //m.insert(pair<string,val>(s,val));
            m[s] += val;
        }else if(opt == 2){
            m.erase(s);
        }else{
            isInM (m, s);
        }
    }  
    return 0;
}

void isInM (map<string,int>& m, string s){
    map<string,int>::iterator it = m.find(s);
    if(it != m.end()){
        cout << it->second << endl;
    }else{
        cout << "0" << endl;
    }
}



