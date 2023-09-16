#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, q, l, r;
	cin >> n >> q;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) a[i + 1] += a[i];
	while (cin >> l >> r) {
		cout << a[r] - a[l] << '\n';
	}
}