// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char);
std::string infx2pstfx(std::string);
int eval(std::string);

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string out = "";
    for (int i = 0; i < inf.length(); i++) {
        char c = inf[i];
        if (isdigit(c)) {
            out += c;
            while (++i < inf.length() && inf[i] == isdigit(c)) {
                c = inf[i];
                out += c;
            }
            out += " ";
            i--;
        } else if (c == '(') {
            stack1.push(c);
        } else if (c == ')') {
            while (stack1.isGet() != '(') {
                out += stack1.pop();
                out += " ";
            }
            stack1.pop();//
        } else {
            while (!stack1.isEmpty() &&
                   getPrior(c) <= getPrior(stack1.isGet())) {
                out += stack1.pop();
                out += " ";
            }
            stack1.push(c);
        }
    }
    while (!stack1.isEmpty()) {
        out += stack1.pop();
        if (!stack1.isEmpty())
            out += " ";
    }
    return out;
}

int eval(std::string pref) {
    TStack<char, 100> stack2;
    std::string res = "";
    int oper1, oper2;
    for (int i = 0; i < pref.length(); i++) {
        if (pref[i] == ' ') {
            continue;
        } else if (pref[i] >= '0' && pref[i] <= '9') {
            stack2.push(pref[i] - '0');
        } else if (pref[i]) {
            oper1 = stack2.pop();
            oper2 = stack2.pop();
            if (pref[i] == '+')
                stack2.push(oper2 + oper1);
            if (pref[i] == '-')
                stack2.push(oper2 - oper1);
            if (pref[i] == '*')
                stack2.push(oper1 * oper2);
            if (pref[i] == '/')
                stack2.push(oper2 / oper1);
        }
    }
    return stack2.isGet();
}


int getPrior(char c) {
    if (c == '(') return 0;
    if (c == ')') return 1;
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/') return 3;
    return -1;
}
