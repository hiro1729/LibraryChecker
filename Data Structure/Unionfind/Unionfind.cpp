#include <iostream>
#include <vector>
using namespace std;

struct unionfind {
	vector<int> par, rnk, siz;
	unionfind(int n) : par(n, -1), rnk(n, 0), siz(n, 1) {}
	int rt(int x) {
		if (par[x] == -1) return x;
		else return par[x] = rt(par[x]);
	}
	bool same(int x, int y) {
		return rt(x) == rt(y);
	}
	bool merge(int x, int y) {
		int rx = rt(x), ry = rt(y);
		if (rx == ry) return false;
		if (rnk[rx] < rnk[ry]) swap(rx, ry);
		par[ry] = rx;
		if (rnk[rx] == rnk[ry]) rnk[rx]++;
		siz[rx] += siz[ry];
		return true;
	}
	int sz(int x) {
		return siz[rt(x)];
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	unionfind uf(n);
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) uf.merge(u, v);
		else cout << uf.same(u, v) << '\n';
	}
}