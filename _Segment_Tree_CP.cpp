#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long>
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define ef(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define erf(i,e,s) for(long long int i=e;i>=s;i--)
#define endl '\n'
#define printa(arr,n) {f(i,0,n) cout<<arr[i]<<" "; cout<<endl;}
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
inline ll nxt() { ll x; cin >> x; return x; }

class SegTree{
public:
    vll T; ll st, size;
    SegTree(ll arr[], ll n, ll fill = 0){
        ll logn = ceil(log2(n)); st = 1<<logn; size = 2*st-1; ll l = st/2;
        T.resize(size+1,0);

        f(i,0,n) T[st + i] = arr[i]; ef(i,st+n,size) T[i] = fill; // Populate
        rf(i,2*l,1) T[i] = T[2*i] + T[2*i + 1];
    }
    SegTree(vll arr, ll fill = 0){
        ll n = arr.size();
        ll logn = ceil(log2(n)); st = 1<<logn; size = 2*st-1; ll l = st/2;
        T.resize(size+1,0);

        f(i,0,n) T[st + i] = arr[i]; ef(i,st+n,size) T[i] = fill; // Populate
        rf(i,2*l,1) T[i] = T[2*i] + T[2*i + 1];
    }
    ~SegTree(){}
    void update(ll idx, ll val){
        ll i = st + idx; ll ch = val - T[i];
        while(i > 0) { T[i] += ch; i /= 2; }
    }
    ll request(ll l, ll r){
        l = st+l; r = st+r;
        if(l == r) return T[l];
        ll sum = T[l] + T[r];
        while(l/2 != r/2){
            if(!(l&1)) { sum += T[l+1]; }
            if(r&1) { sum += T[r-1]; }
            l /= 2; r /= 2;
        }
        return sum;
    }
    void display(){
        cout<<st<<" | "<<size<<" | "<<endl;
        ef(i,1,size){
            cout<<T[i]<<" ";
            if(ceil(log2(i+1)) == floor(log2(i+1))) cout<<endl;
        }
    }
};

void solve(){
    ll n = nxt();
    vll a(n,0); f(i,0,n) cin>>a[i];
    SegTree T(a);
    T.display();
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll _ = nxt();
    while (_--) {
        solve();
    }
    return 0;
}

// st = start index of the array in tree
// size = size of tree
// arr = given array
// n = arr.size
// fill = default value for padding elements
// Populate : Populates the internal nodes
// update : Updates a particular index
// idx = index of element in arr
// request : returns requested value for [l,r] subarray
// l,r = indices in arr

/*
root node of tree = 1
Tree has 1 based indexing
array has 0 based indexing
*/