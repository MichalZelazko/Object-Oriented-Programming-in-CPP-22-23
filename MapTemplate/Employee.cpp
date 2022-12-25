#include "Employee.h"

Employee::Employee() {
  this->name = "";
  this->position = "";
  this->age = 0;
}

Employee::Employee(string name, string position, int age) {
  this->name = name;
  this->position = position;
  this->age = age;
}

Employee::Employee(const Employee& employee) {
  this->name = employee.name;
  this->position = employee.position;
  this->age = employee.age;
}

Employee& Employee::operator=(const Employee& employee) {
  this->name = employee.name;
  this->position = employee.position;
  this->age = employee.age;
  return *this;
}

Employee::~Employee() {}

ostream& operator<<(ostream& os, const Employee& employee) {
  os << "Name: " << employee.name << ", position: " << employee.position << ", age: " << employee.age << endl;
  return os;
}