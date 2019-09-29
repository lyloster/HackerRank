#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'validate' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY data as parameter.
 */

string validate(vector<vector<int>> data);
bool checkRows(vector<vector<int>> data);
bool checkColumns(vector<vector<int>> data);
bool checkSub1 (vector<vector<int>> data);
bool checkSub2 (vector<vector<int>> data);
bool checkSub3 (vector<vector<int>> data);
bool checkSub4 (vector<vector<int>> data);
bool checkSub5 (vector<vector<int>> data);
bool checkSub6 (vector<vector<int>> data);
bool checkSub7 (vector<vector<int>> data);
bool checkSub8 (vector<vector<int>> data);
bool checkSub9 (vector<vector<int>> data);


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> suduko(n);

    for (int i = 0; i < n; i++) {
        suduko[i].resize(3);

        string suduko_row_temp_temp;
        getline(cin, suduko_row_temp_temp);

        vector<string> suduko_row_temp = split(rtrim(suduko_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int suduko_row_item = stoi(suduko_row_temp[j]);

            suduko[i][j] = suduko_row_item;
        }
    }

    string ans = validate(suduko);

    fout << ans << "\n";

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


string validate(vector<vector<int>> data) {
    bool rows = checkRows(data);
    bool columns = checkColumns(data);
    bool sub1 = checkSub1(data);
    bool sub2 = checkSub2(data);
    bool sub3 = checkSub3(data);
    bool sub4 = checkSub4(data);
    bool sub5 = checkSub5(data);
    bool sub6 = checkSub6(data);
    bool sub7 = checkSub7(data);
    bool sub8 = checkSub8(data);
    bool sub9 = checkSub9(data);
    if(rows == false || columns == false || sub1 == false || sub2 == false || sub3 == false || sub4 == false || sub5 == false || sub6 == false || sub7 == false || sub8 == false ||sub9 == false){
        return "WRONG INPUT";
    }else{
        return "OK";
    }
}

bool checkRows(vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j < data.size(); j++){
            if(data[i][0] == data[j][0]){
                if((data[i][2] == data[j][2]) && i!=j){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkColumns(vector<vector<int>> data){
        for(int i = 0; i <data.size(); i++){
        for(int j = 0; j < data.size(); j++){
            if(data[i][1] == data[j][1]){
                if((data[i][2] == data[j][2]) && i!=j) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub1 (vector<vector<int>> data){
    
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if(
                (data[i][0] >= 1 && data[i][0] <= 3 && data[i][1] >= 1 && data[i][1] <= 3) &&
                (data[j][0] >= 1 && data[j][0] <= 3 && data[j][1] >= 1 && data[j][1] <= 3) && 
                i!=j
            ){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub2 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 4 && data[i][0] <= 6 && data[i][1] >= 1 && data[i][1] <= 3) && (data[j][0] >= 4 && data[j][0] <= 6 && data[j][1] >= 1 && data[j][1] <= 3) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub3 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 7 && data[i][0] <= 9 && data[i][1] >= 1 && data[i][1] <= 3) && (data[j][0] >= 7 && data[j][0] <= 9 && data[j][1] >= 1 && data[j][1] <= 3) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub4 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 1 && data[i][0] <= 3 && data[i][1] >= 4 && data[i][1] <= 6) && (data[j][0] >= 1 && data[j][0] <= 3 && data[j][1] >= 4 && data[j][1] <= 6) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub5 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 4 && data[i][0] <= 6 && data[i][1] >= 4 && data[i][1] <= 6) && (data[j][0] >= 4 && data[j][0] <= 6 && data[j][1] >= 4 && data[j][1] <= 6) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}


bool checkSub6 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 7 && data[i][0] <= 9 && data[i][1] >= 4 && data[i][1] <= 6) && (data[j][0] >= 7 && data[j][0] <= 9 && data[j][1] >= 4 && data[j][1] <= 6) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}


bool checkSub7(vector<vector<int>> data){  
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 1 && data[i][0] <= 3 && data[i][1] >= 7 && data[i][1] <= 9) && (data[j][0] >= 1 && data[j][0] <= 3 && data[j][1] >= 7 && data[j][1] <= 9) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub8(vector<vector<int>> data){  
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 4 && data[i][0] <= 6 && data[i][1] >= 7 && data[i][1] <= 9) && (data[j][0] >= 4 && data[j][0] <= 6 && data[j][1] >= 7 && data[j][1] <= 9) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSub9 (vector<vector<int>> data){
    for(int i = 0; i <data.size(); i++){
        for(int j = 0; j <data.size(); j++){
            if((data[i][0] >= 7 && data[i][0] <= 9 && data[i][1] >= 7 && data[i][1] <= 9) && (data[j][0] >= 7 && data[j][0] <= 9 && data[j][1] >= 7 && data[j][1] <= 9) && i!=j){
                if(data[i][2] == data[j][2]){
                    return false;
                }
            }
        }
    }
    return true;
}