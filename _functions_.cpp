#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define vll vector<ll>
#define V(T) vector<T>
#define pb push_back
#define f(i,s,e) for(ll i=s;i<e;i++)
#define ef(i,s,e) for(ll i=s;i<=e;i++)
#define rf(i,e,s) for(ll i=e-1;i>=s;i--)
#define erf(i,e,s) for(ll i=e;i>=s;i--)
/* Returns all the factors of a number 'n' as a vector */
vll factor(ll n)
{
    vll ans, v;
    ef(i,1,sqrt(n)){
        if(!(n%i)){
            ans.pb(i);
            if(n/i != i) v.pb(n/i);
        }
    }
    reverse(all(v));
    for(auto u:v) ans.pb(u);
    return ans;
}
// Time Complexity : O(√n)
// Space Complexity : O(√n)

/* Returns the prime factorisation of a number 'n' as a vector */
vll factorise(int n) 
{
    vll ans;
    ef(i,2,sqrt(n)){
        while(!(n%i)){
            ans.pb(i);
            n /= i;
        }
    }
    if (n > 2) ans.pb(n);
    return ans;
}
// Time Complexity : O(√n)
// Space Complexity : O(√n)

/* Returns all primes <= n, for a given number 'n' as a vector */
vll allPrimes(ll n)
{
    vll ans;
    bool prime[n+1];
    ef(i,0,n) prime[i] = true;
    ef(i,2,sqrt(n)) if(prime[i]) for(ll j=i*i; j<=n; j += i) prime[j] = false;
    ef(i,2,n) if(prime[i]) ans.pb(i);
    return ans;
}
// Time Complexity : O(nlog(log(n)))
// Space Complexity : O(num_of_primes)


/* Returns n! mod M for given numbers 'n' and 'M' */
// Constraints: 0 <= n <= 25, for M = INF
ll factorial(ll n, ll M) 
{ 
    ll ans = 1;
    ef(i,2,n) ans = (ans*i)%M; 
    return ans; 
}
// Time Complexity : O(n)
// Space Complexity : O(1)

/* Returns nCr mod M for given numbers 'n', 'r', and 'M' */
ll nCr(ll n, ll r, ll M)
{
    if(r>n) return 0;
    if (r>n-r) r = n-r;
    ll a[r];
    ef(i,n-r+1,n) a[i+r-n-1] = i;
    ll ans = 1;
    ef(k,1,r){
        ll j=0, i=k;
        while(j<r){
            ll x = gcd(i,a[j]);
            if(x>1) { a[j] /= x; i /= x; }
            if(i==1) break;
            j++;
        }
    }
    f(i,0,r) ans = (ans*a[i])%M;
    return ans;
}

/* Returns (b^e)%M */
ll power(ll b, ll e, ll M){
    if(b == 1 || e == 0) return 1;
    if(b == 0) return 0;
    ll p = power(b,e/2,M);
    p = (p*p)%M;
    if(e&1) p = (p*b)%M;
    return p;
}

// Matrix functions
V(vll) Id = {
                {1,0,0,0,0,0},
                {0,1,0,0,0,0},
                {0,0,1,0,0,0},
                {0,0,0,1,0,0},
                {0,0,0,0,1,0}, 
                {0,0,0,0,0,1}, 
            };
V(vll) Z = {
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0}, 
                {0,0,0,0,0,0}, 
            };
V(vll) operator*(V(vll) &A, V(vll) &B){
    ll n = A.size(), m = A[0].size(), p = B[0].size();
    V(vll) C(n,vll(p,0));
    f(i,0,n) f(j,0,p) f(k,0,m) C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) %mod) %mod;
    return C;
};
bool operator==(V(vll) &A, V(vll) &B){
    ll n = A.size(), m = A[0].size();
    ll p = B.size(), q = B[0].size();
    if(n != p || m != q) return false;
    f(i,0,n) f(j,0,m) if(A[i][j] != B[i][j]) return false;
    return true;
}
V(vll) power(V(vll) &A, ll e){
    if(e == 0 || A == Id) return Id;
    if(A == Z) return Z;
    V(vll) P = power(A,e/2);
    P = P*P;
    if(e&1) P = P*A;
    return P;
}
