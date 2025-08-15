#include <iostream>
#include<queue>
using namespace std;

int n, m;
int dist[100001];
int dx[3] = {-1, 2, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    queue<int> Q;
    Q.push(n);
    fill(dist, dist + 100001, -1);
    dist[n] = 0;

    if (n == m) {                 // 엣지 케이스
        cout << 0 << '\n';
        return 0;
    }

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(int i = 0; i<3; i++){
            int nx = 0;
            if(i == 1){
                nx = cur * dx[i];
            }else{
                nx = cur + dx[i];
            }
            if(nx > 100000) continue;
            if(nx < 0) continue;
            if(dist[nx] != -1) continue; //중복 연산 방지- 중복으로 같은 노드가 큐에 들어가는 경우

            dist[nx] = dist[cur] + 1;
            if(nx == m){
                cout << dist[nx];
                return 0;
            }
            Q.push(nx);
        }
    }

    return 0;
}