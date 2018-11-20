#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
    ofstream fout("output.txt");

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        long long total = 1;
        for (int j = 0; j < s.size(); j++) {
            set<char> combination;
            combination.insert(s[j]);
            if (j > 0) {
                combination.insert(s[j - 1]);
            }
            if (j < s.size() - 1) {
                combination.insert(s[j + 1]);
            }

            total *= combination.size();
            total %= MOD;
        }
        fout << "Case #" << i << ": " << total << endl;
    }

    fout.close();

    return 0;
}