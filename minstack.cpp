#include<iostream>
#include<stack>
#include <climits>
using namespace std;

class minstack{
    stack<int> st;
    int minVal ;
    public:
    minstack(){
    minVal = INT_MAX;
    }
    void push(int val){
        if(st.empty()){
            st.push(val);
            minVal=val;
        }else{
            if(val>minVal){
                st.push(val);
            }else{
                st.push(2*val-minVal);
                minVal=val;
            }
        }
    }

    void pop(){
        if(st.empty()){
            return ;
        }else{
            int n = st.top();
            st.pop();

            if(n<minVal){
                minVal=2*minVal-n;
            }
        }
       
    }

    int top(){
        if(st.empty())
            return -1;
          int  n=st.top();
          if(minVal<n){
            return n;
          }else{
            return minVal;
          }
        
    }

    int getmin(){
       if(st.empty()){
        return -1;
       }else{
        return minVal;
       }
    }

};
int main(){
minstack s;

    s.push(12);
    s.push(15);
    s.push(10);
     cout<<"Minimum element: "<<s.getmin()<<endl;
  s.pop();
    cout<<"Top element: "<<s.top()<<endl;
   

    

    cout<<"After pop:"<<endl;
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Minimum element: "<<s.getmin()<<endl;

    return 0;
}