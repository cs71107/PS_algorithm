#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5+10;

vector<int> are[MAXN], can[MAXN];
long long tar[MAXN];
int q1[MAXN], q2[MAXN], lef[MAXN], rig[MAXN], ans[MAXN];
long long q3[MAXN], tree[MAXN];

int main() {
    int n, m, u, q;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for (int i = 1;i <= m;++i) {
        cin>>u;
        are[u].push_back(i);
    }
    for (int i = 1;i <= n;++i)
        cin>>tar[i];

    cin>>q;

    for (int i = 1;i <= n;++i) {
        lef[i] = 1;
        rig[i] = q;
        ans[i] = q + 1;
    }

    for (int i = 1;i <= q;++i)
        cin>>q1[i]>>q2[i]>>q3[i];

    while (true) {
        bool c = false;
        for (int i = 1;i <= n;++i)
            if (lef[i] <= rig[i]) {
                c = true;
                can[(lef[i] + rig[i]) / 2].push_back(i);
            }
        if (!c)
            break;

        memset(tree, 0, sizeof(tree));
        for (int i = 1;i <= q;++i) {
            if (q1[i] <= q2[i]) {
                for (int x = q1[i];x <= m;x += x & -x)
                    tree[x] += q3[i];
                for (int x = q2[i] + 1;x <= m;x += x & -x)
                    tree[x] -= q3[i];
            }
            else {
                for (int x = q1[i];x <= m;x += x & -x)
                    tree[x] += q3[i];
                for (int x = 1;x <= m;x += x & -x)
                    tree[x] += q3[i];
                for (int x = q2[i] + 1;x <= m;x += x & -x)
                    tree[x] -= q3[i];
            }

            while (!can[i].empty()) {
                c = true;
                int now = can[i].back();
                can[i].pop_back();

                long long tot = 0;
                for (int beh : are[now]) {
                    for (int x = beh;x > 0; x -= x & -x)
                        tot += tree[x];
                    if (tot >= tar[now])
                        break;
                }


                if (tot >= tar[now]) {
                    ans[now] = min(ans[now], i);
                    rig[now] = i - 1;
                }
                else
                    lef[now] = i + 1;
            }
        }
    }

    for (int i = 1;i <= n;++i) {
        if (ans[i] == q + 1)
            cout<<"NIE\n";
        else
            cout<<ans[i]<<"\n";
    }

    return 0;
}
