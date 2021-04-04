#include <iostream>
using namespace  std;
const int h = 65535;
const int MAXEDGE = 20;
const int MAXVEX = 9;
int sum = 0;
/*{h ,12,8 ,21,h ,h ,h ,h ,0 }*/
/*{0 ,10,h ,h ,h ,11,h ,h ,h }*/
int MGragh[9][9] = {{0 ,10,h ,h ,h ,11,h ,h ,h },
                    {10,0 ,18,h ,h ,h ,16,h ,12},
                    {h ,h ,0 ,22,h ,h ,h ,h ,8 },
                    {h ,h ,22,0 ,20,h ,24,16,21},
                    {h ,h ,h ,20,0 ,26,h ,7 ,h },
                    {11,h ,h ,h ,26,0 ,17,h ,h },
                    {h ,16,h ,h ,h ,17,0 ,19,h },
                    {h ,h ,h ,16,7 ,h ,19,0 ,h },
                    {h ,12,8 ,20,h ,h ,h ,h ,0 }};
class MGra{
public:
    MGra(int num_vertexes,int num_edges):num_vertexes(num_vertexes),num_edges(num_edges){};
    int num_vertexes;
    int num_edges;
    int arc[9][9];
};
class Edge{
public:
    int begin;
    int end;
    int weight;
};

void translate(MGra G , Edge edges[]){
    int count = 0;
    Edge mid;
    for (int i = 0; i < 9; ++i) {
        for (int j = i ; j < 9; ++j) {
            if (G.arc[i][j] > 0 && G.arc[i][j] < h /*&& count < 14*/){
                edges[count].begin = i;
                edges[count].end = j;
                edges[count].weight = G.arc[i][j];
                count += 1;
            }
           /* if(count == 14){
                edges[count].begin = i;
                edges[count].end = j;
                edges[count].weight = G.arc[i][j];
                count++;
            }*/
        }
    }
    for (int i = 0; i < G.num_edges -1 ; ++i) {
        for (int j = 0; j < G.num_edges -1  -i ; ++j) {
            if(edges[j].weight > edges[j + 1].weight ){
                mid = edges[j+1];
                edges[j+1] = edges[j];
                edges[j] = mid;
            }
        }
    }
}

int Find( int * parent,int f){
    while ( parent[f] > 0 ){
        f = parent[f];
    }
    return f;
}


void MiniSpanTree_Kruskal( MGra G ){
    int  n , m;
    Edge edges[MAXEDGE]; //定义的边集数组
    int parent[MAXVEX];  // 判断是否形成环路的数组

   translate( G, edges); // 将图换为边际数组

    for (int i = 0; i < G.num_vertexes; ++i) {
        parent[i] = 0;
    }
    for (int i = 0; i < G.num_edges; ++i) {
        n = Find( parent , edges[i].begin);
        m = Find( parent , edges[i].end);
        if(n != m){
            parent[n] = m;  // 将此点加入生成树内
            sum += edges[i].weight;
            cout << "from : "<<edges[i].begin << " to  "<<edges[i].end << "  weight  :" << edges[i].weight << endl;
        }
    }


}
int main() {

    MGra G(9,15);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            G.arc[i][j] = MGragh[i][j];
        }
    }
    MiniSpanTree_Kruskal( G );
    cout << "final sum : " << sum;


    return 0;
}
