#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

string deleteKelements(string s, int k) {
    int n = s.size();
    stack<char> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && k > 0 && st.top() > s[i]) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // If k still remains
    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Build result
    string res = "";
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    // Remove leading zeros
    int i = 0;
    while(i < res.size() && res[i] == '0') {
        i++;
    }

    res = res.substr(i);

    // If empty → return "0"
    if(res == "") return "0";

    return res;
}

int main() {
    string s = "1432219";
    int k = 3;

    cout << deleteKelements(s, k);
}