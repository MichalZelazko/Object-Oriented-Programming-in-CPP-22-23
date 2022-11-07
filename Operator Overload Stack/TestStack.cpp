#include <iostream>
#include "Stack.h"

using namespace std;

void passToPrintViaValue(Stack s);
void passToPrintViaReference(const Stack& s);

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Stack 1 info:\n----------------------------------------" << endl;
    s1.printInfo();
    
    s1 = s1;
    cout << "Stack 1 info after assigning it to itself:\n----------------------------------------" << endl;
    s1.printInfo();
    
    Stack s2(s1);
    cout << "Stack 2 info after copy constructor from Stack 1:\n----------------------------------------" << endl;
    s2.printInfo();
    
    Stack s3 = s1;
    cout << "Stack 3 info after assignment operator from Stack 1:\n----------------------------------------" << endl;
    s3.printInfo();
    
    Stack s4;
    s4.push(10);
    cout << "Stack 4 info after usual constructor and 1 push:\n----------------------------------------" << endl;
    s4.printInfo();
    s4 = s1;
    cout << "Stack 4 info after assignment operator from Stack 1:\n----------------------------------------" << endl;
    s4.printInfo();
    
    Stack s5;
    s5.push(4);
    s5.push(5);
    s5.push(6);
    s5.push(7);
    s5.push(8);
    cout << "Stack 5 info after usual constructor and 5 pushes:\n----------------------------------------" << endl;
    s5.printInfo();
    s5 = s1;
    cout << "Stack 5 info after assignment operator from Stack 1:\n----------------------------------------" << endl;
    s5.printInfo();
    
    
    passToPrintViaReference(s1);
    passToPrintViaValue(s1);
    return 0;
}

void passToPrintViaValue(Stack s){
    cout << "\n\nPassing stack by value" << endl;
    s.printInfo();
}

void passToPrintViaReference(const Stack& s){
    cout << "\n\nPassing stack by reference" << endl;
    s.printInfo();
}
