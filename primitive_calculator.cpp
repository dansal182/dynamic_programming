#include <iostream>
#include <vector>
#include <algorithm>

#define UPPER 10e8;
using namespace std;

int get_num_operations(int& number) {
    vector<int> num_oper(number + 1);
    int q1, q2, q3;
    for (int i = 2; i < number + 1; ++i) {
        q1 = num_oper[i - 1] + 1;
        q2 = UPPER;
        q3 = UPPER;
        if (i % 3 == 0) q3 = num_oper[i / 3] + 1;
        if (i % 2 == 0) q2 = num_oper[i / 2] + 1;
        num_oper[i] = min({q1, q2, q3});
    }
    return num_oper[number];
}

vector<int> get_number_sequence(int number, int num_oper) {
    vector<int> sequence(num_oper + 1);
    int aux = number;
    for (int i = num_oper; i > -1; --i) {
        sequence[i] = aux;
        if (aux % 3 == 0) aux = aux / 3;
        else if ((aux - 1) % 3 == 0) aux = aux - 1;
        else if (aux % 2 == 0) aux = aux / 2;
        else aux = aux - 1;
    }
    return sequence;
}

int main() {
    int n, q;
    cin >> n;
    q = get_num_operations(n);
    cout << q << endl;
    vector<int> seq = get_number_sequence(n, q);
    for (int i = 0; i < q + 1; ++i) {
        cout << seq[i] << ' ';
    }
    return 0;
}
