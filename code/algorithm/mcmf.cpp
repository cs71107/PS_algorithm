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
queue<int> que;

struct Edge{
    int to,c,w,F;
    Edge *dual;
    Edge(): Edge(-1,0,0){};
    Edge(int to1,int c1,int w1): to(to1), c(c1), w(w1), F(0), dual(nullptr){}
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
int dist[MAXN];
bool inque[MAXN];

void buildedge(int a,int b,int cab,int cba,int wab,int wba)
{
    Edge *e1,*e2;

    e1 = new Edge(b,cab,wab);
    e2 = new Edge(a,cba,wba);
    e1->dual = e2;
    e2->dual = e1;
    graph[a].push_back(e1);
    graph[b].push_back(e2);

    return;
}


int main()
{
    int n,m,k,a,b,x,y,w;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    while(scanf("%d%d",&n,&m)!=EOF){

        graph = vector<vector<Edge*> > (n*2);

        for(int i=1;i<n-1;i++)
            buildedge(i*2,i*2+1,1,0,0,0);

        buildedge(0,1,2,0,0,0);
        buildedge(2*n-2,2*n-1,2,0,0,0);

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&w);
            a--; b--;
            buildedge(a*2+1,b*2,1,0,w,-w);
        }

        int here,there;
        int st = 0,en = 2*n-1;
        int res = 0;

        for(int runs=0;runs<2;runs++){

            fill(pre,pre+2*n,-1);
            fill(dist,dist+2*n,INF);
            fill(inque,inque+2*n,false);
            Edge *path[2*n] = {0};

            dist[st] = 0;
            inque[st] = true;
            que.push(st);

            while(!que.empty()){

                here = que.front(); que.pop();
                inque[here] = false;

                for(Edge *e:graph[here]){
                    there = e->to;
                    if(e->spare()>0&&dist[there]>dist[here]+(e->w)){
                        dist[there] = dist[here]+(e->w);
                        pre[there] = here;
                        path[there] = e;
                        if(!inque[there]){
                            que.push(there);
                            inque[there] = true;
                        }
                    }
                }
            }

            if(pre[en]==-1)break;

            for(int i=en;i!=st;i = pre[i])
            {
                path[i]->addflow(1);
                res+=(path[i]->w);
            }
        }

        printf("%d\n",res);
    }

    return 0;
}
