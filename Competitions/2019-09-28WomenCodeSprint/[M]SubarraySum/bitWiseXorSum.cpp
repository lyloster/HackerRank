#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countPowerfulSubarrays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

bool powerOfTwo(int n);
int countPowerfulSubarrays(vector<int> arr);
int findGeneral (const vector <int>& arr);
int xOrInWindow(const vector<int>& arr, int windowSize, int start);

//int checkSingleElementArr (const vector<int>& arr);
// int checkPairElementArr (const vector<int>& arr);
// int checkFullElementArr (const vector<int>& arr);
// int checkFourElementArr (const vector<int>& arr);
// int checkThreeElementArr (const vector<int>& arr);
// int checkFiveElementArr (const vector<int>& arr);

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int ans = countPowerfulSubarrays(a);

    // fout.close();
    
    cout << ans << endl;

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

int countPowerfulSubarrays(vector<int> arr) {
    int powerfulCount = findGeneral(arr); 
    return powerfulCount;
    

}

// int checkFullElementArr (const vector<int>& arr){
//     int checkPower = arr[0];
//     int powerfulCount = 0;
//     for(int i = 1; i < arr.size(); i++){
//         // for(int j = 1; j < arr.size()-1; j++){
//           checkPower ^= arr[i];  
//         // }
//     }
//     //cout << "checkPower == " << checkPower << endl;
//     if(powerOfTwo(checkPower)){
//         powerfulCount++;
//     }
//     //cout << "count in full " << powerfulCount << endl;
//     return powerfulCount;
// }

// int checkFiveElementArr (const vector<int>& arr){
//     int checkPower;
//     int powerfulCount = 0;
//     for(int i = 0; i < arr.size()-4; i++){
//         checkPower = arr[i]^arr[i+1]^arr[i+2]^arr[i+3]^arr[i+4];
//         if(powerOfTwo(checkPower)){
//             powerfulCount++;
//         }
//     }
//     return powerfulCount;
// }

// int checkFourElementArr (const vector<int>& arr){
//     int checkPower;
//     int powerfulCount = 0;
//     for(int i = 0; i < arr.size()-3; i++){
//         checkPower = arr[i]^arr[i+1]^arr[i+2]^arr[i+3];
//         if(powerOfTwo(checkPower)){
//             powerfulCount++;
//         }
//     }
//     return powerfulCount;
// }

// int checkThreeElementArr (const vector<int>& arr){
//     int powerfulCount = 0;
//     int checkPower;
//     for(int i = 0; i < arr.size()-2; i++){
//         checkPower = arr[i]^arr[i+1]^arr[i+2];
//         if(powerOfTwo(checkPower)){
//             powerfulCount++;
//         }
//     }
//     return powerfulCount;
// }


// int checkPairElementArr (const vector<int>& arr){
//     int checkPower;
//     int powerfulCount = 0;
//     for(int i = 0; i< arr.size()-1;i++){
//         //for(int j = 0; j < arr.size()-1; j++){
//             checkPower = arr[i]^arr[i+1];
//             if(powerOfTwo(checkPower)){
//                 powerfulCount++;
//             }
//         }
    
//     //cout << "count in pair " << powerfulCount << endl;
//     return powerfulCount;
// }

// int checkSingleElementArr (const vector<int>& arr){
//     int powerfulCount = 0;
//     for(int i = 0; i<arr.size(); i++){
//         if(powerOfTwo(arr[i])){
//             powerfulCount++;
//         }
//     }
//     //cout << "count in single " << powerfulCount << endl;
//     return powerfulCount;
//}

//Returns the number of contiguous subarrays whose bitwise xor sums are a power of 2
int findGeneral (const vector <int>& arr){
    int powerfulCount = 0;
    int powerCheck;
    //Determines window size and start position in array
    //Based on pattern in commented-out functions
    for (int windowSize = 1; windowSize <= arr.size(); windowSize++){
        for(int start = 0; start < arr.size()-(windowSize-1); start++){
            powerCheck = xOrInWindow(arr, windowSize, start);
            if(powerOfTwo(powerCheck)){
                powerfulCount++;
         }
            powerCheck = 0;
        }

    }
    return powerfulCount;
    
}

//Checks xor for a specific window size and start in array, returns xor-sum
int xOrInWindow(const vector<int>& arr, int windowSize, int start){
    //cout << "start == " <<start << endl;
    //cout << "WS == " << windowSize << endl;
    int powerCheck = arr[start];
    for( int i = 1; i < windowSize; i ++){
        powerCheck ^= arr[start+i];
    }
    return powerCheck;
}

bool powerOfTwo(int n){
    //cout << "n == " << n << endl;
    if(n==0){
        return false;
    }
    if(n == 1){
        return true;
    }
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            return false;
        }
    }
    return true;
}