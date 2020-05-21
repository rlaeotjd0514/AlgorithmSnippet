#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    unsigned long long prevv[101][21];
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j <= 20; j++) {
        prevv[1][j] = 0;
    }
    prevv[1][arr[1]] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            prevv[i][j] = 0;
        }
        for (int j = 0; j <= 20; j++) {
            if (prevv[i - 1][j] > 0) {
                if (j >= arr[i]) {
                    prevv[i][j - arr[i]] += prevv[i - 1][j];
                }
                if (j + arr[i] <= 20) {
                    prevv[i][j + arr[i]] += prevv[i - 1][j];
                }
            }
        }
    }
    cout << prevv[n - 1][arr[n]] << endl;
    return 0;
}
