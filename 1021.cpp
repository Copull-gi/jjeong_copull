#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int n;
int m;
int a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    deque<int>dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    int total_ops = 0;
    
    while(m--){
        cin>>a;

        int idx = 0;
        for(; idx<dq.size(); idx++){
            if(a == dq[idx]){
                break;
            }
        }

        if(idx <= dq.size() / 2){
            while (dq.front() != a) {
                dq.push_back(dq.front());
                dq.pop_front();
                total_ops++;
            }
        } else{
            while (dq.front() != a) {
                dq.push_front(dq.back());
                dq.pop_back();
                total_ops++;
            }
        }
        dq.pop_front();
    }

     cout << total_ops;
    return 0;

}