#include <iostream>
#include <cstring>
using namespace std;

template <class T>

class stacks
{
private:
    int top, size; // here top mean top of the element where size is the total length of the stack
    T *arr;

public:
    stacks(int a)
    {
        size = a;
        arr = new T[size];
        top = -1;
    }
    ~stacks()
    {
        delete[] arr;
    }
    bool isfull()
    {
        return (top == size - 1);
    }
    bool isempty()
    {
        return (top == -1);
    }
    void makeempty() // make the array to behave like empty array
    {
        top = -1;
    }
    void push(T a)
    {
        if (top == size - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = a;
    }

    T pop()
    {
        T item;
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        item = arr[top];
        top--;
        return item;
    }

    T peek()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return arr[top];
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int postfix(char arr[], int a)
{
    stacks<int> s(a);// we use the stack of integer data type
    char temp;
    int result;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            s.push(arr[i] - '0');
        }
        else
        {
            char op = arr[i];
            temp = s.pop();
            // char ntemp = s.pop();
            if (op == '+')
            {
                result = s.pop() + temp;
            }
            else if (op == '-')
            {
                result = s.pop() - temp;
            }
            else if (op == '*')
            {
                result = s.pop() * temp;
            }
            else if (op == '/')
            {
                result = s.pop() / temp;
            }
            s.push(result);
        }
    }
    return s.peek();
}

int prefix(char arr[], int a)
{
    stacks<int> s(20);
    char temp;
    int result;
    for (int i = a - 1; i >= 0; i--)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            s.push(arr[i] - '0');
        }
        else
        {
            char op = arr[i];
            temp = s.pop();
            if (op == '+')
            {
                result = temp + s.pop();
            }
            else if (op == '-')
            {
                result = temp - s.pop();
            }
            else if (op == '*')
            {
                result = temp * s.pop();
            }
            else if (op == '/')
            {
                result = temp / s.pop();
            }
            s.push(result);
        }
    }
    return s.peek();
}
int precedence(char arr)
{
    if (arr == '*' || arr == '/')
        return 2;
    else if (arr == '+' || arr == '-')
        return 1;

    return 0;
}
void infixtopost(char arr[], int a)
{
    stacks<char> s(10);
    char sa[100]; // for showing the text of the postfix
    int j = 0;
    for (int i = 0; i < a; i++)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
        {
            sa[j++] = arr[i];
        }
        else
        {
            char op;
            op = arr[i];
            if (op == '(')
            {
                s.push(op);
            }
            else if (op == ')')
            {
                while (!s.isempty() && s.peek() != '(')
                {
                    sa[j++] = s.pop();
                }
                if (!s.isempty() && s.peek() == '(')
                {
                    s.pop();
                }
            }
            else if (op == '+' || op == '-' || op == '*' || op == '/')
            {
                while (!s.isempty() && precedence(s.peek()) >= precedence(op))
                {
                    sa[j++] = s.pop();
                }
                s.push(op);
            }
        }
    }
    while (!s.isempty())
    {
        sa[j++] = s.pop();
    }
    sa[j] = '\0';
    for (int i = 0; i < strlen(sa); i++)
    {
        cout << sa[i];
    }
}

int main()
{
    // char exp[] = {'2','3','1','*','+','9','-'};  // postfix
    // int size = strlen(exp);
    // int result = postfix(exp,size);
    // cout << "Postfix : "<< result;
    // char exp1[] = {'-','+','2','*','3','1','9'}; // prefix
    // size = strlen(exp1);
    // result = prefix(exp1,size);
    // cout << result;
    char exp2[] = "(A+B)*(C-D)";
    int size = strlen(exp2);
    infixtopost(exp2, size);
    return 0;
}