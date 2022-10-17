#include "Stack.h"

using namespace std;

int main()
{
    Stack s1;
    Stack s2;
    if (s1.isEmpty()) {
        cout << "Stack is empty. Test successful" << endl;
    }
    s1.push(1);
    if (!s1.isEmpty()) {
        cout << "Stack is not empty after first push. Test successful" << endl;
    }
    s1.push(2);
    s1.push(3);
    s2.push(5);
    s2.push(6);
    cout << "Popped: from first: " << s1.pop() << ", from second: " << s2.pop()
         << endl;
    cout << "Popped: from second: " << s2.pop() << endl;
    cout << "Popped: from second: " << s2.pop() << endl;
    return 0;
}
