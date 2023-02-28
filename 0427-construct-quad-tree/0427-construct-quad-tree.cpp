/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node *dfs(vector<vector<int>> &grid, int rows, int cols, int i, int j) {
        Node *node = new Node();

        int isLeaf = 1;
        int val = grid[i][j];

        for (int k = i; k < rows + i && isLeaf; ++k) {
            for (int l = j; l < cols + j && isLeaf; ++l) {
                if (grid[k][l] != val) isLeaf = 0;
            }
        }

        node->isLeaf = isLeaf;
        node->val = val;

        if (!isLeaf) {
            node->topLeft = dfs(grid, rows / 2, cols / 2, i, j);
            node->topRight = dfs(grid, rows / 2, cols / 2, i, j + cols / 2);
            node->bottomLeft = dfs(grid, rows / 2, cols / 2, i + rows / 2, j);
            node->bottomRight = dfs(grid, rows / 2, cols / 2, i + rows / 2, j + cols / 2);
        }

        return node;
    }

public:
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        return dfs(grid, n, n, 0, 0);
    }
};