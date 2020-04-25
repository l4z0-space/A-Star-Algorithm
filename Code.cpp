#include <bits/stdc++.h>
using namespace std;

               		// author: Lazaron Shyta   | A* Algorithm |


int d1[8] = {1,1,1,-1,-1,-1,0,0};
int d2[8] = {1,0,-1,1,0,-1,1,-1};

char Graph[100][100];
int m, n;              // dimensions
int startX, startY;
int targetX, targetY;

struct Node{

    int x, y;

    double F, G, H;

    Node(int _x, int _y){
        x = _x;
        y = _y;

        F=0;
        G=0;
        H=0;
    }

    Node& operator=(const Node& other){
        x = other.x;
        y = other.y;
        F = other.F;
        G = other.G;
        H = other.H;
        return *this;
    }

    bool operator<(const Node other){
        return F < other.F;
    }

    bool operator==(const Node& other){
        return (x == other.x && y == other.y);
    }

};


/* Calculate the heuristic [ H ] */
double calcH(Node a, Node b){

    return ( a.x - b.x ) * ( a.x - b.x )
                         +
           ( a.y - b.y ) * ( a.y - b.y );
}

bool FOUND = 0;

void Astar(Node start, Node target){

    vector<Node> OpenList, ClosedList;

    OpenList.push_back(start);

    while( OpenList.size() != 0 ){

        Node currNode = OpenList[0];
        int index = 0, finalIndex = 0;

        /* Node with minimum [ F ] */
        for( Node& someNode : OpenList ){
            if( someNode.F < currNode.F ){
                currNode   = someNode;
                finalIndex = index;
            }
            index ++;
        }

        /* Remove currentNode and add it to ClosedList */
        OpenList.erase( OpenList.begin() + finalIndex );
        ClosedList.push_back(currNode);

       /*  Mark in graph */
        Graph[currNode.x][currNode.y] = 'x';

        /* Check if found the target */
        if( currNode == target ){
            FOUND = 1;
            return;
        }

        /* Generate Neighbors */
        vector< Node > Neighbors;
        for( int i = 0; i < 8; i++){
            int nX, nY;
            nX = currNode.x + d1[i];
            nY = currNode.y + d2[i];

            // check if valid
            if(nX < 0 || nY < 0 || nX >= n || nY >= m || Graph[nX][nY] == '1' )
                continue;
            Node nextNode(nX,nY); // neighbor
            Neighbors.push_back(nextNode);
        }

        for( Node& someNode : Neighbors ){

            bool ok = 1;
            //  Ignore if in the ClosedList
            for ( Node& closedNode : ClosedList){
                if( closedNode == someNode ){
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            // Calculate G,H,F
            someNode.G = currNode.G + 1;
            someNode.H = calcH(someNode, target);
            someNode.F = someNode.G + someNode.H;

            // Check if already in the OpenList
            bool InOpenList = 0;
            for( Node& openNode : OpenList ){

                // not worthed adding to OpenList
                if( openNode == someNode && openNode.G < someNode.G ){
                    InOpenList = 1;
                    break;
                }
            }
            if( !InOpenList )
                OpenList.push_back(someNode);
        }
    }
}



int main() {

    // freopen("input.txt","r",stdin);

    cin >> n >> m;

    cin >> startX >> startY;
    cin >> targetX >> targetY;

    for( int i = 0 ; i < n ; i++ )
        for( int j = 0 ; j < m ; j++ )
            cin >> Graph[i][j];

    Node start(startX, startY);
    Node target(targetX, targetY);

    /* Call the function here. */
    Astar(start,target);

    if(!FOUND){
        cout<< " > Path doesn't exist!\n";
        return 0;
    }

    cout<<"\n\n > Path shown below...\n\n";
    Graph[start.x][start.y] = 's';
    Graph[target.x][target.y] = 'e';
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0; j < m; j++ ){
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
