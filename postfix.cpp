#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <sstream>
#include <iomanip>

using namespace std;

double calculate(char oper, float n, float m)
{
    double result = 0;

    // cout << "n " << n << " m " << m << endl;
    if (oper == '+')
    {
        result = n + m;
    }
    else if (oper == '-')
    {
        result = n - m;
    }
    else if (oper == '*')
    {
        result = n * m;
    }
    else if (oper == '/')
    {
        result = n / m;
    }
    return result;
}

int main()
{
    double result = 0.0;
    stack<float> post;
    char input[100], a;
    float b, c;

    do
    {
        cin >> input;
        if (isdigit(input[0])){
            post.push(stoi(input));
        } 
        else if (input[0] == '-' || input[0] == '+' || input[0] == '*' || input[0] == '/'){
            a = input[0];
            b = post.top();
            post.pop();
            c = post.top();
            post.pop();
            result = calculate(a, c, b);
            post.push(result);
        }
        
    } while (input[0] != '=');

    cout << setprecision(4) << fixed << result << endl;
}