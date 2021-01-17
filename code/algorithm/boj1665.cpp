#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 1e5+10;
const int MAXM = 1e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;

int n, m, cnt;
pii p1[MAXM], p2[MAXM], A[MAXM*MAXM * 4];
int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d %d", &p1[i].f, &p1[i].s);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) scanf("%d %d", &p2[i].f, &p2[i].s);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[cnt++] = { p1[i].f + p2[j].f,1 };
            A[cnt++] = { p1[i].f + p2[j].s + 1,-1 };
            A[cnt++] = { p1[i].s + p2[j].f + 1,-1 };
            A[cnt++] = { p1[i].s + p2[j].s + 2,1 };
        }
    }
    sort(A, A + cnt);
    ll sum, t = 0, r = 0, idx;
    sum = A[0].s;
    for (int i = 1; i < cnt; i++) {
        if (A[i - 1].first == A[i].first) {
            sum += A[i].second;
            continue;
        }
        t += sum;
        if (t > r) r = t, idx = A[i - 1].first - 1;
        t += sum*(A[i].first - A[i - 1].first - 1);
        if (t > r) r = t, idx = A[i].first - 2;
        sum += A[i].second;
    }
    if (t + sum > r) idx = A[cnt - 1].first - 1;
    printf("%d", idx);
    return 0;
}

