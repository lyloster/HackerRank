#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'classifySignals' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY freq_standard
 *  2. INTEGER_ARRAY freq_signals
 */

int findClosestPosition(const vector<int>& freq_standard, const vector<int>& differences);
vector<int> findDifference (const vector<int>& freq_standard, int x);
vector<int> classifySignals (const vector<int>& freq_standard, const vector<int>& freq_signals);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string f_temp_temp;
    getline(cin, f_temp_temp);

    vector<string> f_temp = split(rtrim(f_temp_temp));

    vector<int> f(n);

    for (int i = 0; i < n; i++) {
        int f_item = stoi(f_temp[i]);

        f[i] = f_item;
    }

    string F_temp_temp;
    getline(cin, F_temp_temp);

    vector<string> F_temp = split(rtrim(F_temp_temp));

    vector<int> F(q);

    for (int i = 0; i < q; i++) {
        int F_item = stoi(F_temp[i]);

        F[i] = F_item;
    }
    
    vector<int> ans = classifySignals(f, F);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
   }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

vector<int> classifySignals (const vector<int>& freq_standard, const vector<int>& freq_signals){
    vector<int>differences;
    int indexClosest;
    vector<int>classified;
    int x;
    for(int i = 0; i < freq_signals.size(); i++){
        x = freq_signals[i];
        differences = findDifference(freq_standard, x);
        indexClosest = findClosestPosition(freq_standard,differences);
        classified.push_back(indexClosest);
    }
    return classified;
}

int findClosestPosition(const vector<int>& freq_standard, const vector<int>& differences){
    int min = differences[0];
    int currentMinPosition = 1;
    for(int i = 1; i < differences.size(); i++){
        if(min == differences[i]){
            if(freq_standard[currentMinPosition-1] < freq_standard[i]){
                currentMinPosition = i+1;
            }
        }
        if(min > differences[i]){
            min = differences[i];
            currentMinPosition = i+1;
        }
    }
    return currentMinPosition;
}

vector<int> findDifference (const vector<int>& freq_standard, int x){
    vector <int> difference;
    for(int i = 0; i < freq_standard.size(); i++){
         difference.push_back(abs(freq_standard[i]-x));
     }
    return difference;
}
    
