#include<iostream>
#include<stack>
#include<string>

using namespace std;
bool flag = true;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string s;
        stack<char> st;
        flag = true;

        getline(cin, s);
        if(s == ".") break;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            } else if(ch == '['){
                st.push(ch);
            } else if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if(ch == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if( flag && st.empty()){
            cout<<"yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}