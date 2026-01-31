#include<iostream>
#include<stack>
using namespace std;

class Twostack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    //constructor
    Twostack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr= new int[size];
    }

void push1(int element){
    if(top2 - top1 > 1){
        top1++;         // left to right 
        arr[top1]=element;

    }

}

void push2(int element){
    if(top2- top1 >1){
        top2--;     //right to left
        arr[top2]=element;
    }
}

void pop1(){
    if(top1==-1){
        cout<<"The stack is empty"<<endl;
    }else if(top1>=0){
        top1--;


    }
}
void pop2(){
    if(top2== size){
        cout<<"The stack is empty"<<endl;
    }else if(top2<size){
        top2++;
    }
}

int peek1(){
        if(top1>=0 && top1<size){
            return arr[top1];
        } else {
            cout<<"empty stack. "<<endl;
            return -1;
        }

    }
int peek2(){
        if(top2>=0 && top2<size){
            return arr[top2];
        } else {
            cout<<"empty stack. "<<endl;
            return -1;
        }

    }


bool isempty(){
        if(top1==-1){
            cout<<"The stack is empty."<<endl;
            return true;
        }else{
            cout<<"The stack isnt empty. "<<endl;
            return false;
            }
    }
};

int main(){
    Twostack st(5);
    st.push1(1);
    st.push1(2);
    st.push2(3);
    st.push2(4);
    st.push2(5);

    st.pop1();
    st.pop2();

    cout<<st.peek1()<<endl;

    
    cout<<st.peek2()<<endl;
    return 0;


    



}
