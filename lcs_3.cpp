#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_lcs_3(vector<int> vec1, vector<int> vec2, vector<int> vec3) {
    vec1.insert(vec1.begin(), 0);
    vec1.insert(vec1.end(), 0);
    vec2.insert(vec2.begin(), 0);
    vec2.insert(vec2.end(), 0);
    vec3.insert(vec3.begin(), 0);
    vec3.insert(vec3.end(), 0);
    int len1 = vec1.size(), len2 = vec2.size(), len3 = vec3.size(), aux_lcs;
    int lcs_matrix[len1][len2][len3];
    for (int i = 0; i < len1; ++i) {
        for (int k = 0; k < len3; ++k) {
            lcs_matrix[i][0][k] = 0;
        }
    }
    for (int j = 0; j < len2; ++j) {
        for (int k = 0; k < len3; ++k) {
            lcs_matrix[0][j][k] = 0;
        }
    }
    for (int i = 0; i < len1; ++i) {
        for( int j = 0; j < len2; ++j) {
            lcs_matrix[i][j][0] = 0;
        }
    }
    for(int i = 1; i < len1; ++i) {
        for(int j = 1; j < len2; ++j) {
            for(int k = 1; k < len3; ++k) {
                if (vec1[i] ==  vec2[j] && vec2[j] == vec3[k]) {
                    aux_lcs = lcs_matrix[i - 1][j - 1][k - 1] + 1;
                } else {
                    aux_lcs = max({lcs_matrix[i - 1][j][k], lcs_matrix[i][j - 1][k], lcs_matrix[i][j][k - 1]});
                }
                lcs_matrix[i][j][k] = aux_lcs;
            }
        }
    }
    return lcs_matrix[len1 - 1][len2 - 1][len3 - 1] - 1;
}

int main() {
    int n, m, p;
    cin >> n;
    vector<int> vector1(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> vector1[i];
    }
    cin >> m;
    vector<int> vector2(m);
    for (size_t j = 0; j < m; ++j) {
        cin >> vector2[j];
    }
    cin >> p;
    vector<int> vector3(p);
    for (size_t k = 0; k < p; ++k) {
        cin >> vector3[k];
    }
    cout << get_lcs_3(vector1, vector2, vector3) << endl;
    return 0;
}
