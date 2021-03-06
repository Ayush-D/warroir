//  https://forthright48.blogspot.com/search/label/GCD
//  https://cp-algorithms.com/algebra/phi-function.html

#include <bits/stdc++.h>
using namespace std;

//(a + b)%c
template<typename T> T add(T a, T b, T c){T x=a+b;return (x>=c ? x-c : x);}
//(a - b)%c
template<typename T> T sub(int a, int b, int c) { int res = a - b; return (res < 0 ? res + c : res);}

//(a * b) % c
int mul(int a, int b, int c){long long res=(long long)a*b;return(res>=c?res%c:res);}

template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
//(a - b) % c
template<typename T> T mod_neg(T a, T b) {a=mod(a, b);if(a<0){a+=b;}return a;}
//(a * b) % c for very large numbers, to avoid overflows
//O(1) hack taken from http://codeforces.com/blog/entry/15884
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
//(a ^ n)
//Complexity: O(log (n))
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
//(a ^ n) % m
//Complexity : O(log (n))
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T powerL(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}

template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
//gcd of 2 numbers a, b
//Complexity: O(log(max(a, b)))
template<typename T> T gcd(T a, T b) { return (b ? __gcd(a,b) : a); }
//lcm of 2 numbers a and b
//Complexity: O(log(max(a, b)))
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}


#define FOR(i,x,y) for(long i = (x) ; i <= (y) ; ++i)

long phi[10000005];   //Using totient function
bool prime[10000005];
long primer[10000005];  //Calculate number of prime no. till n.

void precal( int n ) {
    ///Calculate phi from 1 to n using sieve it's diff approach than https://cp-algorithms.com/algebra/phi-function.html
    FOR(i,1,n) phi[i] = i;
    FOR(i,2,n) {
        if ( phi[i] == i ) {
            for ( int j = i; j <= n; j += i ) {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}

void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    long cnt=0;
    for(int i=2;i<=n;i++){
        if(prime[i]){
          cnt++;
        }
        primer[i]=cnt;
    }
}

long factorial(int n)
{
    if (n == 0)
      return 1;
    return n*factorial(n-1);
}

int main(int argc, char const *argv[])
{ //required precomputation
  precal( 10000005 );
  SieveOfEratosthenes(10000005);
  
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    
  }
  return 0;
}

//Binary Search Errichto Ques TCO link : https://community.topcoder.com/stat?c=problem_statement&pm=14397
Div2 Medium: LastDigit and it Uses bianry Search for Big Numbers 
Explanaion:
It's helpful to notice that we can write the formula for S as: S(X)=X+⌊X10⌋+⌊X100⌋+.... Now it becomes obvious that the function S(X) is strictly increasing (because every component like ⌊X10⌋ is increasing).

So we want to find such x that f(x)=y for some particular y. It's a standard problem for increasing functions, for which we can binary search the value x. In the code you will need the function to calculate f(x), i.e. the function for finding S.

    //Code
long f(long X) {
    long S = 0;
    while(X > 0) {
        S += X;
        X /= 10;
    }
    return S;
}
public long findX(long S) {
    // binary search
    long low = 1, high = 1000000000L * 1000000000;
    while(low < high) {
        long mid = (low + high) / 2;
        if(f(mid) < S) low = mid + 1;
        else high = mid;
    }
    if(f(low) == S) return low;
    return -1;
}
