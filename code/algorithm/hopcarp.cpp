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
const int MAXM = 1e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
int B[MAXN];
int dist[MAXN];
bool used[MAXN];

void bfs(int n){

    for(int i=0;i<n;i++){
        if(!used[i]){
            dist[i] = 0;
            que.push(i);
        }
        else dist[i] = INF;
    }

    while(!que.empty()){

        int a = que.front(); que.pop();

        for(int b:graph[a]){
            if(B[b]!=-1&&dist[B[b]]==INF){
                dist[B[b]] = dist[a]+1;
                que.push(B[b]);
            }
        }

    }
    return;
}

bool dfs(int a)
{
    for(int b:graph[a]){
        if(B[b]==-1||(dist[B[b]]==dist[a]+1&&dfs(B[b]))){
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int getans(int n)
{
    fill(A,A+MAXM,-1);
    fill(B,B+MAXM,-1);
    fill(used,used+MAXM,false);

    int flow = 0;
    int res = 0;

    while(1){

        bfs(n);

        flow = 0;
        for(int i=0;i<n;i++)
            if(!used[i]&&dfs(i))flow++;

        if(flow==0)break;
        res+=flow;
    }

    return res;
}

void chk(int a){
    visited[a] = true;
    if(a>=MAXM&&!visited[B[a-MAXM]])chk(B[a-MAXM]);
    else {
        for(int b:graph[a]){
            if(B[b]!=a&&!visited[b+MAXM])chk(b+MAXM);
        }
    }
}
int main()
{
    int n,m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int server;
    int res = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*build_graph*/


    return 0;
}

