#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

long long eval(long long x, long long y, char op) {
    if (op == '*') {
        return x * y;
    }
    else if (op == '+') {
        return x + y;
    }
    else if (op == '-') {
        return x - y;
    }
    else {
        assert(0);
    }
}

vector<long long> get_min_max(int i, int j, vector<vector<long long>> &max_matrix, vector<vector<long long>> &min_matrix, string &operators) {
    long long a, b, c, d, up, low;
    up = -10e14;
    low = 10e14;
    for (int k = i; k < j; ++k) {
        a = eval(max_matrix[i][k], max_matrix[k + 1][j], operators[k]);
        b = eval(max_matrix[i][k], min_matrix[k + 1][j], operators[k]);
        c = eval(min_matrix[i][k], max_matrix[k + 1][j], operators[k]);
        d = eval(min_matrix[i][k], min_matrix[k + 1][j], operators[k]);
        up = std::max({up, a, b, c, d});
        low = std::min({low, a, b, c, d});
    }
    vector<long long> out = {low, up};
    // cout << up << endl;
    return out;
}

long long get_max_value(const string &expr) {
    int len = expr.length(), j, n;
    string oper;
    n = len / 2 + 1;
    vector<long long> digits(n);
    vector<vector<long long>> max_matrix(len / 2 + 1, vector<long long> (len / 2 + 1, 0));
    vector<vector<long long>> min_matrix(len / 2 + 1, vector<long long> (len / 2 + 1, 0));
    int i0 = 0;
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            digits[i0] = (long long)expr[i] - 48;
            ++i0;
        } else {
            oper += expr[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        min_matrix[i][i] = digits[i];
        max_matrix[i][i] = digits[i];
    }
    for (int s = 1; s < n; ++s) {
        for (int i = 0; i < n - s; ++i) {
            j = i + s;
            min_matrix[i][j] = get_min_max(i, j, max_matrix, min_matrix, oper)[0];
            max_matrix[i][j] = get_min_max(i, j, max_matrix, min_matrix, oper)[1];
        }
    }
    return max_matrix[0][n - 1];
}

int main() {
    string in_expression;
    cin >> in_expression;
    cout << get_max_value(in_expression) << endl;
    return 0;
}
