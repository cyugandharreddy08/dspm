#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_BUILDINGS = 20;

class CollegeGraphDFS {
private:
    int numBuildings;
    vector<string> buildingNames;
    int adjMatrix[MAX_BUILDINGS][MAX_BUILDINGS];
    bool visited[MAX_BUILDINGS];
    int stepCounter;

    // Recursive helper function for DFS
    void dfsRecursive(int current) {
        visited[current] = true;
        cout << "Step " << stepCounter++ << ": Visited -> " 
             << buildingNames[current] << " (ID: " << current << ")\n";

        for (int neighbor = 0; neighbor < numBuildings; neighbor++) {
            if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                dfsRecursive(neighbor);
            }
        }
    }

public:
    CollegeGraphDFS(int n) {
        numBuildings = n;
        buildingNames.resize(n);
        stepCounter = 1;
        for (int i = 0; i < n; i++) {
            visited[i] = false;
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

    // Add an undirected pathway connecting two buildings
    void addPathway(int u, int v) {
        if (u >= 0 && u < numBuildings && v >= 0 && v < numBuildings) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    // Display campus buildings and paths
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

    // Depth-First Search (DFS) Traversal
    void performDFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numBuildings) {
            cout << "Invalid starting building index!\n";
            return;
        }

        for (int i = 0; i < numBuildings; i++) {
            visited[i] = false;
        }
        stepCounter = 1;

        cout << "\n=======================================================\n";
        cout << "DFS Traversal Starting from: " << buildingNames[startVertex] << "\n";
        cout << "=======================================================\n";

        dfsRecursive(startVertex);

        // Check if there are any disconnected components
        for (int i = 0; i < numBuildings; i++) {
            if (!visited[i]) {
                cout << "\nVisiting disconnected building component:\n";
                dfsRecursive(i);
            }
        }

        cout << "=======================================================\n";
    }
};

int main() {
    // 8 standard campus buildings
    const int N = 8;
    CollegeGraphDFS campus(N);

    campus.setBuildingName(0, "Main Campus Gate");
    campus.setBuildingName(1, "Administrative Block");
    campus.setBuildingName(2, "CSE & IT Department");
    campus.setBuildingName(3, "Central Library");
    campus.setBuildingName(4, "Auditorium & Convocation Hall");
    campus.setBuildingName(5, "Student Activity Center (SAC)");
    campus.setBuildingName(6, "Hostel Complex");
    campus.setBuildingName(7, "Campus Cafeteria & Food Court");

    // Realistic campus pathways
    campus.addPathway(0, 1); // Gate - Admin Block
    campus.addPathway(0, 4); // Gate - Auditorium
    campus.addPathway(1, 2); // Admin Block - CSE Department
    campus.addPathway(1, 3); // Admin Block - Central Library
    campus.addPathway(2, 3); // CSE Department - Central Library
    campus.addPathway(2, 5); // CSE Department - SAC
    campus.addPathway(3, 7); // Central Library - Cafeteria
    campus.addPathway(4, 5); // Auditorium - SAC
    campus.addPathway(5, 6); // SAC - Hostel Complex
    campus.addPathway(6, 7); // Hostel Complex - Cafeteria

    campus.displayCampusMap();

    int startBuilding;
    cout << "\nEnter starting building index for DFS (0 to " << N - 1 << "): ";
    cin >> startBuilding;

    campus.performDFS(startBuilding);

    return 0;
}
