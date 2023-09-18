#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

template <typename T>

class graph
{
   public:

   unordered_map <T, list<T>> adj;

   void addEdge(int u, int v, bool directed)
   {
      // directed = true then directed graph from u to v
      // directed = false then undirected graph

      adj[u].push_back(v);
      if(!directed)
      {
         adj[v].push_back(u);
      }
   }   

   void printGraph()
   {
      for(auto i : adj)
      {
         cout << i.first << " -> ";
         for (auto j : i.second)
         {
            cout << j << ",";
         }
         cout << endl;
      }
   } 

   void bfs(T node)
   {
      queue<T> q;
      unordered_map<T, bool> visited;

      for(auto i : adj)
      {
         visited[i.first] = false;
      }

      q.push(node);
      while(true)
      {
         if(q.empty())
         {
            break;
         }
         T front_node = q.front();
         q.pop();
         if (!visited[front_node])
         {cout << front_node << ",";}
         visited[front_node] = true;

         for(auto j : adj[front_node])
         {
            if(!visited[j])
            {
               q.push(j);
            }
         }
      }
   }

   void dfs(T node)
   {
      stack<T> st;
      unordered_map<T, bool> visited;
      for(auto i : adj)
      {
         visited[i.first] = false;
      }

      st.push(node);
      while(true)
      {
         if(st.empty())
         {
            break;
         }
         T node = st.top();
         st.pop();
         if(!visited[node])
         {cout << node << ",";}
         visited[node] = true;
         for (auto j : adj[node])
         {
            if(!visited[j])
            {
               st.push(j);
            }
         }
      }
   }
};

int main()
{
   cout << "Enter number of nodes: ";
   int node;
   cin >> node;

   cout << "Enter number of edges: ";
   int edge;
   cin >> edge;

   graph<int> gh;

   cout << "Enter edges:" << endl;
   for(int i = 0; i < edge; i++)
   {
      int u,v;
      cin >> u >> v;
      gh.addEdge(u,v,false);
   }

   gh.printGraph();

   cout << "BFS search: ";
   gh.bfs(1);
   cout << endl;
   cout << "DFS search: ";
   gh.dfs(1);
   return 0;
}