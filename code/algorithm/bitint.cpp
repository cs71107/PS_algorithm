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
int B[MAXN];
int ans[MAXN];
char S[MAXN];
char T[MAXN];

int main()
{
    int n,m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    cin>>S;
    cin>>T;

    n = strlen(S);
    m = strlen(T);

    for(int i=0;i<n;i++)
        A[n-1-i] = S[i]-'0';
    for(int i=0;i<m;i++)
        B[m-1-i] = T[i]-'0';

    for(int i=0;i<=max(n,m);i++)
    {
        ans[i] = A[i]+B[i];
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }

    int len = max(n,m)+1;
    if(!ans[len-1])len--;

    for(int i=len-1;i>=0;i--)
        cout<<ans[i];

    return 0;
}
