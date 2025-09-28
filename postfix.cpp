#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(const string& exp) {
    stack<int> st;

    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char digit to int
        }
        else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp = "231*+9-";
    cout << "Postfix evaluation: " << evaluatePostfix(exp);
}
