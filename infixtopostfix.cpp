#include <bits/stdc++.h>
using namespace std;
int precedence(char ch){
    switch(ch){
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}
bool isOperand(char ch){
    return (ch>='A' && ch <='Z');
}
string infixToPostfix(string infix){
    int n=infix.size();
    stack<char> st;
    string postfix;
    for(int i=0;i<n;i++){
        if(isOperand(infix[i])){

            postfix.push_back(infix[i]);
        }
        else if(infix[i] == '('){

            st.push('(');
        }
        else if(infix[i] == ')'){

            while( st.top() != '(' ){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();

        }
        else{

            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(infix[i])){
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
int main() {

    string infix="(A+B-C)*(E/F)-(G-H/I)";
    string postfix=infixToPostfix(infix);
    cout<<"Infix expression : "<<infix<<endl;
    cout<<"Postfix expression : "<<postfix<<endl;
    return 0;
}
