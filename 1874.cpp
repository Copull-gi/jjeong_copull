#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int n;
int a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    vector<int> target(n);
    for(int i = 0; i < n; i++) {
        cin >> target[i];
    }

    stack<int> s;
    vector<char> result;
    int cur = 1; 

    for(int i = 0; i < n; i++) {
        int num = target[i];

        while(cur <= num) {
            s.push(cur++);
            result.push_back('+');
        }

        if(s.top() == num) {
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for(char c: result){
        cout<<c<<"\n";
    }

    return 0;
}