#include <iostream>
#include<queue>
using namespace std;

#define X first
#define Y second

int maze[101][101];
int dista[101][101];
int n, m;
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str; 
        cin >> str;
        int j = 0;      
        for (int j = 0; j < m; j++) {
            maze[i][j] = str[j] - '0';
            dista[i][j] = -1;
        }
    }

    if (maze[0][0] == 0) { cout << -1 << "\n"; return 0; }

    queue<pair<int,int>> q;
    q.push({0, 0});
    dista[0][0] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.X == n-1 && cur.Y == m-1) break; // 목적지 도달 시 조기 종료
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == 0) continue;      // 벽
            if (dista[nx][ny] != -1) continue;    // 방문됨
            dista[nx][ny] = dista[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dista[n-1][m-1] + 1 << "\n"; // 도달 못하면 -1 출력
    return 0;
}
