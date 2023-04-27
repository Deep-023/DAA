#include <bits/stdc++.h>
using namespace std;
#define N 4

struct Node
{
    Node* parent;
    int mat[N][N];
    int x, y;
    int cost;
    int level;
};

int printMat(int mat[N][N])
{
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

Node* newChild(int mat[N][N], int x, int y, int newX,
            int newY, int level, Node* parent)
{
    Node* node = new Node;
    node->parent = parent;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->cost = INT_MAX;
    node->level = level;
    node->x = newX;
    node->y = newY;

    return node;
}

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

int checkCost(int intialMat[N][N], int finalMat[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        if (intialMat[i][j] && intialMat[i][j] != finalMat[i][j])
        count++;
    return count;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void print(Node* rootNode)
{
    if (rootNode == NULL)
        return;
    print(rootNode->parent);
    printMat(rootNode->mat);
  cout << "\nCost = " << rootNode->level << " + " << rootNode->cost  << " = " << rootNode->cost + rootNode->level << endl;
    printf("\n\n");
}

struct compare
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

void solve(int intialMat[N][N], int x, int y,
        int finalMat[N][N])
{
    
    priority_queue<Node*, std::vector<Node*>, compare> pq;
    Node* rootNode = newChild(intialMat, x, y, x, y, 0, NULL);
    rootNode->cost = checkCost(intialMat, finalMat);
    
    pq.push(rootNode);
    
    while (!pq.empty())
    {
        
        Node* min = pq.top();
        pq.pop();

        if (min->cost == 0)
        {
            
            print(min);

            return;
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
            
                Node* child = newChild(min->mat, min->x,
                            min->y, min->x + row[i],
                            min->y + col[i],
                            min->level + 1, min);
                child->cost = checkCost(child->mat, finalMat);  
                pq.push(child);
            }
        }
    }
}

int main()
{
    int intialMat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 0, 8},
        {9, 10,7, 11},
    {13,14,15,12}
    };
    int finalMat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    {13, 14, 15, 0}
    };
    int x = 1, y = 2;
  cout << "Inital Puzzle: " << endl;
    solve(intialMat, x, y, finalMat);

    return 0;
}

