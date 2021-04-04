#include <iostream>
using namespace std;
const int h = 65535;
/*const int num_point  = 9;*/
/*int MGragh[9][9] = {{0 ,10,h ,h ,h ,11,h ,h ,h },
                    {10,0 ,18,h ,h ,h ,16,h ,12},
                    {h ,h ,0 ,22,h ,h ,h ,h ,8 },
                    {h ,h ,22,0 ,20,h ,h ,16,21},
                    {h ,h ,h ,20,0 ,26,h ,7 ,h },
                    {11,h ,h ,h ,26,0 ,17,h ,h },
                    {h ,16,h ,h ,h ,17,0 ,19,h },
                    {h ,h ,h ,16,7 ,h ,19,0 ,h },
                    {h ,12,8 ,21,h ,h ,h ,h ,0 },};*/

class MGra{
public:
    MGra(int num_vertexes):num_vertexes(num_vertexes){};
    int num_vertexes;
    int arc[50][50];
};


void MiniSpanTree_Prim(MGra G){
    int i , j, k; // 计数器罢了
    int min ; // 记录 每次走向下一点的最短距离
    int adjvex[h]; // 保存各顶点下标
    int lowcost[h];

    lowcost[0] = 0;  //初始化  将V0加入生成树（即从V0开始执行） 此时V0 已经使用
    adjvex[0] = 0;
    for(i = 1; i < G.num_vertexes ; i++){
        lowcost[i] = G.arc[0][i]; // 将邻接的 都存入 lowcost数组 初始化此处存入了到V1 V5 {0 10 h h h 11 h h h}
        adjvex[i] = 0; // 目前各接触的点都为0
    }
    for (i = 1; i < G.num_vertexes ; i++ ){
        min = h;

        j = 1; k = 0; // k 为 记录前往下一个点 最短距离的 下标
        while ( j < G.num_vertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("( %d, %d )",adjvex[k],k); // 打印路径
        lowcost[k] = 0 ; // 将该 下一点 最短距离的 下标的点 使用（即加入最小生成树）
        for(j = 1; j < G.num_vertexes ; j++){
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j]){// 将 上述使用的点 周围距离较短的 路径加入 lowcost
                lowcost[j] = G.arc[k][j]; //{0 0 h h h 11 16 h 12}  (将[1]除去 在[6]变成了 16 说明此时到V6 最短路径更新为16
                adjvex[j] = k ; // 同时 更新 距离其他点更短的路径的点的下标 { 0 0 1 0 0 0 1 0 1 } 此时 [2] 最近的为 点 [1]
            }
        }
    }

}
int main(){
    int MGragh[9][9] = {{0 ,10,h ,h ,h ,11,h ,h ,h },
                        {10,0 ,18,h ,h ,h ,16,h ,12},
                        {h ,h ,0 ,22,h ,h ,h ,h ,8 },
                        {h ,h ,22,0 ,20,h ,h ,16,21},
                        {h ,h ,h ,20,0 ,26,h ,7 ,h },
                        {11,h ,h ,h ,26,0 ,17,h ,h },
                        {h ,16,h ,h ,h ,17,0 ,19,h },
                        {h ,h ,h ,16,7 ,h ,19,0 ,h },
                        {h ,12,8 ,21,h ,h ,h ,h ,0 },};
    int size;
    cin >> size;
    MGra G(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            G.arc[i][j] = MGragh[i][j];
        }
    }
    MiniSpanTree_Prim(G);
}