#include <iostream>
#include<queue>
using namespace std;

#define X first
#define Y second

int maze[51][51];
bool vis[51][51];
int n, m, r, T;
int dx[4] = {1, 0, -1, 0}; // 동, 남, 서, 북
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while(T--){
        cin >> m >> n >> r;

        for (int i = 0; i < n; i++) {
            fill(maze[i], maze[i] + m, 0);
            fill(vis[i], vis[i] + m, false);
        }

        int minimum = 0;
        queue<pair<int,int>> Q;

        for(int i = 0; i<r; i++){
            int x, y;
            cin >> x >> y;

            maze[y][x] = 1;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(maze[i][j] == 0 || vis[i][j]){
                    continue;
                }
                Q.push({i, j});
                minimum++;
                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx >= n || ny >= m || nx < 0|| ny < 0){
                            continue;
                        }
                        if(vis[nx][ny] || maze[nx][ny] == 0){ //배추인 경우만
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout <<minimum <<'\n';
    }
    
    return 0;

}