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

// long long vector
struct vli2{

    ll x,y;

    explicit vli2(ll x_=0,ll y_=0):x(x_),y(y_)
    {}

    bool operator == (const vli2 &rhs)const{
        return x==rhs.x&y==rhs.y;
    }
    bool operator < (const vli2 &rhs)const{
        return x!=rhs.x?x<rhs.x:y<rhs.y;
    }

    vli2 operator + (const vli2& rhs)const{
        return vli2(x+rhs.x,y+rhs.y);
    }

    vli2 operator - (const vli2& rhs)const{
        return vli2(x-rhs.x,y-rhs.y);
    }
    vli2 operator * (ll rhs){
        return vli2(x*rhs,y*rhs);
    }

    ll norm() const{return x*x+y*y;}
    // not sqrt

    ll dot(const vli2& rhs)const {
        return x*rhs.x+y*rhs.y;
    }
    ll cross(const vli2& rhs)const {
        return x*rhs.y-y*rhs.x;
    }
};


ll ccw(vli2 a,vli2 b)
{
    ll res = a.cross(b);
    if(res>0)return 1LL;
    else if(res<0)return -1LL;
    else return 0;
}

bool segmetnintersect(vli2 a,vli2 b,vli2 c,vli2 d)
{

    ll ab = ccw(b-a,c-a)*ccw(b-a,d-a);
    ll cd = ccw(d-c,a-c)*ccw(d-c,b-c);

    if(ab==0&&cd==0){

        if(b<a)swap(a,b);
        if(d<c)swap(c,d);

        return !(b<c|d<a);
    }

    return (ab<=0)&&(cd<=0);
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
