#include <bits/stdc++.h>

using namespace std;

int N, P;
const int MAX_N = 800;

struct Edge {
    int target, capacity, flow;
    Edge* reverse;
    int residualCapacity() { return capacity - flow; }
    void push(int amt) {
        flow += amt;
        reverse->flow -= amt;
    }
};

vector<Edge*> adj[MAX_N];

int main() {

    scanf("%d %d", &N, &P);

    for (int i = 0; i < N; i++) {
        int u = i * 2, v = u + 1;
        Edge *e1 = new Edge(), *e2 = new Edge();
        e1->target = v; e2->target = u;
        e1->capacity = 1; e2->capacity = 0;
        e1->reverse = e2;    e2->reverse = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }
    for (int i = 0; i < P; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        m--; n--;
        Edge *e1 = new Edge(), *e2 = new Edge();
        e1->target = 2 * n; e2->target = 2 * m;
        e1->capacity = 1; e2->capacity = 1;
        e1->reverse = e2;    e2->reverse = e1;
        adj[m * 2 + 1].push_back(e1);
        adj[n * 2 + 1].push_back(e2);
    }

    int totalFlow = 0;
    int source = 1, sink = 2;
    while (true) {
        vector<int> parent(MAX_N, -1);
        Edge *path[MAX_N] = { 0 };
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for(int i=0;i<adj[here].size();i++){
                int there = adj[here][i]->target;
                if (adj[here][i]->residualCapacity() > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                    path[there] = adj[here][i];
                    if (there == sink) break;
                }
            }
        }
        if (parent[sink] == -1) break;

        int amount = 1;
        for (int i = sink; i != source; i = parent[i]) {
            path[i]->push(amount);
        }
        totalFlow += amount;
    }

    printf("%d", totalFlow);
    return 0;
}
