#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define sec second
#define mkpr make_pair
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mapll map<long long, long long>
#define mapii map<int, int>
#define mapci map<char, int>
#define mapcl map<char, long long>
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define ef(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define erf(i,e,s) for(long long int i=e;i>=s;i--)
#define endl '\n'
#define fitr(it,end,v) {for(it = v.begin(); it!=end; it++) cout<< *it<<" "; cout<<endl;}
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printa(arr,n) {f(ind,0,n) cout<<arr[ind]<<" "; cout<<endl;}
#define inp(arr,n) {f(ind,0,n) cin>>arr[ind];}
#define INF INT_MAX
#define inf INT_MIN
#define BINF LLONG_MAX
#define binf LLONG_MIN
#define P(S,T) pair<S,T>
#define V(T) vector<T>
#define UM(S,T) unordered_map<S,T>
#define M(S,T) map<S,T>
#define PQ(T) priority_queue<T>
#define PQC(T,C) priority_queue<T,vector<T>,C>
#define Q(T) queue<T>
#define ST(T) stack<ll>

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));i++) if (a%i==0) return 0; return 1; }
inline ll nxt() { ll x; cin >> x; return x; }

void solve(){
    ll n; cin>>n;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll _ = nxt(); while (_--)
    solve();
    return 0;
}