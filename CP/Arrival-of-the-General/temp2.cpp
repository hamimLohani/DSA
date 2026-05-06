#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, temp, max = INT_MIN, min = INT_MAX, mx_ind, mn_ind;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i] = temp;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
    }
    for (int i = 0; i < n; i++) 
        if (max == v[i]) {
            mx_ind = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (min == v[i]) {
            mn_ind = i;
            break;
        }
    int move = mx_ind + (n - 1 - mn_ind);
    if (mn_ind < mx_ind) move--;

    cout << move << endl;
    return 0;
}