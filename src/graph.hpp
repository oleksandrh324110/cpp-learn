#pragma once

#include <iostream>
#include <list>
#include <queue>
#include <stack>

class Graph {
 public:
  Graph(int V) : V(V) { adj = new std::list<int>[V]; }

  void addEdge(int v, int w) { adj[v].push_back(w); }

  void BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    std::queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
      s = queue.front();
      std::cout << s << " ";
      queue.pop();

      for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) {
          queue.push(*i);
          visited[*i] = true;
        }
      }
    }
  }

  void DFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    std::stack<int> stack;
    stack.push(s);

    while (!stack.empty()) {
      s = stack.top();
      stack.pop();

      if (!visited[s]) {
        std::cout << s << " ";
        visited[s] = true;
      }

      for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) stack.push(*i);
      }
    }
  }

 private:
  int V;
  std::list<int>* adj;
};
