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
const int MAXN = 1e6+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

/*justices_Hui*/

struct Node{
    ll mx,mx2,cntmx,sum;
};

ll A[MAXN];
Node tree[MAXN*4];

Node f(Node a,Node b){
    if(a.mx == b.mx)return {a.mx,max(a.mx2,b.mx2),a.cntmx+b.cntmx,a.sum+b.sum};
    if(a.mx>b.mx)swap(a,b);
    return {b.mx,max(a.mx,b.mx2),b.cntmx,a.sum+b.sum};
}

Node init(int node,int st,int en){
    if(st==en){return tree[node] = {A[st],-1,1,A[st]};}
    int mid = (st+en)>>1;
    return tree[node] = f(init(node<<1,st,mid),init((node<<1)|1,mid+1,en));
}

void push(int node,int st,int en){
    if(st==en)return;
    for(auto i :{(node<<1),((node<<1)|1)}){
        if(tree[node].mx<tree[i].mx){
            tree[i].sum -= tree[i].cntmx*(tree[i].mx-tree[node].mx);
            tree[i].mx = tree[node].mx;
        }
    }
}

void update(int node,int st,int en,int L,int R,ll v){
    push(node,st,en);

    if(R<st||en<L||tree[node].mx<=v)return;
    if(L<=st&&en<=R&&tree[node].mx2<v){
        tree[node].sum -= tree[node].cntmx * (tree[node].mx - v);
        tree[node].mx = v;
        push(node,st,en);
        return;
    }

    int mid = (st+en)>>1;

    update(node<<1,st,mid,L,R,v);
    update((node<<1)|1,mid+1,en,L,R,v);
    tree[node] = f(tree[node<<1],tree[(node<<1)|1]);
}

ll getmx(int node,int st,int en,int L,int R)
{
    push(node,st,en);
    if(R<st||en<L)return 0;
    if(L<=st&&en<=R)return tree[node].mx;

    int mid = (st+en)>>1;

    return max(getmx(node<<1,st,mid,L,R),getmx((node<<1)|1,mid+1,en,L,R));
}

ll getsum(int node,int st,int en,int L,int R)
{
    push(node,st,en);
    if(R<st||en<L)return 0;
    if(L<=st&&en<=R)return tree[node].sum;

    int mid = (st+en)>>1;

    return getsum(node<<1,st,mid,L,R)+getsum((node<<1)|1,mid+1,en,L,R);
}

int main()
{
    ll n,m,k,a,b,c,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;
    int ty;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    init(1,1,n);

    cin>>q;

    for(int i=0;i<q;i++){

        cin>>ty;
        if(ty==1){
            cin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }
        else if(ty==2){
            cin>>a>>b;
            cout<<getmx(1,1,n,a,b)<<"\n";
        }
        else {
            cin>>a>>b;
            cout<<getsum(1,1,n,a,b)<<"\n";
        }
    }

    return 0;
}

