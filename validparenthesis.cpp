#include<iostream>
#include<stack>
using namespace std;



    bool validparenthesis(string s){
        stack <char> st;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if( s[i] =='(' || s[i] =='{' ||
            s[i] =='[') {
                st.push(s[i]);

            }else{
                if(st.empty()) return false;
                  ch = st.top();
                st.pop();
                
                if( s[i] == ')' && ch == '(' ||
                  s[i] == '}'  && ch == '{'||
                  s[i] == ']'   && ch == '['){
                    
                  }else{
                    return false;
                  }
            }
        }
        return st.empty();
    }

int main(){
    string s;
    cin >> s;

    if(validparenthesis(s))
        cout << "Valid";
    else
        cout << "Invalid";
}
    


