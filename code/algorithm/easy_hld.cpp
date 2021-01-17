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
const int MAXN = 5e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;

queue<int> que;

int in[MAXN];
int sz[MAXN];
int top[MAXN];
int par[MAXN][22];
int depth[MAXN];

vector<vector<int> > graph;
vector<vector<int> > tgraph;
vector<ll> tree;
vector<plii> lazy;

void t_dfs(int here,int p)
{
    int there;

    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i];
        if(there==p)continue;
        depth[there] = depth[here]+1;
        par[there][0] = here;
        t_dfs(there,here);
        tgraph[here].push_back(there);
    }
    return;
}

void dfs_sz(int here)
{
    sz[here] = 1;

    int there;

    for(int i=0;i<tgraph[here].size();i++){
        there = tgraph[here][i];
        dfs_sz(there);
        sz[here]+=sz[there];
        if(sz[there]>sz[tgraph[here][0]])swap(tgraph[here][i],tgraph[here][0]);
    }

}
int n;
int seq;

int lca(int x,int y)
{
    if(depth[x]>depth[y])return lca(y,x);
    for(int i=19,d = depth[y]-depth[x];~i; i--)if((d>>i)&1)y = par[y][i];
    for(int i=19;~i;i--)if(par[x][i]!=par[y][i])x = par[x][i],y = par[y][i];
    return (x==y)?x:par[x][0];
}

void dfs_hld(int here)
{
    in[here] = seq++;

    int there;

    for(int i=0;i<tgraph[here].size();i++){
        there = tgraph[here][i];

        if(!i)top[there] = top[here];
        else top[there] = there;

        dfs_hld(there);
    }
}

int main()
{
    ll m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    graph = vector<vector<int> > (n+1);
    tgraph = vector<vector<int> > (n+1);

    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    t_dfs(1,0);
    dfs_sz(1);
    dfs_hld(1);

    for(int j=1;j<=19;j++)
        for(int i=1;i<=n;i++)
            par[i][j] = par[par[i][j-1]][j-1];

    ll res = 0;


    return 0;
}

