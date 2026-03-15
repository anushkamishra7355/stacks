#include<iostream>
#include<stack>
using namespace std;
string prefixtopostfix(string s){

    int i =s.size()-1;
    stack<string> st;

    while(i>=0){

        if((s[i]>='A' && s[i]<='Z')||
        (s[i]>='a'  && s[i] <='z')||
        (s[i]>='0' && s[i]<='9')){
            st.push(string (1,s[i]));
        }else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

           
             string S =top1 + top2 + s[i];
             st.push(S);
            
        }
        i--;
    }
    return st.top();
}

int main(){
    string s;

    cout<<"Enter Prefix Expression: ";
    cin>>s;

    cout<<"Postfix Expression: "<<prefixtopostfix(s)<<endl;

    return 0;
}