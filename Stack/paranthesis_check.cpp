#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParantheses(char *str)
{
    stack<char> myStack;

    int i=0;

    while(str[i] != '\0')
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            myStack.push(str[i]);
        }

        else 
        {
            if(myStack.empty())
            {
                return false;
            }

            char x;
            switch(str[i])
            {
                case ')':
                    x = myStack.top();
                    myStack.pop();
                    if(x != '(')
                    {
                        return false;
                    }
                    break;

                case ']':
                    x = myStack.top();
                    myStack.pop();
                    if(x != '[')
                    {
                        return false;
                    }
                    break;

                case '}':
                    x = myStack.top();
                    myStack.pop();
                    if(x != '{')
                    {
                        return false;
                    }
                    break;
            }
        }
        i++;
    }

    if(myStack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    char str[100000];

    cin >> t;

    while(t--)
    {
        cin >> str;
        if(isBalancedParantheses(str))
            cout << "balanced\n";
        else
        {
            cout << "not balanced\n";
        }
        
    }

    return (0);
}