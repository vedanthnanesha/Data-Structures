#include <bits/stdc++.h>
using namespace std;

bool isoperand(char c)
{

    return isdigit(c);
}

double evaluatePrefix(string preexp)
{
    stack<double> Stack;

    for (int j = preexp.size() - 1; j >= 0; j--) {


        if (isoperand(preexp[j]))
            Stack.push(preexp[j] - '0');

        else {


            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();


            switch (preexp[j]) {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            case '^':
                Stack.push(pow(o1,o2));
                break;
            }
        }
    }

    return Stack.top();
}
int main()
{
    string preexp = "+*3^46^*2/568";
    cout << evaluatePrefix(preexp) << endl;
    return 0;
}
