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

int A[MAXN];
char S[MAXN];

void update(int tmp,int v)
{
    while(tmp){
        tree[tmp]+=v;
        tmp>>=1;
    }

    return;
}

int getans(int L,int R)
{
    int res = 0;

    while(L<=R){
        if(L&1){res+=tree[L]; L++;}
        if(!(R&1)){res+=tree[R]; R--;}
        L>>=1; R>>=1;
    }

    return res;
}

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

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    return 0;
}
