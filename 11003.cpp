#include<iostream>
#include<deque>

using namespace std;
int n;
int L;
long long k;
long long minium;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> dq;

    cin>>n>>L;

    for(int i = 0; i<n; i++){

        int k;
        cin>>k;

        while (!dq.empty() && dq.back().first > k) {
            dq.pop_back();
        }

        dq.push_back({k, i});

        if (dq.front().second <= i - L) {
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }

    return 0;
}