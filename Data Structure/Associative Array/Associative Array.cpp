#include <iostream>
using namespace std;
using ll = long long;

const int N = 65537;
const int K = 30;

struct node { int sz; ll k[K], v[K]; };

node a[N];

// a[k]が存在するならばその値を返し、存在しないならば-1を返す
int f1(ll k) {
	int d = k % N;
	for (int i = 0; i < a[d].sz; i++) {
		if (a[d].k[i] == k) return i;
	}
	return -1;
}

// a[k]にvを代入
void add(ll k, ll v) {
	int d = k % N;
	int f = f1(k);
	if (f == -1) {
		a[d].k[a[d].sz] = k;
		a[d].v[a[d].sz] = v;
		a[d].sz++;
	} else {
		a[d].v[f] = v;
	}
}

ll find(ll k) {
	return a[k % N].v[f1(k)];
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			ll k, v;
			cin >> k >> v;
			add(k, v);
		} else {
			ll k;
			cin >> k;
			cout << find(k) << '\n';
		}
	}
}