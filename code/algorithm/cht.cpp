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

ll D[MAXN];

struct cht{

    ll La[MAXN],Lb[MAXN];

    int p,sz;

    double cross(int x,int y){return (double)(Lb[y]-Lb[x])/(La[x]-La[y]);}


    void Insert(ll a,ll b)
    {
        La[sz] = a;
        Lb[sz] = b;

        while(sz-2>=p&&cross(sz-1,sz-2)>cross(sz-1,sz)){
            La[sz-1] = La[sz];
            Lb[sz-1] = Lb[sz];
            sz--;
        }
        sz++;
    }

    ll query(ll x){

        while(p+1<sz&&cross(p,p+1)<=x)p++;

        return Lb[p]+La[p]*x;
    }
}hull;

int main()
{
    ll n,m,k,a,b,c,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    ll dp = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b>>c;

    for(int i=1;i<=n;i++){
        cin>>D[i];
        D[i]+=D[i-1];
    }
    hull.Insert(0,0);

    for(int i=1;i<=n;i++){
        dp = hull.query(D[i])+1LL*a*D[i]*D[i]+1LL*b*D[i]+c;
        hull.Insert(-2*a*D[i],D[i]*D[i]*a-D[i]*b+dp);
    }

    cout<<dp<<"\n";

    return 0;
}
