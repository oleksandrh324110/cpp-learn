#pragma once

#include <iostream>
#include <string_view>
#include <vector>

namespace std {
template <typename Key, typename Value>
class hashmap {
 private:
  struct Node {
    Key key;
    Value value;
    Node* next;

    Node(Key key, Value value, Node* next = nullptr)
        : key(key), value(value), next(next) {}
    Node* operator=(Value value) {
      this->value = value;
      return this;
    }
  };

 public:
  hashmap(size_t capacity = 128) : _capacity(capacity), _data(capacity) {}
  void insert(Key key, Value value) {
    size_t index = std::hash<Key>{}(key) % _capacity;

    Node* prev = nullptr;
    Node* head = _data[index];
    if (head) {
      while (head && head->key != key) {
        prev = head;
        head = head->next;
      }

      if (head)
        head->value = value;
      else
        prev->next = new Node(key, value);
    } else
      _data[index] = new Node(key, value);
  }
  bool contains(Key key) {
    size_t index = std::hash<Key>{}(key) % _capacity;

    Node* head = _data[index];
    while (head) {
      if (head->key == key) return true;
      head = head->next;
    }
    return false;
  }
  void remove(Key key) {
    size_t index = std::hash<Key>{}(key) % _capacity;

    Node* prev = nullptr;
    Node* head = _data[index];
    while (head) {
      if (head->key == key) {
        if (prev) {
          Node* toDelete = head;
          prev->next = head->next;
          delete toDelete;
          return;
        }
        delete _data[index];
        _data[index] = nullptr;
        return;
      }
      prev = head;
      head = head->next;
    };
  }
  Node& operator[](Key key) {
    size_t index = std::hash<Key>{}(key) % _capacity;

    Node* prev = nullptr;
    Node* head = _data[index];
    while (head) {
      if (head->key == key) return *head;
      prev = head;
      head = head->next;
    }

    if (prev) {
      prev->next = new Node(key, 0);
      return *prev->next;
    }
    _data[index] = new Node(key, 0);
    return *_data[index];
  }

  void print() {
    for (size_t i = 0; i < _capacity; i++) {
      Node* head = _data[i];
      std::cout << i << ": ";
      while (head) {
        std::cout << head->key << " -> " << head->value << "; ";
        head = head->next;
      }
      std::cout << '\n';
    }
  }

 private:
  size_t _capacity;
  std::vector<Node*> _data;
};
}  // namespace std