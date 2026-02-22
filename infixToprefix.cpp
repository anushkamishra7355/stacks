#include<iostream>
#include<stack>
#include<algorithm>  
using namespace std;

int priority(char s){
    if(s == '^'){
        return 3;
    }else if (s=='/'  || s=='*'){
        return 2;
    }else if(s == '+' || s == '-'){
        return 1;
    }else{
        return -1;
    }
}


string reverseStr(string s){
    reverse(s.begin(), s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    return s;
}

string intfixToprefix(string s){
    s = reverseStr(s);   

    int i =0;
    stack<char> st;
    string ans="";

    while(i<s.size()){
        if((s[i]>='A'&& s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9')){
            ans = ans + s[i];
        }
        else if (s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){  
                    ans = ans + st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) <= priority(st.top())){  
                    ans = ans + st.top();
                    st.pop();
                }
            }
            st.push(s[i]);  
        }
        i++;   
    }

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());  
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<intfixToprefix(s);
    return 0;
}