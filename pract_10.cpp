#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to check if the character is an operator (+, -, *, /)
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of the operator
int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // Assuming -1 for invalid operators
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) { // If operand, add to postfix string
            postfix += ch;
        } else if (ch == '(') { // If '(' push to stack
            operatorStack.push(ch);
        } else if (ch == ')') { // If ')' pop operators from stack until '(' is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '(' from stack
        } else if (isOperator(ch)) { // If operator, handle precedence and push to stack
            while (!operatorStack.empty() && getPrecedence(ch) <= getPrecedence(operatorStack.top())) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop remaining operators from stack to postfix
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operandStack;

    for (char ch : postfix) {
        if (isalnum(ch)) { // If operand, push to stack
            operandStack.push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) { // If operator, perform operation on operands
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result;
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            operandStack.push(result);
        }
    }

    return operandStack.top(); // Return the final result
}

int main() {
    string infixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix and evaluate the expression
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
