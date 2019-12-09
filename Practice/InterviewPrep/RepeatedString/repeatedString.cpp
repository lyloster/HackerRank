#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long repeats = n/s.length();
    long remainder = n%s.length();
    string newS = s;

    for(long i = 1; i < repeats; i++){
        newS += s;
    }

    if(remainder != 0){
        for(long i = 0; i < remainder; i++){
            newS += s[i];
        }
    }
    cout << newS;
    long numA = 0;
    for(long i = 0; i < newS.length(); i++){
        if(newS[i] == 'a'){
            numA++;
        }
    }
    return numA;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
