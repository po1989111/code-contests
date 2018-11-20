#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("output.txt");

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n, k;
        cin >> n >> k;

        int robots[4][n];
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < n; l++) {
                cin >> robots[j][l];
            }
        }

        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                m[robots[0][j] ^ robots[1][l]] += 1;
            }
        }

        long long count = 0;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                int key = robots[2][j] ^ robots[3][l] ^ k;
                if (m.count(key)) {
                    count += m[key];
                }
            }
        }

        fout << "Case #" << i << ": " << count << endl;
    }

    fout.close();

    return 0;
}