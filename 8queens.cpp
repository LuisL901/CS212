#include <iostream>
using namespace std;
int main(){

    int a[8][8] = {0};
    int c;
    int r;
    int num;

    a[0][0] = 1;

    c = 0;
    NC: c++;
    if (c == 8) goto print;

    r = -1;
    NR: r++;
    if(r == 8) goto backtrack;

    //Row Test
    for(int i = 0; i < c; i++){
        if(a[r][i] == 1) goto NR;
    }

    //Up Diagonal Test
    for(int i = 1; (r-i) >= 0 && (c-i) >= 0; i++){
        if(a[r-i][c-i] == 1) goto NR;
    }

    //Down Diagonal Test
    for(int i = 1; (r+i) <= 7 && (c-i) >= 0; i++){
        if(a[r+i][c-i] == 1) goto NR;
    }

    a[r][c] = 1;
    goto NC;

    //backtrack
    backtrack: c--;
    if(c == -1) return 0;
    for(num = 0; num <= 7; num++){
        if(a[num][c] == 1){a[num][c] = 0;
        break;
        }    
    }
    r = num;
    num = 0;
    goto NR;

    //print
    print:
    cout<<endl;
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
     goto backtrack;

    return 0;
}