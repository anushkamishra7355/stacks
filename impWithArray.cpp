#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public: 
    int top;
    int *arr;
    int size;
    
    //constructor
    Stack(int size){
        this->size=size; //initialsing size
        arr= new int[size]; // for size
        top=-1; //ek element pta hona chahiye ki kha pe hme push krna h

    }

    void push (int element){
        if(size - top >1){
            top++;
            arr[top]=element; // copying the element which is being pushed
        }else{
            cout<<"The stack is Overflow. "<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"The stack is underflow";
        }

    }

    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        } else {
            cout<<"empty stack. "<<endl;
            return -1;
        }

    }
    
    bool isempty(){
        if(top==-1){
            cout<<"The stack is empty."<<endl;
            return true;
        }else{
            cout<<"The stack isnt empty. "<<endl;
            return false;
            }
    }


};

int main(){
   Stack st(5);
   st.push(20);
   st.push(21);
   st.push(22);
   st.push(23);
   st.push(24);

   cout<<st.peek()<<endl;
   st.isempty();

   st.pop();
  cout<<st.peek()<<endl;

   st.pop();
   st.pop();

  cout<<st.peek()<<endl;

   st.pop();
   st.pop();

   st.isempty();

   cout<<st.peek()<<endl;


   return 0;

}