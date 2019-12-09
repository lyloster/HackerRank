#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long numA = 0;

    //count numA in substring
    for(long i = 0; i < s.length(); i++){
        if(s[i] == 'a'){
            numA++;
        }
    }

    //multiply by number of repeats
    long repeats = n/s.length();
    numA *= repeats;

    //account for partial repeats
    long remainder = n%s.length();
    if(remainder != 0){
        for(long i = 0; i < remainder; i++){
            if(s[i] == 'a'){
            numA++;
            }
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
