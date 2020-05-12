#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n;
        cin >> n;
        int i;
        for (i = 1; i * i <= n; ++i);
        cout << i - 1 << endl;
    }
    return 0;
}