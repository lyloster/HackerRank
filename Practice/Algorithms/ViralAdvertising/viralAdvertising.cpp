#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int liked;
    int willShare = 5;
    int totalReceived = 0;
    for(int i = 0; i < n; i++){
        liked = willShare/2;
        willShare = liked*3;
        totalReceived += liked;
    }
return totalReceived;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
