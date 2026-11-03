#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> stack;
    for(char c:s){
        if(c=='('){
            stack.push(c);
            continue;
        }
        else if(stack.empty()) return false;
        stack.pop();
    }

    if(!stack.empty())
        return false;

    return true;
}