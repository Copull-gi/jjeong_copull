#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string op;
        int n;
        string arr;
        cin >> op >> n >> arr;

        deque<int> dq;
        string num = "";
        for (int i = 0; i < arr.size(); i++) {
            if (isdigit(arr[i])) {
                num += arr[i];
            } else if (arr[i] == ',' || arr[i] == ']') {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        bool reversed = false;
        bool errorFlag = false;

        for (char c : op) {
            if (c == 'R') {
                reversed = !reversed;
            } else if (c == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    errorFlag = true;
                    break;
                }
                if (!reversed) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }

        if (!errorFlag) {
            cout << "[";
            if (!dq.empty()) {
                if (!reversed) {
                    for (int i = 0; i < dq.size(); i++) {
                        cout << dq[i];
                        if (i != dq.size() - 1)
                            cout << ",";
                    }
                } else {
                    for (int i = dq.size() - 1; i >= 0; i--) {
                        cout << dq[i];
                        if (i != 0)
                            cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
