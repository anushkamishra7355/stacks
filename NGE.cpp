#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findNGE(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }

    return nge;
}

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = findNGE(arr);

    cout << "Next Greater Elements:\n";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}