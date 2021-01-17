#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
const int INF = 1e9+1;
const int MAXN = 1e5+10;
const int MAXM = 3e3+10;

priority_queue<int> pq;

vector<ll> A;
vector<ll> tree;
vector<ll> lazy;

ll init(int node,int st,int en)
{
    if(st==en) return tree[node] = A[st];
    else return tree[node] = init(node<<1,st,(st+en)>>1)+init((node<<1)1,((st+en)>>1)+1,en);
}

void update_lazy(int node,int st,int en)
{
    if(!lazy[node])return;
    tree[node] += (en-st+1)*lazy[node];
    if(st!=en){
        lazy[node<<1] += lazy[node];
        lazy[(node<<1)|1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node,int st,int en,int L,int R,ll val)
{
    update_lazy(node,st,en);
    if(L>en|R<st)return;
    if(L<=st&&en<=R){
        tree[node] +=(en-st+1)*val;
        if(st!=en){
            lazy[node<<1]+=val;
            lazy[(node<<1)|1]+=val;
        }
        return;
    }
    update_range(node<<1,st,(st+en)>>1,L,R,val);
    update_range((node<<1)|1,((st+en)>>1)+1,en,L,R,val);
    tree[node] = tree[node<<1]+tree[(node<<1)|1];
    return;
}
ll sum(int node,int st,int en,int L,int R)
{
    update_lazy(node,st,en);
    if(L>en||st>R)return 0;
    if(L<=st&&en<=R)return tree[node];
    return sum(node<<1,st,(st+en)>>1,L,R)+sum((node<<1)|1,((st+en)>>1)+1,en,L,R);
}
int main()
{
    int n,m,k,a,b,x,y;
    int cnt = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;

    A = vector<ll> (n);

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));

    tree = vector<ll> (tree_size);
    lazy = vector<ll> (tree_size);

    int t1;

    ll res = 0;

    for(int i=0;i<n;i++)
        cin>>A[i];

    init(1,0,n-1);

    for(int i=0;i<m+k;i++){

        cin>>t1;

        if(t1==1){
            cin>>x>>y>>a;
            x--; y--;
            update_range(1,0,n-1,x,y,(ll)a);
        }
        else {
            cin>>x>>y;
            x--; y--;
            res = sum(1,0,n-1,x,y);
            cout<<res<<"\n";
        }
    }

    return 0;
}
