#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

// Fonction pour construire le graphe à partir de la description de la fourmilière quatre
map<string, vector<string>> buildGraphQuatre() {
    vector<string> description = {
        "S3➔S4",
        "Sv➔S1",
        "S1➔S2",
        "S2➔S4",
        "S4➔S5",
        "S5➔Sd",
        "S4➔S6",
        "S6➔Sd",
        "S1➔S3"
    };
    map<string, vector<string>> graph;
    for (const string& line : description) {
        if (line.find("➔") != string::npos) {
            string start = line.substr(0, line.find("➔"));
            string end = line.substr(line.find("➔") + 3);
            start.erase(remove(start.begin(), start.end(), ' '), start.end());
            end.erase(remove(end.begin(), end.end(), ' '), end.end());
            graph[start].push_back(end);
            if (graph.find(end) == graph.end()) {
                graph[end] = {};
            }
        }
    }
    return graph;
}

// Fonction pour simuler les étapes de déplacement des fourmis pour la fourmilière quatre
int simulateAntsMovementQuatre(const map<string, vector<string>>& graph, int F) {
    string vestibule = "Sv";
    string dortoir = "Sd";

    vector<string> path = findShortestPath(graph, vestibule, dortoir);
    if (path.empty()) {
        cerr << "No path found from vestibule to dortoir." << endl;
        return -1;
    }

    int steps = 0;
    map<string, int> antsInPath;

    for (const string& node : path) {
        antsInPath[node] = 0;
    }

    while (F > 0 || antsInPath[dortoir] != path.size() - 1) {
        steps++;

        for (size_t i = 0; i < path.size() - 1; ++i) {
            if (antsInPath[path[i]] > 0 && antsInPath[path[i+1]] == 0) {
                antsInPath[path[i]]--;
                antsInPath[path[i+1]]++;
            }
        }

        if (antsInPath[vestibule] == 0 && F > 0) {
            antsInPath[vestibule]++;
            F--;
        }
    }

    return steps;
}
