#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> FindNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){   
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = n;
        } else {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> FindPSEE(vector<int>& arr){
    int n = arr.size();
    vector<int> psee(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            psee[i] = -1;
        } else {
            psee[i] = st.top();
        }
        st.push(i);
    }
    return psee;
}

int total(vector<int> &arr){
    int n = arr.size();

    vector<int> nse = FindNSE(arr);   
    vector<int> psee = FindPSEE(arr); 

    long long total = 0;             
    int mod = 1e9 + 7;                

    for(int i = 0; i < n-1; i++){     
        int left = i - psee[i];
        int right = nse[i] - i;      

        total = (total + (1LL * left * right % mod) * arr[i] % mod) % mod;
    }
    return (int)total;
}
int main(){
    vector<int> arr = {1, 1};

    int result = total(arr);
    cout << "Total: " << result << endl;

    return 0;
}

