#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) long long((x).size())
#define OUT(x) cout << (x) << endl
typedef long long ll;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp
// O(n)
int main() {
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll x[q];
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < q; i++) {
        ll ans = 0, sum = 0;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && sum + a[right] <= x[i]) {
                sum += a[right];
                right++;
            }
            ans += right - left;
            if (left == right)
                right++;
            else
                sum -= a[left];
        }
        OUT(ans);
    }
}
