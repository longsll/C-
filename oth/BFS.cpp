#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<pair<int, int>, string> PII;

const int N = 210;

int n, m;
char g[N][N];
int dist[N][N];
string d = "URDL";

int bfs(PII start, PII end)
{
    queue<PII> q;
    memset(dist, -1, sizeof dist);

    dist[start.x.x][start.x.y] = 0;
    q.push(start);

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        PII t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
         PII temp;
            temp.x.x = t.x.x + dx[i], temp.x.y = t.x.y + dy[i];
            if (temp.x.x < 0 || temp.x.x >= n || temp.x.y < 0 || temp.x.y >= m) continue;  // 出界
            if (g[temp.x.x][temp.x.y] == '1') continue;  // 障碍物
            if (dist[temp.x.x][temp.x.y] != -1) continue;  // 之前已经遍历过

       dist[temp.x.x][temp.x.y] =    dist[t.x.x][t.x.y] + 1;
   temp.y+=t.y+d[i];
           if(temp.x.x==end.x.x&&temp.x.y==end.x.y) {
             cout<<temp.y<<endl;
             return dist[temp.x.x][temp.x.y];
            }

            q.push(temp);
        }
    }

    return -1;
}

int main()
{
    
        cin>>n>>m;
        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

        PII start, end;
        start.x.x=0,start.x.y=0,end.x.x=n-1,end.x.y=m-1;
        
        int distance = bfs(start, end);
  printf("%d\n", distance);

    return 0;
}