#include <iostream>
#include <cstdio>
using namespace std;
#include <vector>
using std::vector;

int max_of_four(int a, int b, int c, int d);

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}


int max_of_four(int a, int b, int c, int d){
    vector <int> numbersToCheck = {b,c,d};
    int max = a;
    for(int i = 0; i < numbersToCheck.size(); i++){
        if(max < numbersToCheck[i]){
            max = numbersToCheck[i];
        }
    }
    return max;
    }
    
