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
vector<vector<int> >ctree;
queue<int> que;

int depth[MAXN];
int par[MAXN][20];
int chk[MAXN];
int subtree[MAXN];
ll ans[MAXN];

void make_par(int here,int p)
{
    int there;

    par[here][0] = p;

    for(int i=0;i<graph[here].size();i++){
        there =graph[here][i];
        if(there==p)continue;
        depth[there] = depth[here]+1;
        make_par(there,here);
    }

    return;
}

int lca(int x,int y)
{
    if(depth[x]>depth[y])return lca(y,x);
    for(int i=19,d = depth[y]-depth[x];~i; i--)if((d>>i)&1)y = par[y][i];
    for(int i=19;~i;i--)if(par[x][i]!=par[y][i])x = par[x][i],y = par[y][i];
    return (x==y)?x:par[x][0];
}

int getdis(int x,int y)
{
    int vv = lca(x,y);
    return (depth[x]+depth[y]-(depth[vv]<<1));
}

void dfs(int here,int p)
{
    int there;

    subtree[here] = 1;

    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i];
        if(there==p)continue;
        if(chk[there])continue;
        dfs(there,here);
        subtree[here]+=subtree[there];
    }

    return;
}

int mysearch(int here,int p,int sz)
{
    int there;
    int idx = -1;
    int mx = 0;

    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i];
        if(there==p)continue;
        if(chk[there])continue;
        if(mx<subtree[there]){
            mx = subtree[there];
            idx = i;
        }
    }

    if(idx==-1){
        return here;
    }

    if((mx<<1)<=sz)return here;

    return mysearch(graph[here][idx],here,sz);
}

int getcentroid(int here,int sz,int num)
{
    if(sz==1){
        chk[here] = num;
        return here;
    }

    dfs(here,0);

    int res = mysearch(here,0,sz);

    chk[res] = num;

    int there;
    int nxtsz;
    int nxt;

    for(int i=0;i<graph[res].size();i++){
        there = graph[res][i];
        if(chk[there])continue;
        if(subtree[res]>subtree[there])nxtsz = subtree[there];
        else nxtsz = sz-subtree[res];
        nxt = getcentroid(there,nxtsz,num+1);
        //cout<<res<<" "<<nxt<<"\n";
        ctree[res].push_back(nxt);
        ctree[nxt].push_back(res);
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

    graph = vector<vector<int> > (n+1);
    ctree = vector<vector<int> > (n+1);

    for(int i=1;i<n;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    getcentroid(0,n,1);

    for(int i=0;i<n;i++)
        cout<<chk[i]<<" ";

    return 0;
}
