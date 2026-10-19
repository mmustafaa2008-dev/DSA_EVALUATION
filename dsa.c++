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
// int operation(char exp[], int a)
// {
//     stacks<int> s(15);  // stack for storing the operand
//     int result;
//     int temp;
//     for(int i=a-1;i>=0;i--)
//     {
//         if(exp[i] >= '0' && exp[i] <= '9')
//         {
//             s.push(exp[i] - '0');
//         }
//         else
//         {
//             char op = exp[i];
//             temp = s.pop();
//             if( op == '+')
//             {
//                 result = temp + s.pop();
//                 // s.push(result);
//             }
//             else if( op == '-')
//             {
//                 result = temp - s.pop();
//                 // s.push(result);
//             }

//             else if( op == '*')
//             {
//                 result = temp * s.pop();
//                 // s.push(result);
//             }

//             else if( op == '/')
//             {
//                 result = temp / s.pop();
//             }
//             s.push(result);
//         }
//     }
//     return s.peek();
// }
// int main()
// {
//     // 231*+9-  for postfix loop start from 0 to n / dosra wala pop operator phele wala pop
//     // -+2*319 for prefix loop start from  n to 0  / phele wala pop operator dosre wala pop
//     char exp[] = {'2','3','1','*','+','9','-'};  // postfix
//     char exp1[] = {'-','+','2','*','3','1','9'}; // prefix
//     int size = strlen(exp1);
//     cout << operation(exp1,size);
//     return 0;
// }

// infix to postfix
int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    return 0;
}
void operation(char exp[], int a)
{
    stacks<char> op(15);
    char s[100];
    int j = 0;
    for (int i = 0; i < a; i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            s[j] = exp[i];
            j++;
        }
        else
        { // A+B*C-D
            char temp = exp[i];
            if(temp == '(')
            {
                op.push(temp);
            }
            else if(temp == ')')
            {
                while (!op.isempty() && op.peek() != '(')
                {
                    s[j++]=op.pop();
                }
                if(!op.isempty() && op.peek() == '(')
                {
                    op.pop();
                }
            }
            else if(temp == '+' || temp == '-')  // agr current operator + ho yah -
            {
                while(!op.isempty() && (precedence(op.peek()) >= precedence(temp)))
                {
                    s[j++] = op.pop();
                }
                op.push(temp);
            }
            else if((temp == '*' || temp == '/'))  // agr current operator * yah / ho
            {
                while(!op.isempty() && (precedence(op.peek()) >= precedence(temp)))
                {
                    s[j++] = op.pop();
                }
                op.push(temp);
            }
        }
    }
    while(!op.isempty())
    {
        s[j++] = op.pop();
    }
    s[j] = '\0';
    for(int i=0;i<strlen(s);i++)
    {
        cout << s[i] ;
    }
}
int main()
{
    char exp[] = "(A+B)*(C-D)";
    operation(exp, strlen(exp));
    return 0;
}
