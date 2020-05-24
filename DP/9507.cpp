#include <iostream>
#include <vector>
#include <string>

using namespace std;

string add(string& a, string& b) {
    int l1 = a.length();
    int l2 = b.length();
    string s;
    string l;
    if (l1 == l2) {
        s = a;
        l = b;
    }
    else {
        s = l1 < l2 ? a : b;
        l = l1 > l2 ? a : b;
    }
    int c = 0;
    string ret = "";
    for (int i = 0; i < s.length() / 2; i++) {
        int t = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = t;
    }
    for (int i = 0; i < l.length() / 2; i++) {
        int t = l[i];
        l[i] = l[l.length() - 1 - i];
        l[l.length() - 1 - i] = t;
    }
    for (int i = 0; i < s.length(); i++) {
        int t1 = s[i] - 48;
        int t2 = l[i] - 48;
        int st = (t1 + t2 + c) % 10;
        ret += (char)(st + 48);
        if ((t1 + t2 + c) > 9) {
            c = 1;
        }
        else {
            c = 0;
        }
    }
    for (int i = s.length(); i < l.length(); i++) {
        ret += l[i] + c;
        c = 0;
    }
    if (c == 1) {
        ret += "1";
    }
    for (int i = 0; i < ret.length() / 2; i++) {
        int t = ret[i];
        ret[i] = ret[ret.length() - 1 - i];
        ret[ret.length() - 1 - i] = t;
    }
    return ret;
}

int main()
{
    int tc;
    vector<string> arr;
    vector<unsigned long long> dp;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n < 2) {
            cout << 1 << endl;
            continue;
        }
        else if (n == 2) {
            cout << 2 << endl;
            continue;
        }
        else if (n == 3) {
            cout << 4 << endl;
            continue;
        }
        arr.resize(n + 1);
        arr[0] = "1";
        arr[1] = "1";
        arr[2] = "2";
        arr[3] = "4";

        dp.resize(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        if (dp[n] != 0) {
            cout << dp[n] << endl;
            continue;
        }
        for (int i = 4; i <= n; i++) {
            string im = add(arr[i - 1], arr[i - 2]);
            string im2 = add(arr[i - 3], im);
            arr[i] = add(arr[i - 4], im2);
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
        }
        cout << dp[n] << endl;
    }
    return 0;
}