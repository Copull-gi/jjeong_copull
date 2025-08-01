#include<iostream>
#include<stack>

using namespace std;
int n;
long long height;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    stack<int> s;
    
    for(int i =0; i<n; i++){
        cin>>height;
        
        while(!s.empty() && s.top() <= height){
            s.pop();
        }

        ans += s.size();
        s.push(height);

    }
    cout<<ans;
    return 0;
}