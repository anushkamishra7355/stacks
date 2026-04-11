#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// NSE 
vector<int> FindNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){   
        while(!st.empty() && arr[st.top()] >= arr[i]){ 
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

// PSE
vector<int> FindPSE(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){ 
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

int largestrec(vector<int> &arr){
    int n = arr.size();
    
    vector<int> nse = FindNSE(arr);   
    vector<int> pse = FindPSE(arr); 

    int maxArea = 0;

    for(int i = 0; i < n; i++){  
        int width = nse[i] - pse[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}


      /*while(!st.empty()){
        int element = st.top();
        st.pop();

        int nse = n; // no smaller on right
        int pse = st.empty() ? -1 : st.top();

        int width = nse - pse - 1;
        int area = nse - pse - 1 * arr[element];

        maxArea = max(maxArea, area);

        }
        */
        
  

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area: " << largestrec(arr) << endl;

    return 0;
}





