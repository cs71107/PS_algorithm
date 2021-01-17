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
vector<vector<int> > graph;
queue<int> que;

char S[MAXN];

struct node{
    node *L,*R;
    int x;
}T[11050000],*A[MAXN];
int Tn,n;

void Add(node *p,node *q,int x,int y){

    p->x = q->x+1;

    if(y<0)return;

    if(x>>y&1){
        p->R = T + ++Tn;
        p->L = q->L;
        Add(p->R,q->R,x,y-1);
    }
    else {
        p->L = T + ++Tn;
        p->R = q->R;
        Add(p->L,q->L,x,y-1);
    }
}

int Xor(node *p,node *q,int x,int y)
{
    if(y<0)return 0;
    if(x>>y & 1?p->L->x==q->L->x:p->R->x!=q->R->x)return (1<<y)|Xor(p->R,q->R,x,y-1);
    return Xor(p->L,q->L,x,y-1);
}

int getsum(node *p,int x,int y)
{
    if(y<0)return 0;
    if(x>>y&1)return p->L->x+getsum(p->R,x,y-1);
    return getsum(p->L,x,y-1);
}

int Kth(node *p, node *q,int x, int y)
{
    if(y<0)return 0;
    if(p->L->x - q->L->x<x)return (1<<y)| Kth(p->R,q->R,x - p->L->x+q->L->x,y-1);
    return Kth(p->L,q->L,x,y-1);
}

int main()
{
    int m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m;

    for(int i=1;i<1<<19;i++){
        T[i].L = T+(i<<1);
        T[i].R = T+(i<<1|1);
    }

    A[n=0] = T+1;
    Tn = 1<<20;

    while(m--){
        cin>>idx;
        if(idx==1){
            cin>>k;
            A[++n] = T + ++Tn;
            Add(A[n],A[n-1],k,18);
        }
        else if(idx==2){
            cin>>a>>b>>k;
            cout<<Xor(A[b],A[a-1],k,18)<<"\n";
        }
        else if(idx==3){
            cin>>k;
            n-=k;
        }
        else if(idx==4){
            cin>>a>>b>>k;
            cout<<getsum(A[b],k+1,18)-getsum(A[a-1],k+1,18)<<"\n";
        }
        else {
            cin>>a>>b>>k;
            cout<<Kth(A[b],A[a-1],k,18)<<"\n";
        }
    }

    return 0;
}
