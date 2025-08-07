#include<iostream>
#include<stack>

using namespace std;

string str;
int number = 0;  // 잘린 조각 수는 0부터 시작

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char>st;

    cin >> str;
    char prev = '(';

    for(char ch : str){
        if(ch == ')'){
            if(prev == '('){  // 레이저인 경우
                st.pop();
                number += st.size();  // 현재까지 쌓여있는 파이프 수만큼 개수 증가
            } else {  // 쇠막대기 끝인 경우
                st.pop(); //파이프의 개수를 하나 줄이고,
                number += 1;  // 총파이프의 개수를 하나 증가
            }
        } else {  // 여는 괄호라면
            st.push(ch); // 파이프 수 증가 or 레이저 
        }
        prev = ch;
    }

    cout << number;
    return 0;
}
