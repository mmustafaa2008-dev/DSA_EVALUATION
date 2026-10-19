// starting of the program
// muhammad mustafa
// cs-25072
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class stacks
{
private:
    int top, size;
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
        return top == size - 1;
    }

    bool isempty()
    {
        return top == -1;
    }
    void makeempty()
    {
        top = -1;
    }

    void push(T a)
    {
        if (isfull())
        {
            cout << "Overflow" << endl;
            return;
        }

        arr[++top] = a;
    }

    T pop()
    {
        if (isempty())
        {
            cout << "Underflow" << endl;
            return T();
        }

        return arr[top--];
    }

    T peek()
    {
        if (isempty())
            return T();

        return arr[top];
    }
};

bool isValid(char str[], int n)
{
    stacks<char> s(n);

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isempty()) 
                return false;

            char temp = s.pop();

            if (ch == ')' && temp != '(')
                return false;

            if (ch == '}' && temp != '{')
                return false;

            if (ch == ']' && temp != '[')
                return false;
        }
    }

    return s.isempty();
}

// output
int main()
{
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    if (isValid(str, strlen(str)))
        cout << "Valid String";
    else
        cout << "Invalid String";

    return 0;
}
