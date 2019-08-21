#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int n,m;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    cin >> m;
    int cont = 0;

    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        if(*it == m) {
            cont++;
        }
    }

    cout << "Total: " << cont << endl;


    return 0;
}
