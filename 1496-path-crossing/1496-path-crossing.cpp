class Solution {
public:
    bool isPathCrossing(string path) {
        // Using a map to store visited coordinates and a boolean value
        map<pair<int,int>, bool> visited;
        int x = 0, y = 0; // Initializing the starting point (0,0)

        for(auto c : path){
            visited[{x, y}] = true; // Mark the current coordinate as visited

            // Update the coordinates based on the direction
            if(c == 'N') y++; // Move north
            else if(c == 'S') y--; // Move south
            else if(c == 'E') x++; // Move east
            else x--; // Move west

            // Check if the current coordinate has been visited before
            if(visited[{x, y}]) return true; // If visited, there's a crossing
        }

        return false; // No crossing found along the path
    }
};