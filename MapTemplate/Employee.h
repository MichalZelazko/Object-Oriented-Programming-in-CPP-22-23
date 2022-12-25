#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee {
  public:
    string name;
    string position;
    int age;
    Employee();
    Employee(string name, string position, int age);
    Employee(const Employee& employee);
    Employee& operator=(const Employee& employee);
    ~Employee();
    friend ostream& operator<<(ostream& os, const Employee& employee);
};