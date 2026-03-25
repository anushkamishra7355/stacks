#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> findNSE(vector<int> & arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = 0 ;i<=n-1;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(i<n){
            if(st.empty()){
                nse[i]=-1;
            }else{
                nse[i]=st.top();
            }
        }
        st.push(arr[i]);
    }
    return nse;

}

int main(){
     vector<int> arr = {5, 7, 9, 6, 7, 4, 5, 1, 3, 7};

    vector<int> result = findNSE(arr);

    cout << "Next Smaller Elements:\n";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}