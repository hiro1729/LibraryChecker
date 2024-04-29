#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

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
	string read_str() {
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		int rd_first = rd;
		string res;
		while (rd <= wt && !isspace(buf[rd])) {
			++rd;
			if (rd == wt) {
				res += string(buf, rd_first, wt - rd_first);
				_read();
				rd_first = 0;
			}
		}
		res += string(buf, rd_first, rd - rd_first);
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
	string read_line() {
		int ch = _chr();
		while (isspace(ch)) ch = nxchar();
		int rd_first = rd;
		string res;
		while (rd <= wt && buf[rd] != '\n') {
			++rd;
			if (rd == wt) {
				res += string(buf, rd_first, wt - rd_first);
				_read();
				rd_first = 0;
			}
		}
		res += string(buf, rd_first, rd - rd_first);
		return res;
	}
private:
	void _read() {
		ssize_t r = read(0, buf, maxsz);
		if (r < 0) {
			throw runtime_error(strerror(errno));
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
inline string String() { return sc.read_str(); }
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
inline void _SingleInput(string &s) { s = String(); }
inline void _SingleInput(char &c) { c = Char(); }
inline void _SingleInput(bool &b) { b = Bool(); }
template<class S, class T> inline void _SingleInput(pair<S, T> &p) { _SingleInput(p.first); _SingleInput(p.second); }
template<class T> inline void _SingleInput(vector<T> &v) { for (T &x: v) _SingleInput(x); }

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

void print_string(string s) {
	for (char &c: s) {
		pc_u(c);
	}
}

template<typename T> void print_double(T d) {
	print_string(to_string(d));
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
inline void _SingleOutput(string s) { print_string(s); }
inline void _SingleOutput(char c) { pc_u(c); }
inline void _SingleOutput(bool b) { pc_u(b ? '1' : '0'); }
template<class S, class T> inline void _SingleOutput(pair<S, T> p) { _SingleOutput(p.first); pc_u(' '); _SingleOutput(p.second); }
template<class T> inline void _SingleOutput(vector<T> v) { for (int i = 0; i < v.size() - 1; i++) { _SingleOutput(v[i]); pc_u(' '); } _SingleOutput(v.back()); }


void print() { pc_u('\n'); }
template<class T1, class... T2> void print(T1 t1, T2... t2) { _SingleOutput(t1); print(t2...); }

int main() {
    int t; input(t); __int128_t a, b; while (t--) { input(a, b); print(a + b); }
}