#include <iostream>
#include <vector>

#define UPPER 10e8;
using namespace std;

int get_change_dp(int money, vector<int>& coins) {
    vector<int> min_number_coins(money + 1);
    int number_coins = 0;
    min_number_coins[0] = 0;
    for (int i = 1; i <= money; ++i) {
        min_number_coins[i] = UPPER;
        for (int j = 0; j < coins.size(); ++j) {
            if (i >= coins[j]) {
                number_coins = min_number_coins[i - coins[j]] + 1;
                if (number_coins < min_number_coins[i]) {
                    min_number_coins[i] = number_coins;
                } 
            }
        }
    }
    return min_number_coins[money];
}

int main() {
    int money;
    vector<int> coins = {1, 3, 4};
    cin >> money;
    cout << get_change_dp(money, coins) << endl;
    return 0;
}
