#include<iostream>
#include<stack>
using namespace std;
string postfixtoprefix(string s){

    int i =0;
    stack<string> st;

    while(i<s.size()){

        if((s[i]>='A' && s[i]<='Z')||
        (s[i]>='a'  && s[i] <='z')||
        (s[i]>='0' && s[i]<='9')){
            st.push(string (1,s[i]));
        }else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

           
             st.push(string(1,s[i]) + top2 + top1);
            
        }
        i++;
    }
    return st.top();
}

int main(){
    string s;

    cout<<"Enter Postfix Expression: ";
    cin>>s;

    cout<<"Prefix Expression: "<<postfixtoprefix(s)<<endl;

    return 0;
}