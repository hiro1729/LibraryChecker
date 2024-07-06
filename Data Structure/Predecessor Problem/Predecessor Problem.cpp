#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>

#define pc_u putchar_unlocked

struct Scanner {
	char *buf;
	ssize_t wt, rd;
	size_t maxsz;
public:
	Scanner(int size = 1<<12): maxsz(size) {
		buf = (char*)malloc(sizeof(char) * size);
		_read();
	}
	std::string read_str() {
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		int rd_first = rd;
		std::string res;
		while (rd <= wt && !isspace(buf[rd])) {
			++rd;
			if (rd == wt) {
				res += std::string(buf, rd_first, wt - rd_first);
				_read();
				rd_first = 0;
			}
		}
		res += std::string(buf, rd_first, rd - rd_first);
		return res;
	}
	char read_chr() {
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		return ch;
	}
	template<class T> T read_int() {
		T ret = 0;
		bool s = true;
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		if (ch == '-') {
			s = false;
			ch = nxchar();
		}
		for (; isdigit(ch); ch = nxchar()) ret = ret * 10 + ch - '0';
		return (s ? ret : -ret);
	}
	template<class T> T read_flt() {
		return stold(read_str());
	}
	std::string read_line() {
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		int rd_first = rd;
		std::string res;
		while (rd <= wt && buf[rd] != '\n') {
			++rd;
			if (rd == wt) {
				res += std::string(buf, rd_first, wt - rd_first);
				_read();
				rd_first = 0;
			}
		}
		res += std::string(buf, rd_first, rd - rd_first);
		return res;
	}
private:
	void _read() {
		ssize_t r = read(0, buf, maxsz);
		if (r < 0) {
			throw std::runtime_error(strerror(errno));
		}
		wt = r;
		rd = 0;
	}
	inline int nxchar() {
		++rd;
		if (rd == wt) _read();
		return _chr();
	}
	inline int _chr() {
		return rd == wt ? EOF : buf[rd];
	}
} sc;

// 基本的な型の入力
inline short Short() { return sc.read_int<short>(); }
inline unsigned short UShort() { return sc.read_int<unsigned short>(); }
inline int Int() { return sc.read_int<int>(); }
inline unsigned int UInt() { return sc.read_int<unsigned int>(); }
inline long Long() { return sc.read_int<long>(); }
inline unsigned long ULong() { return sc.read_int<unsigned long>(); }
inline long long LLong() { return sc.read_int<long long>(); }
inline unsigned long long ULLong() { return sc.read_int<unsigned long long>(); }
inline __int128_t Int7() { return sc.read_int<__int128_t>(); }
inline __uint128_t UInt7() { return sc.read_int<__uint128_t>(); }
inline float Float() { return sc.read_flt<float>(); }
inline double Double() { return sc.read_flt<double>(); }
inline long double LDouble() { return sc.read_flt<long double>(); }
inline std::string String() { return sc.read_str(); }
inline char Char() { return sc.read_chr(); }
inline bool Bool() { return sc.read_chr() == '1'; }

inline void _SingleInput(short &n) { n = Short(); }
inline void _SingleInput(unsigned short &n) { n = UShort(); }
inline void _SingleInput(int &n) { n = Int(); }
inline void _SingleInput(unsigned int &n) { n = UInt(); }
inline void _SingleInput(long &n) { n = Long(); }
inline void _SingleInput(unsigned long &n) { n = ULong(); }
inline void _SingleInput(long long &n) { n = LLong(); }
inline void _SingleInput(unsigned long long &n) { n = ULLong(); }
inline void _SingleInput(__int128_t &n) { n = Int7(); }
inline void _SingleInput(__uint128_t &n) { n = UInt7(); }
inline void _SingleInput(float &d) { d = Float(); }
inline void _SingleInput(double &d) { d = Double(); }
inline void _SingleInput(long double &d) { d = LDouble(); }
inline void _SingleInput(std::string &s) { s = String(); }
inline void _SingleInput(char &c) { c = Char(); }
inline void _SingleInput(bool &b) { b = Bool(); }
template<class S, class T> inline void _SingleInput(std::pair<S, T> &p) { _SingleInput(p.first); _SingleInput(p.second); }
template<class T> inline void _SingleInput(std::vector<T> &v) { for (T &x: v) _SingleInput(x); }

void input() { }
template<class T1, class... T2> void input(T1& t1, T2&... t2) { _SingleInput(t1); input(t2...); }

template<typename T> inline void print_int(T n) {
	if (n < 0) {
		pc_u('-');
		n = -n;
	}
	if (n < 10) {
		pc_u('0' + n);
		return;
	}
	int i;
	char b[21];
	b[20] = 0;
	for (i = 20; n > 0; b[--i] = '0' + n % 10, n /= 10); fputs(b + i, stdout);
}

template<typename T> void print_bigint(T n) {
	if (n < 0) {
		pc_u('-');
		n = -n;
	}
	if (n < 10) {
		pc_u('0' + n);
		return;
	}
	int i;
	char b[41];
	b[40] = 0;
	for (i = 40; n > 0; b[--i] = '0' + n % 10, n /= 10); fputs(b + i, stdout);
}

void print_char(char c) {
	pc_u(c);
}

void print_string(std::string s) {
	for (char &c: s) {
		pc_u(c);
	}
}

template<typename T> void print_double(T d) {
	print_string(std::to_string(d));
}

inline void _SingleOutput(short n) { print_int<short>(n); }
inline void _SingleOutput(unsigned short n) { print_int<unsigned short>(n); }
inline void _SingleOutput(int n) { print_int<int>(n); }
inline void _SingleOutput(unsigned int n) { print_int<unsigned int>(n); }
inline void _SingleOutput(long n) { print_int<long>(n); }
inline void _SingleOutput(unsigned long n) { print_int<unsigned long>(n); }
inline void _SingleOutput(long long n) { print_int<long long>(n); }
inline void _SingleOutput(unsigned long long n) { print_int<unsigned long long>(n); }
inline void _SingleOutput(__int128_t n) { print_bigint<__int128_t>(n); }
inline void _SingleOutput(__uint128_t n) { print_bigint<__uint128_t>(n); }
inline void _SingleOutput(float d) { print_double<float>(d); }
inline void _SingleOutput(double d) { print_double<double>(d); }
inline void _SingleOutput(long double d) { print_double<long double>(d); }
inline void _SingleOutput(std::string s) { print_string(s); }
inline void _SingleOutput(char c) { pc_u(c); }
inline void _SingleOutput(bool b) { pc_u(b ? '1' : '0'); }
template<class S, class T> inline void _SingleOutput(std::pair<S, T> p) { _SingleOutput(p.first); pc_u(' '); _SingleOutput(p.second); }
template<class T> inline void _SingleOutput(std::vector<T> v) { for (int i = 0; i < v.size() - 1; i++) { _SingleOutput(v[i]); pc_u(' '); } _SingleOutput(v.back()); }


void print() { pc_u('\n'); }
template<class T1, class... T2> void print(T1 t1, T2... t2) { _SingleOutput(t1); print(t2...); }

using namespace std;

using ull = unsigned long long;

/*
整数 k に対して、
A の位置を 111111 000000 000000 000000 の 111111 の部分
B の位置を 000000 111111 000000 000000 の 111111 の部分
C の位置を 000000 000000 111111 000000 の 111111 の部分
D の位置を 000000 000000 000000 111111 の 111111 の部分
と定義して、以下の説明で使います
*/

struct wordsizetree {
	ull A, B[1 << 6], C[1 << 12], D[1 << 18];
	wordsizetree() {
		A = 0;
		for (int i = 0; i < (1 << 6); i++) B[i] = 0;
		for (int i = 0; i < (1 << 12); i++) C[i] = 0;
		for (int i = 0; i < (1 << 18); i++) D[i] = 0;
		/*
		memset(B, 0, sizeof(B));
		memset(C, 0, sizeof(C));
		memset(D, 0, sizeof(D));
		*/
	}
/*
	a(k) は k の A の位置を
	b(k) は k の B の位置を
	c(k) は k の C の位置を
	d(k) は k の D の位置を
	返す関数です
*/
	inline int a(int k) {
		return k >> 18;
	}
	inline int b(int k) {
		return (k >> 12) & 63;
	}
	inline int c(int k) {
		return (k >> 6) & 63;
	}
	inline int d(int k) {
		return k & 63;
	}
/*
	add(k) は集合 S に k を追加する関数です
*/
	inline void add(int k) {
		A |= 1ULL << (k >> 18);
		B[k >> 18] |= 1ULL << ((k >> 12) & 63);
		C[k >> 12] |= 1ULL << ((k >> 6) & 63);
		D[k >> 6] |= 1ULL << (k & 63);
	}
/*
	erase(k) は集合 S から k を削除する関数です
*/
	inline void erase(int k) {
		D[k >> 6] &= ~(1ULL << (k & 63));
		if (D[k >> 6] == 0) {
			C[k >> 12] &= ~(1ULL << ((k >> 6) & 63));
			if (C[k >> 12] == 0) {
				B[k >> 18] &= ~(1ULL << ((k >> 12) & 63));
				if (B[k >> 18] == 0) {
					A &= ~(1ULL << (k >> 18));
				}
			}
		}
	}
/*
	in(k) は集合 S に k が含まれるか判定する関数です
*/
	inline bool in(int k) {
		return D[k >> 6] & (1ULL << (k & 63));
	}
/*
	ge(k) は集合 S に含まれ、かつ k 以上である最小の要素を返す関数です
*/
	inline int ge(int k) {
		// まず、上 18 桁が一致している場合、下 6 桁が k の下 6 桁以上である最小のものを返す
		if (D[k >> 6] >> (k & 63)) {
			return k + countr_zero(D[k >> 6] >> (k & 63));
		}
		// 上 12 桁が一致している場合、上 18 桁で一致しているものが存在しなかったので、C の部分が (k の C の部分) + 1 以上であるものを調べる
		if (C[k >> 12] >> 1 >> c(k)) {
			int ctz = c(k) + 1 + countr_zero(C[k >> 12] >> 1 >> c(k));
			int ctz2 = countr_zero(D[(k >> 12 << 6) | ctz]);
			return (k >> 12 << 12) | (ctz << 6) | ctz2;
		}
		// 上 6 桁が一致している場合、上 12 桁で一致しているものが存在しなかったので、B の部分が (k の B の部分) + 1 以上であるものを調べる
		if (B[k >> 18] >> 1 >> b(k)) {
			int ctz = b(k) + 1 + countr_zero(B[k >> 18] >> 1 >> b(k));
			int ctz2 = countr_zero(C[(k >> 18 << 6) | ctz]);
			int ctz3 = countr_zero(D[(k >> 18 << 12) | (ctz << 6) | ctz2]);
			return (k >> 18 << 18) | (ctz << 12) | (ctz2 << 6) | ctz3;
		}
		// それでも見つからない場合、A の部分が (k の A の部分) + 1 以上であるものを調べる
		if (A >> 1 >> a(k)) {
			int ctz = a(k) + 1 + countr_zero(A >> 1 >> a(k));
			int ctz2 = countr_zero(B[ctz]);
			int ctz3 = countr_zero(C[(ctz << 6) | ctz2]);
			int ctz4 = countr_zero(D[(ctz << 12) | (ctz2 << 6) | ctz3]);
			return (ctz << 18) | (ctz2 << 12) | (ctz3 << 6) | ctz4;
		}
		return -1;
	}
/*
	le(k) は集合 S に含まれ、かつ k 以下である最大の要素を返す関数です
*/
	inline int le(int k) {
		// まず、上 18 桁が一致している場合、下 6 桁が k の下 6 桁以下である最大のものを返す
		if (D[k >> 6] << (63 - d(k))) {
			return k - countl_zero(D[k >> 6] << (63 - d(k)));
		}
		// 上 12 桁が一致している場合、上 18 桁で一致しているものが存在しなかったので、C の部分が (k の C の部分) - 1 以下であるものを調べる
		if (C[k >> 12] << 1 << (63 - c(k))) {
			int clz = c(k) - 1 - countl_zero(C[k >> 12] << 1 << (63 - c(k)));
			int clz2 = 63 - countl_zero(D[(k >> 12 << 6) | clz]);
			return (k >> 12 << 12) | (clz << 6) | clz2;
		}
		// 上 6 桁が一致している場合、上 12 桁で一致しているものが存在しなかったので、B の部分が (k の B の部分) - 1 以下であるものを調べる
		if (B[k >> 18] << 1 << (63 - b(k))) {
			int clz = b(k) - 1 - countl_zero(B[k >> 18] << 1 << (63 - b(k)));
			int clz2 = 63 - countl_zero(C[(k >> 18 << 6) | clz]);
			int clz3 = 63 - countl_zero(D[(k >> 18 << 12) | (clz << 6) | clz2]);
			return (k >> 18 << 18) | (clz << 12) | (clz2 << 6) | clz3;
		}
		// それでも見つからない場合、A の部分が (k の A の部分) - 1 以下であるものを調べる
		if (A << 1 << (63 - a(k))) {
			int clz = a(k) - countl_zero(A << 1 << (63 - a(k))) - 1;
			int clz2 = 63 - countl_zero(B[clz]);
			int clz3 = 63 - countl_zero(C[(clz << 6) | clz2]);
			int clz4 = 63 - countl_zero(D[(clz << 12) | (clz2 << 6) | clz3]);
			return (clz << 18) | (clz2 << 12) | (clz3 << 6) | clz4;
		}
		return -1;
	}
};

int main() {
	int N, Q, c, k;
	string T;
	input(N, Q, T);
	wordsizetree st;
	for (int i = 0; i < N; i++) {
		if (T[i] == '1') {
			st.add(i);
		}
	}
	while (Q--) {
		input(c, k);
		if (c == 0) {
			if (!st.in(k)) st.add(k);
		}
		if (c == 1) {
			if (st.in(k)) st.erase(k);
		}
		if (c == 2) {
			print(st.in(k));
		}
		if (c == 3) {
			print(st.ge(k));
		}
		if (c == 4) {
			print(st.le(k));
		}
	}
}