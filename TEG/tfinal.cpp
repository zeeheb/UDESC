#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define INFINITO 1000000000
using namespace std;

class Grafo {
	private:
	public:
	    int v; // nro de vertices
	    list<pair<int, int>> * adj; // ex: adj[0].push_back(make_pair(1-destino-, X-custo-)
	    //construct
	    Grafo(int v) {
	    	this->v = v; // atribui vertices

	    	adj = new list<pair<int,int>>[v]; // cria listas de acordo com nro de vertices
	    }

	    void addAresta(int v1, int v2, int custo) {
	    	adj[v1].push_back(make_pair(v2, custo));                     // add de v1 p/ v2, o custo
	    }

	    int dijkstra (int orig, int dest) {
	      	int dist[v]; // vetor de distancias
	      	int visitados[v];

	      	if (adj[dest].size() == 0 || adj[orig].size() == 0){
	      		return 0;
	      	}

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
			            }
	          		}
	        	}
	      	}
					if(visitados[dest] == false) {
						cout << "impossible" << endl;
					} else {
						return dist[dest]; //retorna o minimo
					}
	    }
};

struct Matriz{
	vector<vector<int>> mat;
	int x;
	int y;
	pair<int, int> origem, destino;
};

struct Tabela{
	list<pair<int, int>> Tabela;
};

int makePantano();
Matriz criaMatriz(int x, int y);
void imprimeMatriz(Matriz m);
Matriz preencheLago(Matriz m, int c1, int r1, int c2, int r2);
int contaVertices(Matriz m);
Grafo criaGrafo(Matriz m);
Grafo addCalorias(Matriz m,int x,int y, Grafo g);
void imprimeGrafo(Grafo g);
Tabela addCed(Tabela t,int x, int y);

int main(){
	int p = 1;
	while(p == 1){
		p = makePantano();
	}
	return 0;
}

int makePantano(){
	Matriz Pantano;
	int c = -1, r = -1;
	while(c <= 0 || c > 1000 || r <= 0 || r > 1000){
		cin >> c >> r;
		if (c == 0 && r == 0){
			return 0;
		}
	}

	Pantano = criaMatriz(r,c);

	int orc = 0,orr = 0, dc = 0, dr = 0;
	while(orc <= 0 || orc > c || orr <= 0 || orr > r || dc <= 0 || dc > c || dr <= 0 || dr > r){
		cin >> orc >> orr >> dc >> dr;
	}
	//Pantano.mat[orr-1][orc-1] = -2;
	//Pantano.mat[dr-1][dl-1] = -3;

	Pantano.origem = make_pair(orr-1, orc-1);
	Pantano.destino = make_pair(dr-1, dc-1);

	int i = -1;
	while(i < 0 || i > 1000){
		cin >> i;
	}

	int C1 = 0, R1 = 0, C2 = 0, R2 = 0;
	for (int j = 0; j < i; j++){
		C1 = 0;
		R1 = 0;
		C2 = 0;
		R2 = 0;
		while(C1 <= 0 || C1 > c || C1 > C2 || C2 <= 0 || C2 > c || R1 <= 0 || R1 > r || R1 > R2 || R2 <= 0 || R2 > r ){
			cin >> C1 >> R1 >> C2 >> R2;
		}
		Pantano = preencheLago(Pantano, C1, R1, C2, R2);
	}
	imprimeMatriz(Pantano);

	Grafo mapa = criaGrafo(Pantano);

	//=cout << "1" << endl;

	for (int i = 0; i < Pantano.x; i++){
		for (int j = 0; j < Pantano.y; j++){
			if (Pantano.mat[i][j]==0){
				//cout << "2- " << i << ","<< j << endl << endl;
				mapa = addCalorias(Pantano,i,j,mapa);
				//cout << "\n2- " << i << ","<< j << endl;
			}
		}
	}

	//cout << "3" << endl;

	//imprimeGrafo(mapa);

	//cout << "4" << endl;

	int origem,destino;
	origem = Pantano.origem.first * (Pantano.y) + Pantano.origem.second + 1;
	destino = Pantano.destino.first * (Pantano.y) + Pantano.destino.second + 1;
	int ret = mapa.dijkstra(origem,destino);

	//cout << "5" << endl;

	if (ret == 0){
		cout << endl << "impossible" << endl << endl;
	}else{
		cout << endl << ret << endl << endl;
	}
	return 1;
}

Matriz criaMatriz(int x, int y){ // Cria uma matriz X x Y zerada
    Matriz m;
    vector<int> v;

    m.mat.clear();

    m.x = x;
    m.y = y;

    for(int a = 0; a < x; a++){
        for(int b = 0; b < y; b++){
            v.push_back(0);
        }
        m.mat.push_back(v);
    }

    m.origem = make_pair(0,0);
    m.destino = make_pair(x,y);

    return m;
}

void imprimeMatriz(Matriz m){ // Imprime o conteudo da matriz m
    cout << "Origem: " << m.origem.first << "," << m.origem.second << endl;
    cout << "Destino: " << m.destino.first << "," << m.destino.second << endl << endl;
    cout << "\t";
    for(int a = 0; a < m.y; a++){
        cout << a << "\t";
    }
    cout << endl;
    for(int a = 0; a < m.x; a++){
        cout << a << "\t";
        for(int b = 0; b < m.y; b++){
            cout << m.mat[a][b] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

Matriz preencheLago(Matriz m, int c1, int r1, int c2, int r2){
	Matriz aux = m;
	for (int i = c1; i <= c2; i++){
		for (int j = r1; j <= r2; j++){
			if (aux.mat[j-1][i-1] == 0){
				aux.mat[j-1][i-1] = -1;
			}
		}
	}
	return aux;
}

int contaVertices(Matriz m){
	int ret = 0;

	for (int i = 0; i < m.x; ++i){
		for (int j = 0; j < m.y; ++j){
			if (m.mat[i][j]==0){
				ret++;
			}
		}
	}

	return ret + 2;
}

Grafo criaGrafo(Matriz m){
	int vertices = m.x * m.y;
	Grafo ret(vertices);
	return ret;
}

Grafo addCalorias(Matriz m,int x,int y, Grafo g){
	Matriz aux = m;
	Grafo auxg = g;
	int c = y,r = x,c1=0;
	int vertO,vertD;

	vertO = r * (m.y) + c + 1;
	/* Tabela de calorias:
		7 6 5 6 7			a b c d e
		6 3 2 3 6			f g h i j
		5 2 F 2 5			k l F m n
		6 3 2 3 6			o p q r s
		7 6 5 6 7			t u v x w
	*/
	if (c>=1){// l
		if (aux.mat[r][c-1] == 0){
			vertD = vertO - 1;
			//cout << "l " << vertO << " " << vertD << " " << c1 << endl;
			auxg.addAresta(vertO,vertD,2);
		}
		c1++;
		if (c>=2){// k
			if (aux.mat[r][c-2] == 0){
				vertD = vertO - 2;
				//cout << "k " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,5);
			}
			c1++;
		}
	}
	if (r>=1){// h
		if (aux.mat[r-1][c] == 0){
			vertD = vertO - (m.y);
			//cout << "h " << vertO << " " << vertD << " " << c1 << endl;
			auxg.addAresta(vertO,vertD,2);
		}
		if (c1>=1){// g
			if (aux.mat[r-1][c-1] == 0){
				vertD = vertO - (m.y) - 1;
				//cout << "g " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,3);
			}
			if(c1>=2){// f
				if (aux.mat[r-1][c-2] == 0){
					vertD = vertO - (m.y) - 2;
					//cout << "f " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
			}
		}
		if (r>=2){// c
			if (aux.mat[r-2][c] == 0){
				vertD = vertO - 2 * (m.y);
				//cout << "c " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,5);
			}
			if (c1>=1){// b
				if (aux.mat[r-2][c-1] == 0){
					vertD = vertO - 2 * (m.y) - 1;
					//cout << "b " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
				if(c1>=2){// a
					if (aux.mat[r-2][c-2] == 0){
						vertD = vertO - 2 * (m.y) - 2;
						//cout << "a " << vertO << " " << vertD << " " << c1 << endl;
						auxg.addAresta(vertO,vertD,7);
					}
				}
			}
		}
	}
	if (r<aux.x-1){// q
		if (aux.mat[r+1][c] == 0){
			vertD = vertO + (m.y);
			//cout << "q " << vertO << " " << vertD << " " << c1 << endl;
			auxg.addAresta(vertO,vertD,2);
		}
		if (c1>=1){// p
			if (aux.mat[r+1][c-1] == 0){
				vertD = vertO + (m.y) - 1;
				//cout << "p " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,3);
			}
			if(c1>=2){// o
				if (aux.mat[r+1][c-2] == 0){
				vertD = vertO + (m.y) - 2;
				//cout << "o " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,6);
				}
			}
		}
		if (r<aux.x-2){// v
			if (aux.mat[r+2][c] == 0){
				vertD = vertO + 2 * (m.y);
				//cout << "v " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,5);
			}
			if (c1>=1){// u
				if (aux.mat[r+2][c-1] == 0){
					vertD = vertO + 2 * (m.y) -1;
					//cout << "u " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
				if(c1>=2){// t
					if (aux.mat[r+2][c-2] == 0){
						vertD = vertO + 2 * (m.y) -2;
						//cout << "t " << vertO << " " << vertD << " " << c1 << endl;
						auxg.addAresta(vertO,vertD,7);
					}
				}
			}
		}
	}
	//---------------------------------------------------------
	c1=0;
	if (c<aux.y-1){// m
		if (aux.mat[r][c+1] == 0){
			vertD = vertO + 1;
			//cout << "m " << vertO << " " << vertD << " " << c1 << endl;
			auxg.addAresta(vertO,vertD,2);
		}
		c1++;
		if (c<aux.y-2){// n
			if (aux.mat[r][c+2] == 0){
				vertD = vertO + 2;
				//cout << "n " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,5);
			}
			c1++;
		}
	}
	if (r>=1){
		if (c1>=1){// i
			if (aux.mat[r-1][c+1] == 0){
				vertD = vertO - (m.y) + 1;
				//cout << "i " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,3);
			}
			if(c1>=2){// j
				if (aux.mat[r-1][c+2] == 0){
					vertD = vertO - (m.y) + 2;
					//cout << "j " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
			}
		}
		if (r>=2){
			if (c1>=1){// d
				if (aux.mat[r-2][c+1] == 0){
					vertD = vertO - 2 * (m.y) + 1;
					//cout << "d " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
				if(c1>=2){// e
					if (aux.mat[r-2][c+2] == 0){
						vertD = vertO - 2 * (m.y) + 2;
						//cout << "e " << vertO << " " << vertD << " " << c1 << endl;
						auxg.addAresta(vertO,vertD,7);
					}
				}
			}
		}
	}
	if (r<aux.x-1){
		if (c1>=1){// r
			if (aux.mat[r+1][c+1] == 0){
				vertD = vertO + (m.y) + 1;
				//cout << "r " << vertO << " " << vertD << " " << c1 << endl;
				auxg.addAresta(vertO,vertD,3);
			}
			if(c1>=2){// s
				if (aux.mat[r+1][c+2] == 0){
					vertD = vertO + (m.y) + 2;
					//cout << "s " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
			}
		}
		if (r<aux.x-2){
			if (c1>=1){// x
				if (aux.mat[r+2][c+1] == 0){
					vertD = vertO + 2 * (m.y) + 1;
					//cout << "x " << vertO << " " << vertD << " " << c1 << endl;
					auxg.addAresta(vertO,vertD,6);
				}
				if(c1>=2){// w
					if (aux.mat[r+2][c+2] == 0){
						vertD = vertO + 2 * (m.y) + 2;
						//cout << "w " << vertO << " " << vertD << " " << c1 << endl;
						auxg.addAresta(vertO,vertD,7);
					}
				}
			}
		}
	}
	return auxg;
}

void imprimeGrafo(Grafo g){
	int i = 0;
	for (int a = 0; a < g.v; ++a){
		i = g.adj[a].size();
		cout << a << ".\t";
		for (int b = 0; b < i; ++b){
			cout << "a ";
		}
		cout << endl;
	}
}
