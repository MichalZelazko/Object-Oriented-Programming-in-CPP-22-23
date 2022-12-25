#pragma once
#include <iostream>
#include <string>

using namespace std;

class KeyAlreadyExistsException : public exception {
  public:
    const char* what() const throw() {
      return "Key already exists";
    }
};

template <class Key, class T> class Map {
  public:
    Key* keys;
    T* values;
    int size;
    int capacity;
    Map();
    Map(const Map<Key, T>& map);
    Map& operator=(const Map<Key, T>& map);
    ~Map();
    void add(Key key, T value);
    T* find(Key key);
  private:
    void resize();
};

template <class Key, class T> ostream& operator<<(ostream& os, const Map<Key, T>& map);

template <class Key, class T> Map<Key, T>::Map() {
  this->size = 0;
  this->capacity = 5;
  this->keys = new Key[this->capacity];
  this->values = new T[this->capacity];
}

template <class Key, class T> Map<Key, T>::Map(const Map<Key, T>& map) {
  this->size = map.size;
  this->capacity = map.capacity;
  this->keys = new Key[this->capacity];
  this->values = new T[this->capacity];
  for (int i = 0; i < size; i++) {
    this->keys[i] = map.keys[i];
    this->values[i] = map.values[i];
  }
}

template <class Key, class T> Map<Key, T>& Map<Key, T>::operator=(const Map<Key, T>& map) {
  if (this != &map) {
    delete[] this->keys;
    delete[] this->values;
    this->size = map.size;
    this->capacity = map.capacity;
    this->keys = new Key[this->capacity];
    this->values = new T[this->capacity];
    for (int i = 0; i < this->size; i++) {
      this->keys[i] = map.keys[i];
      this->values[i] = map.values[i];
    }
  }
  return *this;
}

template <class Key, class T> Map<Key, T>::~Map() {
  delete[] this->keys;
  delete[] this->values;
}

template <class Key, class T> void Map<Key, T>::add(Key key, T value) {
  for(int i = 0; i < this->size; i++) {
    if (this->keys[i] == key) {
      throw KeyAlreadyExistsException();
    }
  }
  if (this->size == this->capacity) {
    this->resize();
  }
  this->keys[this->size] = key;
  this->values[this->size] = value;
  this->size++;
}

template <class Key, class T> T* Map<Key, T>::find(Key key) {
  for (int i = 0; i < this->size; i++) {
    if (this->keys[i] == key) {
      return &this->values[i];
    }
  }
  return 0;
}

template <class Key, class T> ostream& operator<<(ostream& os, const Map<Key, T>& map) {
  for (int i = 0; i < map.size; i++) {
    os << map.keys[i] << ": " << map.values[i] << endl;
  }
  return os;
}

template <class Key, class T> void Map<Key, T>::resize() {
  this->capacity *= 2;
  Key* newKeys = new Key[this->capacity];
  T* newValues = new T[this->capacity];
  for (int i = 0; i < size; i++) {
    newKeys[i] = this->keys[i];
    newValues[i] = this->values[i];
  }
  delete[] this->keys;
  delete[] this->values;
  this->keys = newKeys;
  this->values = newValues;
}