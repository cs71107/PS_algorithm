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

vector<int> xpos;
vector<int> ypos;

int main()
{
    int n,m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    cin>>n;

    xpos = vector<int> (2*n);
    ypos = vector<int> (2*n);

    for(int i=0;i<2*n;i++){
        cin>>x>>y;
        xpos[i] = x;
        ypos[i] = y;
    }
    ll res = 0;

    vector<vector<int> > cal(n+1,vector<int>(3,0));

    for(int i=0;i<2*n;i++){
        x = xpos[i]; y = ypos[i];
        if(x<1){res+=(ll)(1-x); x = 1;}
        if(x>n){res+=(ll)(x-n); x = n;}
        if(y<1){res+=(ll)(1-y); y = 1;}
        if(y>2){res+=(ll)(y-2); y = 2;}
        cal[x][y]++;
    }

    vector<int> dp(3,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            dp[j] += (cal[i][j]-1);
        }
        for(int j=1;j<=2;j++){
            if(dp[j]>0&&0>dp[3-j]){
                const int t = min(dp[j],-dp[3-j]);
                res+=(ll)t;
                dp[j]-=t;
                dp[3-j]+=t;
            }
        }
        for(int j=1;j<=2;j++)
            res+=abs(dp[j]);
    }

    cout<<res<<"\n";

    return 0;
}

