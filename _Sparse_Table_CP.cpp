#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long>
#define pb push_back
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define ef(i,s,e) for(long long int i=s;i<=e;i++)
#define endl '\n'
#define printa(arr,n) {f(i,0,n) cout<<arr[i]<<" "; cout<<endl;}
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
inline ll nxt() { ll x; cin >> x; return x; }

// Tab[i][j] = func(a[i],...,a[i+2^j -1])
ll Tab[1000001][32];
void makeTab(ll a[], ll n){
    f(i,0,n) Tab[i][0] = a[i];
    ef(j,1,log2(n)){
        ef(i,0,n-(1<<j)){
            Tab[i][j] = Tab[i][j-1] | Tab[i+(1<<(j-1))][j-1];
        }
    }
}
ll Range(ll i, ll j){
    ll lg = log2(j-i+1);
    return Tab[i][lg] | Tab[j-(1<<lg)+1][lg];
}
void display(ll n){ f(j,0,n) printa(Tab[j],log2(n)+1); }

void solve(){
    ll n = nxt();
    ll a[n]; f(i,0,n) cin>>a[i];
    makeTab(a,n);
    display(n);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll _ = nxt();
    while (_--) {
        solve();
    }
    return 0;
}
