#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<int> st;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(') {
            st.push(-1); 
        } else if (ch == '[') {
            st.push(-2); 
        } else if (ch == ')') {
            int temp = 0;
            while (!st.empty() && st.top() != -1) {
                if (st.top() == -2) { 
                    cout << 0;
                    return 0;
                }
                temp += st.top();
                st.pop();
            }
            if (st.empty()) {
                cout << 0;
                return 0;
            }
            st.pop(); 

            if (temp == 0) st.push(2);       
            else st.push(temp * 2);          

        } else if (ch == ']') {
            int temp = 0;
            while (!st.empty() && st.top() != -2) {
                if (st.top() == -1) { 
                    cout << 0;
                    return 0;
                }
                temp += st.top();
                st.pop();
            }
            if (st.empty()) {
                cout << 0;
                return 0;
            }
            st.pop();

            if (temp == 0) st.push(3);        
            else st.push(temp * 3);          
        }
    }

    
    int result = 0;
    while (!st.empty()) {
        if (st.top() < 0) { 
            cout << 0;
            return 0;
        }
        result += st.top();
        st.pop();
    }

    cout << result;
    return 0;
}
