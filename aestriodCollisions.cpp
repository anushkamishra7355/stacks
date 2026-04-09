#include<iostream>
#include<vector>
using namespace std;

vector<int> collision(vector<int> &st){
    int n = st.size();
    vector<int> arr = st;   
    vector<int> res;        

    for(int i = 0; i < n-1; i++){
        if(arr[i] > 0){
            res.push_back(arr[i]);
        } 
        else{
            while(!res.empty() && res.back() > 0 && res.back() < abs(arr[i])){
                res.pop_back();
            }

            if(!res.empty() && res.back() == abs(arr[i])){
                res.pop_back();
            }
            else if(res.empty() || res.back() < 0){
                res.push_back(arr[i]);
            }
        }
    }
    return res;
}

int main() {
    vector<int> st = {5, 10, -5};

    vector<int> result = collision(st);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
