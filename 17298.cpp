#include<iostream>
#include<stack>

using namespace std;
long long n;
long long num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    stack<long long> s;

    cin>>num;
    s.push(num);
    n-=1;
    while(n--){
        cin>>num;

        while(!s.empty() && s.top() < num){
            s.pop();
            s.push(num);
        }
        cout<<s.top()<<" ";
    }
    cout<<"-1";
    return 0;
}