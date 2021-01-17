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
const int MAXH = 23;
priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int S[MAXN];
int T[MAXN];

int nxt[MAXH][MAXN];
int lazy[MAXH][MAXN];

int A[MAXN];
int B[MAXN];

int N;
int cur = 0;
int head = 1;


void down(int r, int n) {
  if (r == 0) return;
  bool first = true;
  for(int x = n; x != nxt[r][n]; x = nxt[r - 1][x]) {
    if (!first) A[x] -= lazy[r][n];
    first = false;
    lazy[r - 1][x] += lazy[r][n];
  }
  lazy[r][n] = 0;
}


int geth() {
  for(int i = 0; i < MAXH; ++i) {
    if (rand() % 2) return i;
  }
  return MAXH; // return MAXH if height > MAXH
}

// compares by B - A.
bool better(int x, int y) {
  return B[x] - A[x] >= B[y] - A[y];
}
// sidenote: could make code cleaner by storing B - A in array instead of B

int main() {

  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d %d", S + i, T + i);
  }

  ++cur; // node 1 is head, stores (0, 0)
  int ans = 0;
  for(int i = N; i >= 1; --i) {
    ++cur;
    A[cur] = S[i];
    int height = geth();

    // search for insertion point of cur
    int x = head;
    for(int r = MAXH; r >= 0; --r) {
      while (nxt[r][x] && A[nxt[r][x]] < A[cur]) x = nxt[r][x];
      down(r, x);
    }

    // compute time when cow i sits
    int val = B[x] - A[x] + S[i] + T[i];
    B[cur] = val; // insert (A[cur], B[cur]) into queue
    if (val > ans) ans = val;

    // insert cur into queue
    // simultaneously decrement pairs passed by cow i
    x = head;
    --A[x];
    for(int r = MAXH; r >= 0; --r) {
      // search for insertion point while decrementing ranges
      while (nxt[r][x] && A[nxt[r][x]] < A[cur]) {
        ++lazy[r][x];
        x = nxt[r][x];
        --A[x];
      }
      down(r, x);

      // delete nodes majorized by cur
      while (nxt[r][x] && better(cur, nxt[r][x])) {
        down(r, nxt[r][x]);
        nxt[r][x] = nxt[r][nxt[r][x]];
      }

      // insert cur depending on layer
      if (height >= r) {
        nxt[r][cur] = nxt[r][x];
        nxt[r][x] = cur;
      }
    }
    --A[cur]; // A[cur] must be decremented too
  }

  printf("%d\n", ans);
  return 0;
}

