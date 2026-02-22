#include<iostream>
#include<stack>
using namespace std;

int priority(char s){

    if(s=='^'){
        return 3;
    }else if (s == '*' || s == '/'){
        return 2;
    }else if (s == '+' || s == '-'){
        return 1;
    }else {
        return -1;
    }

}
string infixTopostfix(string s){
int i =0;
string ans = "";
stack<char> st;
while(i<s.size()){
    if((s[i]>='A' && s[i]<='Z') ||
    (s[i]>='a'  && s[i]<='z') ||
    (s[i]>='0' && s[i]<='9')){
ans = ans + s[i];
    }else if (s[i]== '('){
        st.push(s[i]);
    }
    
    else if (s[i]==')'){

        while(!st.empty() && st.top()!='('){
            ans += st.top();
            st.pop();
        }
      if(!st.empty())  st.pop(); 
    }else{
        while(!st.empty() && (priority(s[i])< priority(st.top()) ||  (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
            ans +=st.top();
            st.pop();

        }
        st.push(s[i]);
    }
    i++;
}
while(!st.empty()){
    ans = ans + st.top();
    st.pop();
}
return ans;

}
int main(){
    string s;
    cin>>s;
    cout<<"Postfix: "<<infixTopostfix(s);
    return 0;
}

