#include <iostream>
#include <vector>

using namespace std;

int knapsack_reps(vector<int> weights, vector<int> values, int capacity) {
    vector<int> optimal_sack(capacity + 1);
    int aux;
    optimal_sack[0] = 0;
    for (int cap = 1; cap < capacity + 1; ++cap) {
        optimal_sack[cap] = 0;
        for (int i = 0; i < weights.size(); ++i) {
            if (weights[i] <= cap) {
                aux = optimal_sack[(int) cap - weights[i]] + values[i];
                if (aux >= optimal_sack[cap]) {
                    optimal_sack[cap] = aux;
                }
            }

        }
    }
    return optimal_sack[capacity];
}

int knapsack_no_reps(vector<int> weights, vector<int> values, int capacity) {
    int n = weights.size();
    vector<vector<int>> optimal_sack(n + 1, vector<int> (capacity + 1));
    for (int i = 0; i < capacity + 1; ++i) {
        optimal_sack[0][i] = 0;
    }
    for (int i = 1; i < n + 1; ++i) {
        optimal_sack[i][0] = 0;
    }
    for (int j = 1; j < n + 1; ++j) {
        for (int cap = 1; cap < capacity + 1; ++cap) {
            if (weights[j - 1] > cap) optimal_sack[j][cap] = optimal_sack[j - 1][cap];
            else {
                if (optimal_sack[j - 1][(int) cap - weights[j - 1]] + values[j - 1] >= optimal_sack[j - 1][cap]) {
                    optimal_sack[j][cap] = optimal_sack[j - 1][(int) cap - weights[j - 1]] + values[j - 1];
                } else {
                    optimal_sack[j][cap] = optimal_sack[j - 1][cap];
                }
            }
        }
    }
    return optimal_sack[n][capacity];
}

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> weights(n);
    // vector<int> values(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> weights[i];
        // values[i] = weights[i]
    }
    cout << knapsack_no_reps(weights, weights, W) << endl;
    return 0;
}
