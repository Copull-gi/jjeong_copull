#include<iostream>
#include<stack>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    stack<int> s;

    while(n--){
        string cmd;
        int num;

        cin>>cmd;

        if(cmd == "push"){
            cin>>num;
            s.push(num);
        } else if(cmd == "pop"){
            if(s.empty()){
                cout<<"-1\n";
            } else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        } else if(cmd == "size"){
            cout<<s.size()<<"\n";
        } else if(cmd == "empty"){
            if(s.empty()){
                cout<<"1\n";
            } else{
                cout<<"0\n";
            }
        } else if(cmd == "top"){
            if(s.empty()){
                cout<<"-1\n";
            } else{
                cout<<s.top()<<"\n";
            }
        }
    }
    return 0;
}