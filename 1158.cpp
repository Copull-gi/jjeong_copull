#include <iostream>
#include <list>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    list<int> L;
    for (int i = 1; i <= n; i++) {
        L.push_back(i);
    }

    auto cursor = L.begin();
    cout << "<";

    while (!L.empty()) {
        
        for (int i = 0; i < k - 1; i++) {
            cursor++;
            if (cursor == L.end()) cursor = L.begin();
        }

       
        cout << *cursor;
        cursor = L.erase(cursor); 
        if (cursor == L.end()) cursor = L.begin(); 

        if (!L.empty()) cout << ", ";
    }

    cout << ">\n";
    return 0;
}
