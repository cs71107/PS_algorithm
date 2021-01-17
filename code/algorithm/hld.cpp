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
const int MAXN = 1e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<pii> > graph;
vector<vector<int> > segtree;
vector<vector<pii> > hld;
queue<int> que;

int depth[MAXN];
int par[MAXN];
int sz[MAXN];
int spa[MAXN][20];
int ex[MAXN];
int ey[MAXN];
int base[MAXN];
pii id[MAXN];

int dfs(int here,int p){

    par[here] = p;
    sz[here] = 1;

    int there;

    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i].f;
        if(there==p)continue;
        depth[there] = depth[here]+1;
        sz[here]+=dfs(there,here);
    }
    return sz[here];
}

int hldsz;

void gethld(int here,int val,int cur)
{
    hld[cur].push_back(pii(here,val));

    int heavy = 0,mx = 0;
    int there;

    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i].f;
        if(par[here]==there)continue;
        if(mx<sz[there]){heavy = there; mx = sz[there];}
    }
    for(int i=0;i<graph[here].size();i++){
        there = graph[here][i].f;
        if(par[here]==there)continue;
        if(there==heavy)gethld(there,graph[here][i].s,cur);
        else {
            hldsz++;
            gethld(there,graph[here][i].s,hldsz-1);
        }
    }
}

int lca(int x,int y)
{
    if(depth[x]>depth[y])return lca(y,x);
    for(int i=19,d = depth[y]-depth[x];~i; i--)if((d>>i)&1)y = spa[y][i];
    for(int i=19;~i;i--)if(spa[x][i]!=spa[y][i])x = spa[x][i],y = spa[y][i];
    return (x==y)?x:spa[x][0];
}

int getsum(int k,int L,int R)
{
    L+=base[k];
    R+=base[k];

    int res = 0;

    while(L<=R){
        if(L&1)res=max(res,segtree[k][L]);
        if(!(R&1))res=max(res,segtree[k][R]);
        L++; R--;
        L>>=1; R>>=1;
    }

    return res;
}

int down(int x,int p){
    if(id[x].f==id[p].f)return getsum(id[x].f,id[p].s+1,id[x].s);
    return max(getsum(id[x].f,0,id[x].s),down(par[hld[id[x].f][0].f],p));
}

int query(int x,int y){
    int l = lca(x,y);
    return max(down(x,l),down(y,l));
}

void update(int k,int tmp,int val)
{
    tmp+=base[k];
    segtree[k][tmp] = val;
    tmp>>=1;
    while(tmp){
        segtree[k][tmp] = max(segtree[k][tmp*2],segtree[k][tmp*2+1]);
        tmp>>=1;
    }
    return;
}

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    graph = vector<vector<pii> > (n+1);
    hld = vector<vector<pii> > (MAXN);

    for(int i=1;i<n;i++)
    {
        cin>>x>>y>>a;
        ex[i] = x; ey[i] = y;
        graph[x].push_back(pii(y,a));
        graph[y].push_back(pii(x,a));
    }
	/*update edge query in tree*/
	
    depth[1] = 1;
    dfs(1,1);

    hldsz++;

    gethld(1,0,0);

    for(int i=0;i<hldsz;i++)
        for(int j=0;j<hld[i].size();j++)
            id[hld[i][j].f] = pii(i,j);

    for(int i=1;i<=n;i++)spa[i][0] = par[i];
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)
            spa[i][j] = spa[spa[i][j-1]][j-1];

    int sz = 0;

    segtree = vector<vector<int> > (hldsz);

    for(int i=0;i<hldsz;i++){

        sz = hld[i].size();
        base[i] = 1;
        for(;base[i]<sz;base[i]<<=1);

        segtree[i].resize(base[i]*2);

        for(int j=0;j<sz;j++)
            segtree[i][j+base[i]] = hld[i][j].s;

        for(int j=base[i]-1;j>=1;j--)
            segtree[i][j] = max(segtree[i][j*2],segtree[i][j*2+1]);
    }

    cin>>q;

    while(q--){

        cin>>a>>x>>y;
        if(a==1){
            x = depth[ex[x]]<depth[ey[x]]?ey[x]:ex[x];
            update(id[x].f,id[x].s,y);
        }
        else cout<<query(x,y)<<"\n";
    }


    return 0;
}
