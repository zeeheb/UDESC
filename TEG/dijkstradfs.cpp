#include <stack>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#define INFINITO 100000000

using namespace std;

class Grafo {
private:
    int v; // nro de vertices
    list<pair<int, int>> * adj; // ex: adj[0].push_back(make_pair(1-destino-, X-custo-)
    list<int> *adj2;
public:
    //construct
    Grafo(int v) {
      this->v = v; // atribui vertices

      adj = new list<pair<int,int>>[v]; // cria listas de acordo com nro de vertices
      adj2 = new list<int>[v];
    }

    void addAresta(int v1, int v2, int custo) {
      adj[v1].push_back(make_pair(v2, custo));                           // add de v1 p/ v2, o custo
      adj2[v1].push_back(v2);
    }

    int dijkstra (int orig, int dest) {
      int dist[v]; // vetor de distancias
      int visitados[v];
      vector<int> caminho;
      caminho.push_back(0);

      priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

      // inicia vetor de dist e visitados
      for (int i = 0; i < v; i++){
        dist[i] = INFINITO;
        visitados[i] = false;
      }

      dist[orig] = 0; //sempre origem = 0

      //insere na fila de prioridade
      pq.push(make_pair(dist[orig], orig));

      while(!pq.empty()) { //loop do algoritmo
        pair<int, int> p = pq.top(); //extrai o pair do topo
        int u = p.second; // obtem o vertice do pair
        pq.pop();

        if(visitados[u] == false) { //verifica se vertice n foi expandido
          visitados[u] = true; //marca como visitado

          list<pair<int, int>>::iterator it; //cria uma iterator para percorrer a lista

          for(it = adj[u].begin(); it != adj[u].end(); it++) { //percore os v adjacentes de u
            int v = it-> first;
            int custoAresta = it->second;

            if(dist[v] > (dist[u] + custoAresta)) { //relaxamento (u, v)
              dist[v] = dist[u] + custoAresta;
              pq.push(make_pair(dist[v], v));
              caminho.push_back(u);


            }
          }
        }
      }

    //  for(auto it = caminho.begin(); it != caminho.end(); it++) {
      //    cout << *it << endl;
    //  }


      return dist[dest]; //retorna o minimo
    }

    int dfs(int v, int dest) {
      vector<int> auxNV;
      stack<int> pilha;
      bool visitados[v]; // vetor de visitados

      for(int i=0; i < v; i++)  // bota todos como nao visitados
        visitados[i] = false;


      while(true) {
        if(!visitados[v]) {
          cout << "visitando vertice: " << v << " .... \n";
          visitados[v] = true; // marca como visitados
          pilha.push(v); // insere v na pilha
          auxNV.push_back(v);
        }

        bool achou = false;
        list<int>::iterator it;

        for(it = adj2[v].begin(); it != adj2[v].end(); it++) { // busca em vizinhos algum nao visitado
          if(!visitados[*it]) {
            achou = true;
            break;
          }
        }

        if(achou)
          v = *it; // atualiza o v
         else {
          pilha.pop();

          if(pilha.empty())
            break;

          v = pilha.top();
        }

      }

          // visita todos os componentes do vector auxiliar de visitados, se nao encontrar o destino passado
          // retorna 0, se achar retorna 1
            if((find(auxNV.begin(), auxNV.end(), dest) != auxNV.end()) == false) {
              cout << " nao visitou: " << dest << endl;
              return 0;
            } else {
              return 1;
            }

    }




};


int main(int argc, char const *argv[]) {
  Grafo g(5);

  // exemplo de grafo com vertice 2 desconexo
  g.addAresta(0,1,1);
  g.addAresta(0,4,10);
  g.addAresta(0,3,4);
  g.addAresta(2,4,5);
  //g.addAresta(2,4,1);
  g.addAresta(3,4,6);
  //g.addAresta(3,2,2);

  cout << "Total: " << g.dijkstra(0,4) << endl;
  int ret = g.dfs(0,2); // retorna 0 se nao achar , 1 se achar ---- primeiro parametro: inicio, segundo: destino
  if (ret == 0) {
    cout << "impossible" << endl;
  }

  return 0;
}
