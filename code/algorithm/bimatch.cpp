#include <bits/stdc++.h>

using namespace std;

int n,m;

const int MAXN = 1000;
bool adj[MAXN+1][MAXN+1];

vector<int> amatch,bmatch;

vector<bool> visited;

bool dfs(int a)
{
    if(visited[a])return false;

    visited[a] = true;

    for(int b=1;b<=m;b++){

        if(adj[a][b]){


            if(bmatch[b]==-1||dfs(bmatch[b])){

                amatch[a] = b;
                bmatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartitematch()
{

    amatch = vector<int> (n+1,-1) ;
    bmatch = vector<int> (m+1,-1);
    int s = 0;

    for(int start=1;start<=n;start++)
    {
        visited = vector<bool> (n+1,false);
        if(dfs(start))++s;

    }
    return s;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        int s;
        scanf("%d",&s);
        for(int j=0;j<s;j++)
        {
            int x;
            scanf("%d",&x);
            adj[i][x] = true;
        }
    }

    printf("%d",bipartitematch());

    return 0;
}
