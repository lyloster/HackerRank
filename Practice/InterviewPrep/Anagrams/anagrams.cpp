#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    string s;
    int lengthA = a.length();
    cout << lengthA << endl;
    int lengthB = b.length();
    cout << lengthB << endl;
    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(a[i] == b[j]){
                s += a[i];
                //messing up the indexing
                b.erase(b.begin()+j);
            }
        }
    }
    cout << s.length() << endl;
    int deletion = (lengthA+lengthB)-(s.length()*2);
    return deletion;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
