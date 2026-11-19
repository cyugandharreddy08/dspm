#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAX_BUILDINGS = 20;

class CollegeGraphBFS {
private:
    int numBuildings;
    vector<string> buildingNames;
    int adjMatrix[MAX_BUILDINGS][MAX_BUILDINGS];

public:
    CollegeGraphBFS(int n) {
        numBuildings = n;
        buildingNames.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void setBuildingName(int index, const string& name) {
        if (index >= 0 && index < numBuildings) {
            buildingNames[index] = name;
        }
    }

    string getBuildingName(int index) const {
        if (index >= 0 && index < numBuildings) {
            return buildingNames[index];
        }
        return "Unknown";
    }

    void addPathway(int u, int v) {
        if (u >= 0 && u < numBuildings && v >= 0 && v < numBuildings) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    void displayCampusMap() {
        cout << "\n--- College Campus Buildings ---\n";
        for (int i = 0; i < numBuildings; i++) {
            cout << " [" << i << "] " << buildingNames[i] << "\n";
        }

        cout << "\n--- Direct Pathways Between Buildings ---\n";
        for (int i = 0; i < numBuildings; i++) {
            cout << buildingNames[i] << " is directly connected to: ";
            bool hasPath = false;
            for (int j = 0; j < numBuildings; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << "[" << buildingNames[j] << "] ";
                    hasPath = true;
                }
            }
            if (!hasPath) cout << "None";
            cout << "\n";
        }
    }

    void performBFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numBuildings) {
            cout << "Invalid starting building index!\n";
            return;
        }

        bool visited[MAX_BUILDINGS] = {false};
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "\n=======================================================\n";
        cout << "BFS Traversal Starting from: " << buildingNames[startVertex] << "\n";
        cout << "=======================================================\n";

        int step = 1;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << "Step " << step++ << ": Visited -> " << buildingNames[current] << " (ID: " << current << ")\n";

            for (int neighbor = 0; neighbor < numBuildings; neighbor++) {
                if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "=======================================================\n";
    }
};

int main() {

    const int N = 8;
    CollegeGraphBFS campus(N);

    campus.setBuildingName(0, "Main Campus Gate");
    campus.setBuildingName(1, "Administrative Block");
    campus.setBuildingName(2, "CSE & IT Department");
    campus.setBuildingName(3, "Central Library");
    campus.setBuildingName(4, "Auditorium & Convocation Hall");
    campus.setBuildingName(5, "Student Activity Center (SAC)");
    campus.setBuildingName(6, "Hostel Complex");
    campus.setBuildingName(7, "Campus Cafeteria & Food Court");

    campus.addPathway(0, 1);
    campus.addPathway(0, 4);
    campus.addPathway(1, 2);
    campus.addPathway(1, 3);
    campus.addPathway(2, 3);
    campus.addPathway(2, 5);
    campus.addPathway(3, 7);
    campus.addPathway(4, 5);
    campus.addPathway(5, 6);
    campus.addPathway(6, 7);

    campus.displayCampusMap();

    int startBuilding;
    cout << "\nEnter starting building index for BFS (0 to " << N - 1 << "): ";
    cin >> startBuilding;

    campus.performBFS(startBuilding);

    return 0;
}
