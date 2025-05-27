#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

// Déclarations des fonctions des fichiers des fourmilières
map<string, vector<string>> buildGraphZero();
int simulateAntsMovementZero(const map<string, vector<string>>& graph, int F);

map<string, vector<string>> buildGraphUn();
int simulateAntsMovementUn(const map<string, vector<string>>& graph, int F);

map<string, vector<string>> buildGraphDeux();
int simulateAntsMovementDeux(const map<string, vector<string>>& graph, int F);

map<string, vector<string>> buildGraphTrois();
int simulateAntsMovementTrois(const map<string, vector<string>>& graph, int F);

map<string, vector<string>> buildGraphQuatre();
int simulateAntsMovementQuatre(const map<string, vector<string>>& graph, int F);

map<string, vector<string>> buildGraphCinq();
int simulateAntsMovementCinq(const map<string, vector<string>>& graph, int F);

// Fonction pour trouver le chemin le plus court en utilisant BFS
vector<string> findShortestPath(const map<string, vector<string>>& graph, const string& start, const string& end) {
    map<string, string> parent;
    queue<string> q;
    q.push(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        auto it = graph.find(current);
        if (it != graph.end()) {
            for (const string& neighbor : it->second) {
                if (parent.find(neighbor) == parent.end()) {
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }
    }

    vector<string> path;
    string current = end;
    while (current != start) {
        auto it = parent.find(current);
        if (it == parent.end()) {
            // Si le chemin n'existe pas, retournez un chemin vide
            return {};
        }
        path.push_back(current);
        current = it->second;
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    // Construire les graphes et simuler les étapes de déplacement des fourmis pour chaque fourmilière
    map<string, vector<string>> graphZero = buildGraphZero();
    int stepsZero = simulateAntsMovementZero(graphZero, 2);
    cout << "Fourmiliere zero - Nombre minimal d'etapes necessaires : " << stepsZero << endl;

    map<string, vector<string>> graphUn = buildGraphUn();
    int stepsUn = simulateAntsMovementUn(graphUn, 5);
    cout << "Fourmiliere un - Nombre minimal d'etapes necessaires : " << stepsUn << endl;

    map<string, vector<string>> graphDeux = buildGraphDeux();
    int stepsDeux = simulateAntsMovementDeux(graphDeux, 5);
    cout << "Fourmiliere deux - Nombre minimal d'etapes necessaires : " << stepsDeux << endl;

    map<string, vector<string>> graphTrois = buildGraphTrois();
    int stepsTrois = simulateAntsMovementTrois(graphTrois, 5);
    cout << "Fourmiliere trois - Nombre minimal d'etapes necessaires : " << stepsTrois << endl;

    map<string, vector<string>> graphQuatre = buildGraphQuatre();
    int stepsQuatre = simulateAntsMovementQuatre(graphQuatre, 10);
    cout << "Fourmiliere quatre - Nombre minimal d'etapes necessaires : " << stepsQuatre << endl;

    map<string, vector<string>> graphCinq = buildGraphCinq();
    int stepsCinq = simulateAntsMovementCinq(graphCinq, 10);
    cout << "Fourmiliere cinq - Nombre minimal d'etapes necessaires : " << stepsCinq << endl;

    return 0;
}
