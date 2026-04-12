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


int maximal(vector<vector<int>> &mat){
    int n = mat.size(); 
    int m = mat[0].size();

    int maxArea = 0;

    vector<int> pSum(m, 0);  

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                pSum[j] = 0;
            } else {
                pSum[j] += mat[i][j];
            }
        }

        maxArea = max(maxArea, largestrec(pSum));
    }

    return maxArea;
}

int main(){
    vector<vector<int>> mat = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0}
    };

    int result = maximal(mat);

    cout << "Maximum Rectangle Area: " << result << endl;

    return 0;
}