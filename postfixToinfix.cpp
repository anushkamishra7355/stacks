#include<iostream>
#include<stack>
using namespace std;

string postfixtoinfix(string s){
    int i=0;
    stack<string> st;
    while(i<s.size()){
        if((s[i]>='A' && s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));   
 
        }else{
           string top1 = st.top();
           st.pop();
           string top2 = st.top();
           st.pop();
           string S = '(' + top2 + s[i] + top1 + ')';
           st.push(S);
        }
        i++;
    }
    return st.top();

    
}
int main(){
    string postfix;
    cout<<"Enter postfix expression: ";
    cin>>postfix;

    cout<<"Infix expression: "<<postfixtoinfix(postfix);

    return 0;
}