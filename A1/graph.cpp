// Write a program to represent input graph using adjecency matrix. Implement Depth First and breadth first traversal algorithms.
// Check if graph is connected, if not find how many connected components it has.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class graph
{
  int adjmat[5][5];
  int arr[5];
  vector<int> visited;

public:
  graph()
  {
    // initialize the adjacency matrix
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        adjmat[i][j] = 0;
      }
    }
    for (int i = 0; i < 5; i++)
    {
      arr[i] = 0;
    }
  }
  void create_graph()
  {
    int v1, v2;
    cout << "enter the number of edges" << endl;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
      cout << "enter first vertex" << endl;
      cin >> v1;
      cout << "enter second vertex" << endl;
      cin >> v2;
      adjmat[v1 - 1][v2 - 1] = 1;
      adjmat[v2 - 1][v1 - 1] = 1;
    }
  }
  void print_matrix()
  {
    cout << "   ";
    for (int i = 0; i < 5; i++)
    {
      cout << i + 1 << "  ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
      cout << (i + 1) << "  ";
      for (int j = 0; j < 5; j++)
      {
        cout << adjmat[i][j] << "  ";
      }
      cout << endl;
    }
  }
  void check_connected()
  {
    this->breadth_first_search(1);
    int val = 1;
    for (int i = 0; i < 5; i++)
    {
      if (arr[i] == 0)
      {
        this->breadth_first_search(arr[i]);
        val++;
      }
    }
    cout << endl;
    cout << val << endl;
  }
  void depth_first_search()
  {
    stack<int> st;
    st.push(1);
    arr[0] = 1;
    int val;
    while (!st.empty())
    {
      val = st.top();
      st.pop();
      cout << val << "  ";
      for (int i = 0; i < 5; i++)
      {
        if (adjmat[val - 1][i] != 0)
        {
          int g = check(visited, i + 1);
          if (g == 0)
          {
            st.push(i + 1);
            visited.push_back(i + 1);
          }
        }
      }
    }
  }
  int check(vector<int> q, int el)
  {
    int f = 0;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      if (el == q[i])
      {
        f = 1;
        break;
      }
    }
    return f;
  }
  void breadth_first_search(int b)
  {
    queue<int> q;
    q.push(b);
    arr[b - 1] = 1;
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      cout << v << "  ";
      for (int i = 0; i < 5; i++)
      {
        if (adjmat[v - 1][i] != 0)
        {
          int g = check(visited, i + 1);
          if (g == 0)
          {
            q.push(i + 1);
            adjmat[i][v - 1] = 0;
            arr[i] = 1;
          }
        }
      }
    }
    cout << endl;
  }
};
int main()
{
  graph g;
  g.create_graph();
  g.print_matrix();
  g.check_connected();
}