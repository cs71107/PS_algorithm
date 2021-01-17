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

pii A[MAXN];
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

vli2 point[MAXN];

bool cmp(vli2 a,vli2 b)
{
    vli2 a1 = a-point[0];
    vli2 b1 = b-point[0];

    if(ccw(a1,b1)>0)return true;
    else if(ccw(a1,b1)==0&&a1.norm()<b1.norm())return true;
    else return false;
}

vli2 convexhull[MAXN];

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

    for(int i=0;i<n;i++){
        cin>>A[i].s>>A[i].f;//find min-y,min-x point
    }

    sort(A,A+n);

    for(int i=0;i<n;i++){
        point[i] = vli2(A[i].s,A[i].f);
    }

    sort(point+1,point+n,cmp);

    convexhull[0] = point[0];
    convexhull[1] = point[1];

    int t = 2;

    for(int i=2;i<n;i++){
        while(t>1&&ccw(convexhull[t-1]-convexhull[t-2],point[i]-convexhull[t-2])<=0)t--;
        convexhull[t++] = point[i];
    }

    cout<<t<<"\n";

    return 0;
}
