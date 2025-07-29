#include<iostream>
#include<stack>

using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    stack<int>s;
    int num;
    long long sum = 0;

    while(n--){
        cin>>num;

        if(num == 0){
            s.pop();
        } else{
            s.push(num);
        }
    }
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout<<sum;

    return 0;
}