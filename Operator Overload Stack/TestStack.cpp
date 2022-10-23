#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "\n\nStack 1 info:\n----------------------------------------" << endl;
    s1.printInfo();
    
    Stack s2(s1);
    cout << "\nStack 2 info after copy constructor from Stack 1:\n----------------------------------------" << endl;
    s2.printInfo();
    
    Stack s3 = s1;
    cout << "\nStack 3 info after assignment operator from Stack 1:\n----------------------------------------" << endl;
    s3.printInfo();
    
    Stack s4;
    s4.push(10);
    cout << "\nStack 4 info after usual constructor and 1 push:\n----------------------------------------" << endl;
    s4.printInfo();
    s4 = s1;
    cout << "\nStack 4 info after assignment operator from Stack 1:\n----------------------------------------" << endl;
    s4.printInfo();
    return 0;
}
