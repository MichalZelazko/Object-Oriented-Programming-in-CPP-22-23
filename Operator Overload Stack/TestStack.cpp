#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack s1;
    s1.isEmpty();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.pop();
    return 0;
}
