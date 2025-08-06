#include<iostream>
#include<stack>

using namespace std;

int N;
string str;
int counter;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    while(N--){
        stack<char> st;
        cin>>str;

        for(char ch : str){
            if(!st.empty() && st.top() == ch){
                st.pop();
            } else {
                st.push(ch);
            }
        }

        if(st.empty()){
            counter++;
        }
    }
    cout << counter;

    return 0;
}