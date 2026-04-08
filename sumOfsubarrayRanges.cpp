#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// FOR SUM OF SUBAARAY MAXIMUMS
vector<int> findNGE(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }

        st.push(i);
    }

    return nge;
}
vector<int> findPGE(vector<int>& arr){
    int n = arr.size();
    vector<int> pge(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();

        st.push(i);
    }
    return pge;
}

int total1(vector<int> &arr){
    int n = arr.size();

    vector<int> nge = findNGE(arr);   
    vector<int> pge = findPGE(arr); 

    long long total1 = 0;             
    int mod = 1e9 + 7;                

    for(int i = 0; i < n; i++){     
        int left = i - pge[i];
        int right = nge[i] - i;      

        total1 = (total1 + (1LL * left * right % mod) * arr[i] % mod) % mod;
    }
    return (int)total1;
}

// FOR SUM OF SUBARRAY MINIMUMS
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
        while(!st.empty() && arr[st.top()] > arr[i]){
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

int total2(vector<int> &arr){
    int n = arr.size();

    vector<int> nse = FindNSE(arr);   
    vector<int> psee = FindPSEE(arr); 

    long long total2 = 0;             
    int mod = 1e9 + 7;                

    for(int i = 0; i < n; i++){     
        int left = i - psee[i];
        int right = nse[i] - i;      

        total2 = (total2 + (1LL * left * right % mod) * arr[i] % mod) % mod;
    }
    return (int)total2;
}

// NOW THE RANGE 

int range(vector<int> arr){

    long long TOTAL=0;

  long long t1 = total1(arr);
  long long t2 = total2(arr);
    TOTAL = t1 - t2;

    return (int)TOTAL;
    
}
int main(){
    vector<int> arr = {1, 4, 3, 2};

    int ans = range(arr);

    cout << "Sum of Subarray Ranges: " << ans << endl;

    return 0;
}


