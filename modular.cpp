// Darpan Deka
// 2112041
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

#include<bits/stdc++.h>
using namespace std;
#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define fr3(x,t,y) for(ll x=t; x>y; x--)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vpair vector<pair<ll,ll>>
#define pb push_back
#define pp pop_back
#define all(vector) vector.begin(), vector.end()
#define nn "\n" 
const ll mod = 1e9+7;
// 1101
// a*(a^2)*(a^8)
ll binary_exponentiation(ll a, ll b, ll mod){
    ll ans = 1;
    while(b){
        if(b%2==1){
            ans = (ans*a) % mod;
        }
        a = (a*a) % mod;
        b /= 2;
    }
    return ans;
}
// Calculation of inverse
// a^-1 mod p = a^(p-2) mod p

ll add(ll a, ll b){
    ll ans = (a%mod+b%mod)%mod;
    if(ans >= mod) ans -= mod;
    if(ans < 0) ans += mod;
    return ans;
}

ll sub(ll a, ll b){
    return add(a,-b);
}
ll mul(ll a, ll b){
    ll ans = ((a%mod)*(b%mod))%mod;
    if(ans < 0){
        ans += mod;
    }
    return ans;
}
ll binpow(ll a, ll b){
    a = a%mod;
    b = b%mod;
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2){
        return mul(a, binpow(a,b-1));
    }
    else
    {
        ll temp = binpow(a,b/2);
        return mul(temp,temp);
    }
}
ll inv(ll a){
    return binpow(a, mod-2);
}
ll divi(ll a, ll b){
    return mul(a,inv(b));
}
const ll N = 1000001;
ll fac[N];
ll facInv[N];

void fact(){
    fac[0] = 1;
    for(ll i=1; i<N; i++){
        fac[i] = mul(fac[i-1],i);
    }
    facInv[N-1] = inv(fac[N-1]);
    for(ll i=N-2; i>=0; i--){
        facInv[i] = mul(facInv[i+1],i+1);
    }
}

ll pow1[N];

void pow2(){
    pow1[0] = 1;
    for(ll i=1; i<N; i++){
        pow1[i] = mul(pow1[i-1],2);
    }
}

ll ncr(ll n, ll r){
    if(r<0||r>n) return 0;
    return mul(fac[n],mul(facInv[r],facInv[n-r]));
}

vll divisors(ll x){
    vll ans;
    for(ll i=1; i*i<=x; i++){
        if(x%i==0){
            ans.push_back(i);
            if(i*i != x){
                ans.push_back(x/i);
            }
        }
    }
    return ans;
}

vpair factors(ll x){
    vpair ans;
    for(ll i=2; i*i<=x; i++){
        if(x % 2 == 0){
            ll ct=0;
            while(x%i == 0){
                ct++;
                x /= i;
            }
            ans.push_back({i,ct});
        }
    }
    if(x > 1){
        ans.push_back({x,1});
    }
    return ans;
}

void OM(){
    
}

int main(){
    ll football=1;
    cin>>football;
    while(football--){
        OM();
    }

}

struct nCr{
    int mxN, M;
    vector<int> fact, ifact;
    inline int mul(int a, int b) { return a *1LL* b % M ;}
    int power(int a, int n) {
        if(n == 0) return 1 ;
        int p = power(a, n/2) % M ;
        p = mul(p, p) ;
        return n & 1 ? mul(p, a) : p ; 
    }
    int invMod(int a) {return power(a,M-2);}
    void pre() {
        fact[0] = 1 ;
        for(int i = 1;i< mxN;++i) fact[i] = mul(i, fact[i-1]) ;
        ifact[mxN-1] = invMod(fact[mxN-1]) ; 
        for(int i = mxN-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
    }
    nCr(int _mxN, int _M) {
        mxN = _mxN + 1; 
        M = _M ; 
        fact.resize(mxN) ; 
        ifact.resize(mxN) ;
        pre() ;  
    }
    int C(int n, int r) {
        if (n < r || r < 0 || n < 0) return 0;
        return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
    }
};
nCr comb(200001,mod);
