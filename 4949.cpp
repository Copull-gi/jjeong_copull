#include<iostream>
#include<stack>
#include<string>

using namespace std;
bool flag = true;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string s; //string 으로 입력 받기
        stack<char> st;
        flag = true;

        getline(cin, s); //띄어쓰기 포함한 경우 : getline
        if(s == ".") break;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            } else if(ch == '['){
                st.push(ch);
            } else if(ch == ')'){
                if(!st.empty() && st.top() == '('){ //스택이 비어있지는 않은지 먼저 체크 (segmentation fault)
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
        if( flag && st.empty()){ //stack이 비어있는지 예외처리
            cout<<"yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}