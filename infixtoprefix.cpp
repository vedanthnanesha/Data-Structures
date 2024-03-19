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
    int len=infix.size();
    stack<char> st;
    string postfix;
    for(int i=0;i<len;i++){
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

string infixToPrefix(string infix) {

  int l = infix.size();


  reverse(infix.begin(), infix.end());


  for (int i = 0; i < l; i++) {

    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);


  reverse(prefix.begin(), prefix.end());

  return prefix;
}
int main() {

    string infix="(A/D+C)*(X^Y)";

    string prefix=infixToPrefix(infix);
    cout<<"Infix expression : "<<infix<<endl;
    cout<<"Prefix expression : "<<prefix<<endl;
    return 0;
}

