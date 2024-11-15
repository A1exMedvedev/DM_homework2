#include <bits/stdc++.h>

using namespace std;


vector<string> operator+(vector<string> &a, vector<string> &b) {
    vector<string> c = a;
    for (auto i : b) {
        c.push_back(i);
    }
    return c;
}


int main() {

    int n, m;
    cin >> n;
    int R_size, S_size;
    cin >> R_size;
    vector<vector<string>> R_relation(R_size, vector<string> (n));
    for (int i = 0; i < R_size; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> R_relation[i][j];
        }
    }

    cin >> m >> S_size;
    vector<vector<string>> S_relation(S_size, vector<string>(m));
    for (int i = 0; i < S_size; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> S_relation[i][j];
        }
    }

    int common_fields_sz;
    cin >> common_fields_sz;
    vector<string> common_fields(common_fields_sz);

    for (int i = 0; i < common_fields_sz; ++i) {
        cin >> common_fields[i];
    }

    if (common_fields_sz != 0) {
        cout << "Cross join of two relations is undefined ";
        cout << "because thet have common attribute ";
        cout << common_fields[0];
        return 0;
    }

    vector<vector<string>> cross_join;

    for (auto i : R_relation) {
        for (auto j : S_relation) {
            cross_join.push_back(i + j);
        }
    }

    for (auto i : cross_join) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}