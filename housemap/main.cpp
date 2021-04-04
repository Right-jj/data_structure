//
// Created by 86137 on 2021/4/1.
//
#include<iostream>
#include<time.h>
#include <iomanip>
using namespace std;
const int G_X = 8;
const int G_Y = 8;
const int YES = 1;
const int NO = 0;
int a[0];

int chess_map[G_Y][G_X];
void print(){
    int i , j ;
    for (i = 0 ; i < G_Y; i++){
        for (j = 0 ; j < G_X ; j++){
           printf("%2d\t",chess_map[i][j]);
        }
        cout << endl;
    }
}
// 判断下一步我是否可以走
int Next_Move( int &y, int &x, int way_count ){
    switch ( way_count ) {
        case 0 ://4
            if ( y - 2 >= 0 && x - 1 >= 0 && chess_map[y-2][x-1] == 0){
                y = y-2;
                x = x-1;
                return YES ;
            }
            break;
        case 1 ://5
            if ( y - 2 >= 0 && x + 1  <= G_X - 1  && chess_map[y-2][x+1] == 0){
                y -= 2;
                x += 1;
                return YES ;
            }
            break;
        case 2 ://7
            if ( y - 1 >= 0 && x + 2 <= G_X - 1 && chess_map[y-1][x+2] == 0){
                y = y-1;
                x = x+2;
                return YES ;
            }
            break;
        case 3 ://3
            if ( y + 1 <= G_Y - 1 && x + 2 <= G_X - 1 && chess_map[y+1][x+2] == 0){
                y = y+1;
                x = x+2;
                return YES ;
            }
            break;
        case 4 :// 2
            if ( y + 2 <= G_Y - 1 && x + 1 <= G_X - 1 && chess_map[y+2][x+1] == 0){
                y = y+2;
                x = x+1;
                return YES ;
            }
            break;
        case 5 ://1
            if ( y + 2 <= G_Y - 1 && x - 1 >= 0 && chess_map[y+2][x-1] == 0){
                y = y+2;
                x = x-1;
                return YES ;
            }
            break;
        case 6 :
            if ( y + 1 <= G_Y - 1 && x - 2 >= 0 && chess_map[y+1][x-2] == 0){
                y += 1;
                x -= 2;
                return YES ;
            }
            break;
        case 7 ://6
            if ( y - 1 >= 0 && x - 2 >= 0 && chess_map[y-1][x-2] == 0){
                y = y-1;
                x = x-2;
                return YES ;
            }
            break;
        default:
            break;
    }
    return NO;
}
//dfs travel chess_map

int Travel_Chess(int y, int x,int tag){
    int y1 = y , x1 = x , flag = 0, way_count = 0;

    chess_map[y][x] = tag;

    if ( tag == G_Y * G_X){
        // print chess_map
        print();
        return YES;
    }

    flag = Next_Move( y1 , x1, way_count);

    while( flag == 0 && way_count < 7){
        way_count ++;
        flag =  Next_Move( y1 , x1, way_count);
    }
    // find next move place (y1,x1) ,flag = next_move( 1 or 0 )

    while ( flag ){
        if ( Travel_Chess(y1,x1,tag+1)){
            return YES;
        }
        x1 = x;
        y1 = y;
        way_count ++ ;

        flag = Next_Move( y1 , x1, way_count);
        while( flag == 0 && way_count < 7){
            way_count ++;
            flag =  Next_Move( y1 , x1, way_count);
        }
        // find next move place (y1,x1) ,flag = next_move( 1 or 0 )

    }
    if(flag == 0){
        chess_map[y][x] = 0;
    }
    return 0;
}


int main(){
    clock_t begin ,end;
    begin = clock();
    for (int k = 0; k < G_Y; ++k) {
        for (int l = 0; l < G_X; ++l) {
            chess_map[k][l] = 0;
        }
    }
    if( !Travel_Chess( 2,0,1)){
        cout << "sorry ma mei le"<<endl;
    }
    end = clock();
    cout << "use " << (double)(end - begin)/CLOCKS_PER_SEC << "  s"<<endl;


}
