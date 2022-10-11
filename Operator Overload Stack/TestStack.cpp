#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack s1;
    s1.isEmpty();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack s2 = s1;
    cout << s2.pop();
    return 0;
}
