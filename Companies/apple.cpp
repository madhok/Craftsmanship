/* 
Your previous Plain Text content is preserved below:

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

You can also change the default language your pads are created with
in your account settings: https://coderpad.io/settings

Enjoy your interview!


You have been given flight data in the following manner:

SJC -> SEA
SJC -> CHICAGO
SEA -> ATL
SJC -> DEN
JFK -> MIA
ATL -> MIA
LAS -> MIA
MIA -> SJC
ORD -> DEN
ATL -> LAX
JFK -> SFO
CHICAGO -> JFK

Given a source and destination, find a route between the airports. You can not visit same airport more than once.


 */
#include <iostream>
#include <list>
#include <vector>
using namespace std;


int getplace(string place) {
  string places[11] = {"SJC",
                "SEA",
               "CHICAGO",
               "ATL",
               "DEN",
               "JFK",
               "MIA",
               "LAS",
               "ORD",
               "LAX",
               "SFO"
                };
  
  for(int i = 0; i < 11;++i) {
    if(place == places[i])
        return i;
  }
  return -1;
  
}


class Graph {
  public:
  int V;
  list<int> *adj;
  Graph(int _V) {
    V= _V;
    adj = new list<int>[V];
  }
  void addEdge(int v, int w);
  void DFS(int v, int w);
  void DFSutil(int v, bool visited[],int dest,
              vector<int>&result,bool& reached);
};

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::DFS(int v, int dest) {
  bool visited[V] = {false};
  vector<int>result;
  result.push_back(v);
  bool reached = false;
  DFSutil(v,visited,dest,result, reached);
  
  if(reached) {
  for(int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
    }
  }
}

void Graph::DFSutil(int v, bool visited[],int dest,
              vector<int>&result, bool& reached) {
  if(v == -1) {
      return;
  }
  visited[v] = true;
  if(v == dest) {
    reached = true;
    return;
  }
  for(auto i = adj[v].begin(); i != adj[v].end(); ++i) {
    if(!visited[*i]){
      result.push_back(*i);
      //cout << "v " << v << "  i : " << *i << " dest: " << dest << endl;
      DFSutil(*i,visited,dest,result, reached);
      if(!reached) {
        result.pop_back();
      } else {
          return;
      }
    }
  }
  visited[v] = false;
}
  
  
int main() {
  Graph g(11);
  g.addEdge(getplace("SJC"),getplace("SEA"));
  g.addEdge(getplace("SJC"),getplace("CHICAGO"));
  g.addEdge(getplace("SEA"),getplace("ATL"));
  g.addEdge(getplace("SJC"),getplace("DEN"));
  g.addEdge(getplace("JFK"),getplace("MIA"));
  g.addEdge(getplace("ATL"),getplace("MIA"));
  g.addEdge(getplace("LAS"),getplace("MIA"));
  g.addEdge(getplace("MIA"),getplace("SJC"));
  g.addEdge(getplace("ORD"),getplace("DEN"));
  g.addEdge(getplace("ATL"),getplace("LAX"));
  g.addEdge(getplace("JFK"),getplace("SFO"));
  g.addEdge(getplace("CHICAGO"),getplace("JFK"));

  g.DFS(getplace("SJC"), getplace("CHICAGO"));
  
  return 0;
}









