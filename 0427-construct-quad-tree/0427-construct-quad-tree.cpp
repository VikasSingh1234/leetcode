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
public:
    bool sameValue(vector<vector<int>>& grid, int x, int y, int length) {
        for (int i = x; i < x + length; i++) {
            for (int j = y; j < y + length; j++)
                if (grid[i][j] != grid[x][y])
                    return false;
        }
        return true;
    }
    
    Node* helper(vector<vector<int>>& grid, int x, int y, int length) {
        if (sameValue(grid, x, y, length)) {
            return new Node(grid[x][y], true);
        } else {
            Node* root = new Node(false, false);

            root -> topLeft = helper(grid, x, y, length / 2);
            root -> topRight = helper(grid, x, y + length / 2, length / 2);
            root -> bottomLeft = helper(grid, x + length / 2, y, length / 2);
            root -> bottomRight = helper(grid, x + length / 2, y + length / 2, length / 2);

            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
};