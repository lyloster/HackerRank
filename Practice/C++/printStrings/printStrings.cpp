#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b;
    cin>> a >> b;
    int aSize = a.size();
    int bSize = b.size();
    
    cout << aSize << " " << bSize << endl;
    cout << a + b << endl;

    //switch first two letters of each string
    char temp;
    temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b ;

    return 0;
}

