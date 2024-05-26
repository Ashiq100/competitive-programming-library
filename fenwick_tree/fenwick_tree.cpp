#include <bits/stdc++.h>
using namespace std;

/*
Fenwick Tree for [0, n - 1] range.
*/

template<typename T>
class FenwickTree {
    int n_;
    vector<T> tree_;
public:
    FenwickTree(int n) : n_(n) {
        tree_ = vector<T>(n_ + 1);
    }

    void add(int i, T value) {
        ++i;
        while (i < n_ + 1) {
            tree_[i] += value;
            i += i & (-i) ;
        }
    }
    
    T get_sum(int i) {
        ++i;
        T sum = 0;
        while (i > 0) {
            sum += tree_[i];
            i -= i & (-i);
        }
        return sum;
    }

    T get_sum(int i, int j) {
        return get_sum(j) - get_sum(i - 1);
    }
};

int main() {

    int n = 10;
    vector<int> v(n);

    FenwickTree<double> ft(n);

    for(int i = 0; i < n; i++) {
        ft.add(i, 2.5);
    }

    cout << ft.get_sum(0, 2) << endl;
}