#include <bits/stdc++.h>
#include <unistd.h>

namespace hiro1729 {

namespace fastio {

namespace fastin {

namespace reader {

const size_t buf_size = 1 << 18;
char buf[buf_size];
ssize_t wt = 0, rd = 0;

void _read() {
	ssize_t r = read(0, buf, buf_size);
	wt = r;
	rd = 0;
}

inline int _chr() {
	if (rd == wt) [[unlikely]] {
		_read();
	}
	return buf[rd];
}

inline int nxchar() {
	++rd;
	if (rd == wt) _read();
	return _chr();
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

} // namespace reader

inline short Short() { return reader::read_int<short>(); }
inline unsigned short UShort() { return reader::read_int<unsigned short>(); }
inline int Int() { return reader::read_int<int>(); }
inline unsigned int UInt() { return reader::read_int<unsigned int>(); }
inline long Long() { return reader::read_int<long>(); }
inline unsigned long ULong() { return reader::read_int<unsigned long>(); }
inline long long LLong() { return reader::read_int<long long>(); }
inline unsigned long long ULLong() { return reader::read_int<unsigned long long>(); }
inline __int128_t Int7() { return reader::read_int<__int128_t>(); }
inline __uint128_t UInt7() { return reader::read_int<__uint128_t>(); }
inline float Float() { return reader::read_flt<float>(); }
inline double Double() { return reader::read_flt<double>(); }
inline long double LDouble() { return reader::read_flt<long double>(); }
inline std::string String() { return reader::read_str(); }
inline char Char() { return reader::read_chr(); }
inline bool Bool() { return reader::read_chr() == '1'; }

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

} // fastin

namespace fastout {

namespace writer {

const size_t buf_size = 1 << 18;
char buf[buf_size];
ssize_t wt = 0;

void _write() {
	write(1, buf, wt);
	wt = 0;
}

inline void wtchar(char c) {
	if (wt == buf_size - 1) [[unlikely]] {
		_write();
	}
	buf[wt++] = c;
}

template<typename T> inline void print_int(T n) {
	if (n == 0) {
		wtchar('0');
		return;
	}
	if (n < 0) {
		wtchar('-');
		n = -n;
	}
	if (wt + 41 > buf_size) _write();
	char m[41];
	int i = 40;
	for (; n > 0; i--) {
		m[i] = '0' + n % 10;
		n /= 10;
	}
	memcpy(buf + wt, m + i + 1, 40 - i);
	wt += 40 - i;
}

void print_char(char c) {
	wtchar(c);
}

void print_string(std::string s) {
	for (char &c: s) {
		wtchar(c);
	}
}

template<typename T> void print_double(T d) {
	print_string(std::to_string(d));
}

struct _writer_atexit {
	_writer_atexit() {
		atexit(_write);
	}
} _wt_atexit;

} // writer

inline void _SingleOutput(short n) { writer::print_int<short>(n); }
inline void _SingleOutput(unsigned short n) { writer::print_int<unsigned short>(n); }
inline void _SingleOutput(int n) { writer::print_int<int>(n); }
inline void _SingleOutput(unsigned int n) { writer::print_int<unsigned int>(n); }
inline void _SingleOutput(long n) { writer::print_int<long>(n); }
inline void _SingleOutput(unsigned long n) { writer::print_int<unsigned long>(n); }
inline void _SingleOutput(long long n) { writer::print_int<long long>(n); }
inline void _SingleOutput(unsigned long long n) { writer::print_int<unsigned long long>(n); }
inline void _SingleOutput(__int128_t n) { writer::print_int<__int128_t>(n); }
inline void _SingleOutput(__uint128_t n) { writer::print_int<__uint128_t>(n); }
inline void _SingleOutput(float d) { writer::print_double<float>(d); }
inline void _SingleOutput(double d) { writer::print_double<double>(d); }
inline void _SingleOutput(long double d) { writer::print_double<long double>(d); }
inline void _SingleOutput(std::string s) { writer::print_string(s); }
inline void _SingleOutput(char c) { writer::wtchar(c); }
inline void _SingleOutput(bool b) { writer::wtchar(b ? '1' : '0'); }
template<class S, class T> inline void _SingleOutput(std::pair<S, T> p) { _SingleOutput(p.first); writer::wtchar(' '); _SingleOutput(p.second); }
template<class T> inline void _SingleOutput(std::vector<T> v) { for (int i = 0; i < v.size() - 1; i++) { _SingleOutput(v[i]); writer::wtchar(' '); } _SingleOutput(v.back()); }

void print() { writer::wtchar('\n'); }
template<class T1, class... T2> void print(T1 t1, T2... t2) { _SingleOutput(t1); writer::wtchar(' '); print(t2...); }

} // namespace fastout

} // namespace fastio

} // namespace hiro1729

using hiro1729::fastio::fastin::input;
using hiro1729::fastio::fastout::print;

int main() {
	int T;
	__int128_t A, B;
	input(T);
	while (T--) {
		input(A, B);
		print(A + B);
	}
}