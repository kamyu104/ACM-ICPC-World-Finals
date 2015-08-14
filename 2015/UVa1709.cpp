// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1709 - Amalgamated Artichokes
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=865&page=show_problem&problem=4782
 *
 * Time  : O(n)
 * Space : O(1)
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios;
using std::max;

int main() {
    int p, a, b, c, d, n;
    while (cin >> p >> a >> b >> c >> d >> n) {
        vector<double> prices(n);
        for (double i = 1; i <= n; ++i) {
            prices[i - 1] = p * (sin(a * i + b) + cos(c * i + d) + 2);
        }
        double max_decline = 0.0;
        double max_price = prices.front();
        for (const auto& price : prices) {
            max_price = max(max_price, price);
            max_decline = max(max_decline, max_price - price);
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);
        cout << max_decline << endl;
    }
    return 0;
}
