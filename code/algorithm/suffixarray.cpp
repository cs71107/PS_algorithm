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
const int MAXN = (1<<19);
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

char S[MAXN];
int n,d,sa[MAXN],pos[MAXN];
int lcp[MAXN];
int tmp[MAXN];

bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];

    i+=d;
    j+=d;
    return (i<n&&j<n)?(pos[i]<pos[j]):(i>j);
}

void constructSA()
{
    n = strlen(S);

    for(int i=0;i<n;i++){
        sa[i] = i;
        pos[i] = S[i];
    }

    for(d = 1;;d<<=1){
        sort(sa,sa+n,cmp);

        fill(tmp,tmp+n,0);

        for(int i=0;i<n-1;i++)
            tmp[i+1] = tmp[i]+cmp(sa[i],sa[i+1]);

        for(int i=0;i<n;i++)
            pos[sa[i]] = tmp[i];

        if(tmp[n-1]==n-1)break;
    }

    for(int i=0;i<n;i++){
        pos[sa[i]] = i;
    }
}

void constructLCP(){
    for(int i=0,k=0; i<n; i++,k = max(k-1,0)){
        if(pos[i]==n-1)continue;

        for(int j=sa[pos[i]+1];S[i+k]==S[j+k];k++);
        lcp[pos[i]] = k;
    }
}

int main()
{
    int m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    cin>>S;
    constructSA();
    constructLCP();

    return 0;
}
