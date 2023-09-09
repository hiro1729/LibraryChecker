#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bll = __int128_t;

// PollardRhoまでverified

template<class T>T modpow(T a,T n,T m){T r=1;while(n){if(n&1)r=r*a%m;a=a*a%m;n>>=1;}return r;}

// 失敗率 1/(4^30)
bool MillerRabin(ll n) {if(n==2)return true;if(n==1||(n>2&&n%2==0))return false;ll s=0,t=n-1;while(t%2==0){s++;t>>=1;}random_device gen;mt19937_64 mtrand(gen());for(int i=0;i<30;i++){ll a=(mtrand())%(n-1)+1;if(a%n==0)continue;bool ok=false;if(modpow<bll>(a,t,n)==1)ok=true;else for(int i=0;i<s;i++)if(modpow<bll>(a,modpow<bll>(2,i,1ull<<63)*t,n)==n-1){ok=true;break;}if(!ok)return false;}return true;}

ll _findprime(ll n){if(n%2==0)return 2;for(int c=1;c<n;c++){auto f=[&](ll a)->ll {return((bll)a*a+c)%n;};ll x=0,y=0,g=1;while(g==1){x=f(x);y=f(f(y));g=gcd(abs(x-y),n);}if(g==n)continue;if(MillerRabin(g))return g;else if(MillerRabin(n/g))return n/g;else return _findprime(g);}}

vector<pair<ll,ll>>PollardRho(ll n){vector<pair<ll,ll>>r;while(!MillerRabin(n)&&n>1){ll p=_findprime(n),s=0;while(n%p==0){n/=p;s++;}r.push_back({p,s});}if(n>1)r.push_back({n,1});return r;}

int main() {
    int q; ll a;
    cin >> q;
    while (cin >> a) {
        auto p = PollardRho(a);
        vector<ll> ans;
        for (auto i: p) {
            for (int j = 0; j < i.second; j++) ans.push_back(i.first);
        }
        sort(ans.begin(), ans.end());
        int s = ans.size();
        cout << s;
        for (int i = 0; i < s; i++) cout << ' ' << ans[i];
        cout << '\n';
    }
}