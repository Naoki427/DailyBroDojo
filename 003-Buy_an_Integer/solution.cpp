#include <algorithm>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ull = unsigned long long;

ull ccalculate_value(ull a, ull b, ull n) {
    ull dn = n == 0 ? 1 : (int)log10(n) + 1;
    return a * n + b * dn;
}

int main() {
    ull a,b,x;
    cin >> a >> b >> x;

    ull left = 0;
    ull right = 10000000000ULL;
    ull answer = 0;
    ull max = 1000000000ULL;
    while(left < right)
    {
        ull mid = (left + right) / 2;
        ull price = ccalculate_value(a,b,mid);
        if(price <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if(answer > max)
        answer = max;
    cout << answer;
}