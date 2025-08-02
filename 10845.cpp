#include<iostream>
#include<queue>

using namespace std;
int n;
string str;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    queue<int> q;

    while(n--){
        cin>>str;
        if(str == "push"){
            int num;
            cin>>num;
            q.push(num);
        } else if(str == "pop"){
            if(q.empty()){
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(str == "front"){
            if(q.empty()){
                cout << "-1\n";
            }
            else cout << q.front()<<"\n";
        } else if(str == "back"){
            if(q.empty()){
                cout << "-1\n";
            }
            else cout << q.back()<<"\n";
        }else if(str == "empty"){
            if(q.empty()){
                cout << "1\n";
            }
            else cout << "0\n";
        } else if(str == "size"){
            cout << q.size() << "\n";
        }
    }

    return 0;
}