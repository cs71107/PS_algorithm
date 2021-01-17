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
vector<vector<int> >rgraph;
vector<vector<int> >scc;
queue<int> que;

/*kosaraju method*/
stack<int> ord;
bool visited[MAXN];
//int ans[MAXN];
//int P[MAXN];
int num_scc;
int sccindex[MAXN];

bool cmp(int a,int b)
{
    return sccindex[a]<sccindex[b];
}

void dfs(int here)
{
    visited[here] = true;

    int there;

    for(int i=0;i<graph[here].size();i++)
    {
        there = graph[here][i];
        if(visited[there])continue;
        dfs(there);
    }

    ord.push(here);

    return;
}

void rdfs(int here)
{
    visited[here] = true;

    int there;

    for(int i=0;i<rgraph[here].size();i++)
    {
        there = rgraph[here][i];
        if(visited[there])continue;
        rdfs(there);
    }

    scc[num_scc].push_back(here);
    sccindex[here] = num_scc;

    return;
}

void make_scc(int n)
{
    for(int i=1;i<=n;i++)
        visited[i] = false;

    int here;

    while(!ord.empty()){

        here = ord.top(); ord.pop();
        if(visited[here])continue;

        rdfs(here);
        num_scc++;
    }

    return;
}

void kosaraju(int n){
    /*intialize*/
    fill(visited,visited+n+1,false);
    fill(sccindex,sccindex+n+1,-1);
    while(!ord.empty())ord.pop();
    num_scc = 0;

    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i);
    }
    make_scc(n);
}

int main()
{
    int n,m,k,a,b,x,y,x_,y_;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    bool res = true;

    cin>>n>>m;

    graph = vector<vector<int> > (2*n+1);
    rgraph = vector<vector<int> > (2*n+1);
    scc = vector<vector<int> > (2*n+1);

    for(int i=0;i<m;i++){
        cin>>x>>y;
        /*build graph*/
    }

    kosaraju(2*n);

    res = true;

    for(int i=1;i<=n;i++){
        x = 2*i-1; y = 2*i;
        if(sccindex[x]==sccindex[y]){
            res = false; break;
        }
    }
    /*
    for(int i=1;i<=2*n;i++)P[i] = i;

    sort(P+1,P+2*n+1,cmp);

    fill(ans+1,ans+2*n+1,-1);

    for(int i=1;i<=2*n;i++){
        cur = P[i];
        if(ans[(cur+1)>>1]==-1)ans[(cur+1)>>1] = !(cur&1);
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i];
    */
    return 0;
}

