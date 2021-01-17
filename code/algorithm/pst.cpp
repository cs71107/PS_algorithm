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
const int MAX_DEPTH = 18;
const int MAX_ST = 1<<MAX_DEPTH;//number of points for initialize
const int MAX = 10001;//number of points
const int MAX_RANGE = 100001;
const int MAX_NODE = MAX_ST+MAX*MAX_DEPTH;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

struct Node{
    int val;
    int ns,ne;
    int nNum;
    int Lnum,Rnum;
    Node(): Node(-1,-1,-1){}
    Node(int ns1,int ne1,int nNum1): val(0), ns(ns1), ne(ne1), nNum(nNum1),Lnum(-1), Rnum(-1){}
};

struct Persistentsegtree{

    int TN;
    int ncnt;
    int root[MAX];
    Node node[MAX_NODE];

    Persistentsegtree(): TN(0), ncnt(0){
        fill(root,root+MAX,-1);

        root[TN++] = initialize(0,MAX_ST/2);
    }

    int initialize(int st,int en){
        Node &curr = node[ncnt] = Node(st,en,ncnt);
        ncnt++;
        if(st+1<en){
            int mid = (st+en)>>1;
            curr.Lnum = initialize(st,mid);
            curr.Rnum = initialize(mid,en);
        }
        return curr.nNum;
    }

    void addNode(int y,int val = 1){

        root[TN] = addNode(node[root[TN-1]],y,val,0,MAX_ST/2);
        ++TN;
    }

    int addNode(Node &shadow,int y,int val,int st,int en){

        if(en<=y||y<st)return shadow.nNum;

        Node &curr = node[ncnt] = Node(st,en,ncnt);
        ncnt++;

        if(st+1==en)curr.val = shadow.val+val;

        else {

            int mid = (st+en)>>1;

            curr.Lnum = addNode(node[shadow.Lnum],y,val,st,mid);
            curr.Rnum = addNode(node[shadow.Rnum],y,val,mid,en);

            curr.val = node[curr.Lnum].val+node[curr.Rnum].val;
        }

        return curr.nNum;
    }

    int getsum(int tn,int st,int en){
        return getsum(node[root[tn]],st,en);
    }
    int getsum(Node &curr,int st,int en){
        if(en<=curr.ns||curr.ne<=st)return 0;
        if(st<=curr.ns&&curr.ne<=en)return curr.val;
        return getsum(node[curr.Lnum],st,en)+getsum(node[curr.Rnum],st,en);
    }

};

pii p[MAXN];
int tn[MAX_RANGE];

int main()
{
    int n,m,k,a,b,x,y,x0,y0;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;
    ll res = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>tc;




    return 0;
}
