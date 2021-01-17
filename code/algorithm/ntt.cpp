#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

/*cubelover*/

const int A = 3, B = 18, P = A<<B|1, R = 11;
const int SZ = 18, N = 1<<SZ;

ll mypow(ll n,ll m)
{
    ll res = 1;
    while(m){
        if(m&1)res = (res*n)%P;
        n = (n*n)%P;
        m>>=1;
    }
    return res;
}

void NTT(ll *a, bool f) {
    int i, j;
    ll k, x, y, z;

    j = 0;
    for (i = 1; i < N; i++) {
        for (k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k;
        if (i < j) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    for (i = 1; i < N; i <<= 1) {
        x = mypow(f ? mypow(R, P - 2) : R, P / i >> 1);
        for (j = 0; j < N; j += i << 1) {
            y = 1;
            for (k = 0; k < i; k++) {
                z = a[i | j | k] * y % P;
                a[i | j | k] = a[j | k] - z;
                if (a[i | j | k] < 0) a[i | j | k] += P;
                a[j | k] += z;
                if (a[j | k] >= P) a[j | k] -= P;
                y = y * x % P;
            }
        }
    }
    if (f) {
        j = mypow(N, P - 2);
        for (i = 0; i < N; i++) a[i] = a[i] * j % P;
    }
}

ll X[N];
ll Y[N];
ll Z[N];
ll ans[P];

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    ll bi = 1;
    ll bii = 1;
    ll biii = 1;

    ll mo = R;
    ll di = R*R;
    ll tri = R*R*R;

    for(int i=0;i<=n;i++)
    {
        cin>>X[i];
        Y[i] = (X[i]*bi)%P;
        Z[i] = (X[i]*bii)%P;
        bi*=mo;
        bii*=di;
        bi%=P;
        bii%=P;
    }

    ans[0] = X[0];

    NTT(X,false);
    NTT(Y,false);
    NTT(Z,false);

    bi = mo;
    bii = di;

    for(int i=0;i<N;i++){
        ans[biii] = X[i];
        ans[bi] = Y[i];
        ans[bii] = Z[i];
        bi*=tri;
        bi%=P;
        bii*=tri;
        bii%=P;
        biii*=tri;
        biii%=P;
    }

    cin>>m;

    for(int i=0;i<m;i++){
        cin>>x;
        cout<<ans[x]<<"\n";
    }
    return 0;
}
