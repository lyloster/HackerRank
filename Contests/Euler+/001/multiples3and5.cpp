#include <iostream>
using namespace std;

int findMultiple3 (int n);
int findMultiple5 (int n);
int findMultiple15 (int n);

int main(){
    int n;
    cin >> n;

    while(cin>>n){

    int result = findMultiple3(n) + findMultiple5(n) - findMultiple15(n);
    cout << result << endl;

    }

    return 0;
}


int findMultiple3 (int n){
    int mult3 = 0;
    for (int i = 3; i < n; i = i+3){
        mult3+=i;
    }
    return mult3;
}

int findMultiple5 (int n){
    int mult5 = 0;
    for (int i = 5; i <n; i = i+5){
        mult5+=i;
    }
    return mult5;
}

int findMultiple15 (int n){
    int mult15 = 0;
    for (int i = 15; i < n; i = i+15){
        mult15+=i;
    }
    return mult15;
}


