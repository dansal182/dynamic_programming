#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int get_edit_distance(string str1, string str2) {
    int len_str1 = str1.length(), len_str2 = str2.length(), aux;
    int dist_matrix[len_str2 + 1][len_str1 + 1];
    str1 = "+" + str1;
    str2 = "+" + str2;
    for (int i = 0; i < len_str2 + 1; ++i) {
        dist_matrix[i][0] = i;
    }
    for (int j = 0; j < len_str1 + 1; ++j) {
        dist_matrix[0][j] = j;
    }
    for (int i = 1; i < len_str2 + 1; ++i) {
        for (int j = 1; j < len_str1 + 1; ++j) {
            aux = str1[j] == str2[i] ? 0 : 1;
            dist_matrix[i][j] = min({1 + dist_matrix[i - 1][j], 1 + dist_matrix[i][j - 1], aux + dist_matrix[i - 1][j - 1] });
        }
    }
    return dist_matrix[len_str2][len_str1];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << get_edit_distance(str1, str2) << endl;
    return 0;
}