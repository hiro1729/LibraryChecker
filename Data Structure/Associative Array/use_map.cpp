#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int q;
	cin >> q;
	map<ll, ll> m;
	while (q--) {
		int t, k, v;
		cin >> t;
		if (t == 0) {
			cin >> k >> v;
			m[k] = v;
		} else {
			cin >> k;
			cout << m[k] << '\n';
		}
	}
}