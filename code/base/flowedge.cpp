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


struct Edge{
    int to,c,F;
    Edge *dual;
    Edge(): Edge(-1,0){};
    Edge(int to1,int c1): to(to1), c(c1), F(0), dual(nullptr){}
    int spare(){
        return c-F;
    }
    void addflow(int f1){
        F += f1;
        dual->F-=f1;
    }
};

vector<vector<Edge*> >graph;

int pre[MAXN];

void buildedge(int a,int b,int wab,int wba)
{
    Edge *e1,*e2;

    e1 = new Edge(b,wab);
    e2 = new Edge(a,wba);
    e1->dual = e2;
    e2->dual = e1;
    graph[a].push_back(e1);
    graph[b].push_back(e2);

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
