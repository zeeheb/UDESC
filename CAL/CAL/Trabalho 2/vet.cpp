#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

    int n;
    cin >> n;
    vector<pair<int,pair<string, string>>> v;    // index, nome e sobrenome

    for(int i=0; i<n; i++) {
        int aux;
        string nome, snome;
        cin >> n >> nome >> snome;
        v.push_back(make_pair(n, make_pair(nome, snome)));
    }

/*  TESTE   for(int i=0; i<n; i++) {
                cout << v[i].first << ' ' << v[i].second.first << v[i].second.second <<endl;
    }

*/

    int m;
    cin >> m;
    vector<pair<string,string>> v2;

    for(int i=0; i<m; i++) {
        string nome2, snome2;
        cin >> nome2 >> snome2;
        v2.push_back(make_pair(nome2, snome2));
    }

    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            if (!v2[j].first.compare(v[i].second.first) && (!v2[j].second.compare(v[i].second.second))) {
                cout << v[i].first << endl;
            }
        }
    }




}
