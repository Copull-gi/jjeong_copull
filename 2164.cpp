#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n;
int last = 1;
int counter;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    queue<int> q;

    for(int i=1; i <= n; i++)
    {
        q.push(i);
    }

    while(!q.empty()){
        counter++;
        if(counter % 2 == 1){
            q.pop();
        } else {
            last = q.front();
            q.pop();
            q.push(last);
        }
    }
    cout << last;
    return 0;

}