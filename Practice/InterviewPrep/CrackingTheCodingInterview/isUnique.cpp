#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::map;


bool isUnique(const string& s);

int main(){
	string s;
	while(cin >> s){
		bool unique = isUnique(s);
		cout << s <<  " " << unique << endl;;
	}

	return 0;
}

bool isUnique(const string& s){
	map<char,int> m;
	for(int i = 0; i < s.length(); i++){
		m[s[i]]++;
	}

	for(map<char,int>::iterator it = m.begin(); it != m.end(); it++){
		if(it->second > 1){
			return false;
		}
	}

	return true;
}