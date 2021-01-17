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
const ll LINF = 2LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

ll A[MAXN];
ll psum[MAXN];
char S[MAXN];

struct Line{
    ll a,b;
    ll get(ll x){
        return a*x+b;
    }
};

struct Node{
    int Lid,Rid;
    ll st,en;
    Line line;
};

struct Li_chao{
    vector<Node> tree;

    void init(ll st,ll en){
        tree.push_back({-1,-1,st,en,{0,-LINF}});
    }

    void update(int node,Line v){

        ll st = tree[node].st,en = tree[node].en;
        ll mid = (st+en)>>1;

        Line low = tree[node].line,high = v;

        if(low.get(st)>high.get(st))swap(low,high);

        if(low.get(en)<=high.get(en)){
            tree[node].line = high; return;
        }

        if(low.get(mid)<high.get(mid)){

            tree[node].line = high;

            if(tree[node].Rid==-1){
                tree[node].Rid = tree.size();
                tree.push_back({-1,-1,mid+1,en,{0,-LINF}});
            }
            update(tree[node].Rid,low);
        }
        else {
            tree[node].line = low;
            if(tree[node].Lid==-1){
                tree[node].Lid = tree.size();
                tree.push_back({-1,-1,st,mid,{0,-LINF}});
            }
            update(tree[node].Lid,high);
        }
    }

    ll query(int node,ll x){
        if(node==-1)return -LINF;
        ll st = tree[node].st,en = tree[node].en;
        ll mid = (st+en)>>1;

        if(x<=mid)return max(tree[node].line.get(x),query(tree[node].Lid,x));
        else return max(tree[node].line.get(x),query(tree[node].Rid,x));
    }

}seg;

int main()
{
    ll n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    seg.init(-2e12,2e12);


    return 0;
}

