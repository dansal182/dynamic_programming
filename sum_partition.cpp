#include <iostream>
#include <vector>

using namespace std;

vector<int> knap_check_sum(vector<int> numbers, int target) {
    int n = numbers.size(), aux;
    vector<vector<int>> sum_sack(n + 1, vector<int> (target + 1, 0));
    vector<int> bins(n, 0);
    // vector<int> subset;
    for ( int j = 1; j < n + 1; ++j) {
        for (int t = 1; t < target + 1; ++t) {
            if (numbers[j - 1] > t) {
                sum_sack[j][t] = sum_sack[j - 1][t];
            } else {
                if (sum_sack[j - 1][t - numbers[j - 1]] == t - numbers[j - 1]) {
                    sum_sack[j][t] = t;
                } else {
                    sum_sack[j][t] = sum_sack[j - 1][t];
                }
            }
        }
    }
    if (sum_sack[n][target] != 0) {
        aux = target;
        for(int k = n; k >= 1; --k) {
            if (sum_sack[k - 1][aux - numbers[k - 1]] == aux - numbers[k - 1]) {
                bins[k - 1] = 1;
                aux -= numbers[k - 1];
            }
        }
    }
    return bins;
}

int check_subsets_coll(vector<int> numbers, int suma, int num_subsets) {
    if (suma % num_subsets == 0 && numbers.size() >= num_subsets) {
        int out = 0;
        vector<int> bins = knap_check_sum(numbers, suma / num_subsets);
        for (int i = 0; i < bins.size(); ++i) {
            if (bins[i] == 1) {
                out = 1;
            }
        }
        return out;
    } else {
        return 0;
    }
}

int main() {
    int n, tar = 0, suma = 0, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> nums[i];
        tar += nums[i];
    }
    vector<int> aux_bins = knap_check_sum(nums, tar);
    for (int i = 0; i < n; ++i) {
        if (aux_bins[i] == 1) {
            cout << nums[i] << ' ';
            suma += nums[i];
        }
    }
    cout << endl;
    cout << suma << endl;
    cout << check_subsets_coll(nums, tar, q) << endl;
    return 0;
}