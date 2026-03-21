#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> FindNGE2(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n);

    for(int i = 2*n-1 ;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(i<n){
            if(st.empty()){
            nge[i] = -1;
            }
        else{
            nge[i]=st.top();
        }
    }
        st.push(arr[i%n]);
    }
    return nge;
}
int main(){
      vector<int> arr = {2, 10, 12, 1, 11};

    vector<int> result = FindNGE2(arr);

    cout << "Next Greater Elements:\n";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}
