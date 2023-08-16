#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bll = __int128_t;
// O(√n) verified
bool is_prime(ll n){if(n<2)return false;if(n==2)return true;if(n%2==0)return false;for(ll i=3;i*i<=n;i+=2)if(n%i==0)return false;return true;}

// O(√n) verified
vector<ll>divisors(ll n){vector<ll>r;int i;for(i=1;i*i<n;i++)if(n%i==0){r.push_back(i);r.push_back(n/i);}if(i*i==n)r.push_back(i);sort(r.begin(),r.end());return r;}

// O(√n) verified
vector<pair<ll,ll>>prime_factorize(ll n){vector<pair<ll,ll>>r;int c=0;while(n%2==0){n/=2;c++;}r.push_back({2,c});for(ll p=3;p*p<=n;p+=2){if(n%p!=0)continue;int e=0;while(n%p==0){e++;n/=p;}r.push_back({p,e});}if(n!=1)r.push_back({n,1});return r;}

// エラトステネスの篩
// O(n*log(log(n))) verified
vector<bool>EraSieve(ll n){vector<bool>p(n+1,true);p[0]=p[1]=false;for(int i=2;i<=n;i++){if(!p[i])continue;for(int q=i*2;q<=n;q+=i){p[q]=false;}}return p;}

// エラトステネスの区間篩 verified
// a以上b未満のcに対してp[c - a]
vector<bool>EraSecSieve(ll a,ll b){ll sq=(ll)ceil(sqrt(b));vector<bool>ps(sq,true);ps[0]=ps[1]=false;for(ll i=2;i<sq;i++){if(!ps[i])continue;for(ll j=i*i;j<sq;j+=i)ps[j]=false;}vector<bool>p(b-a,true);for(ll i=2;i<sq;i++){if(!ps[i])continue;ll k=max(i,(a+i-1)/i);for(ll j=k*i;j<b;j+=i)p[j-a]=false;}return p;}

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