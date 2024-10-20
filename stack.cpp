#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

string checkBrackets(const string& expression) {
    stack<char> s;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return "Помилка на позиції: " + to_string(i);
            }
            s.pop();
        }
    }
    
    if (!s.empty()) {
        return "Незакрита дужка в кінці виразу.";
    }

    return "Рядок правильний.";
}

int main() {
    string expression;
    cout << "Введіть рядок для перевірки: ";
    getline(cin, expression);

    string result = checkBrackets(expression);
    cout << result << endl;

    return 0;
}
