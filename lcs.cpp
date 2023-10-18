#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int get_lcs(vector<int> str1, vector<int> str2) {
    str1.insert(str1.begin(), 0);
    str1.insert(str1.end(), 0); 
    str2.insert(str2.begin(), 0);
    str2.insert(str2.end(), 0);
    int len1 = str1.size(), len2 = str2.size(), aux_lcs;
    int match_matrix[len2][len1];
    for (int i = 0; i < len2; ++i) {
        match_matrix[i][0] = 0;
    }
    for (int j = 0; j < len1; ++j) {
        match_matrix[0][j] = 0;
    }
    for (int i = 1; i < len2; ++i) {
        for (int j = 1; j < len1; ++j) {
            if (str1[j] == str2[i]) aux_lcs = match_matrix[i - 1][j - 1] + 1;
            else aux_lcs = max(match_matrix[i - 1][j], match_matrix[i][j - 1]);
            match_matrix[i][j] = aux_lcs;
        }
    }
    return match_matrix[len2 - 1][len1 - 1] - 1;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> vec1(n);
    for ( size_t i = 0; i < n; ++i) {
        cin >> vec1[i];
    }
    cin >> m;
    vector<int> vec2(m);
    for (size_t j = 0; j < m; ++j) {
        cin >> vec2[j];
    }
    cout << get_lcs(vec1, vec2) << endl;
    return 0;
}
