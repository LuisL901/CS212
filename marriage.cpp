#include <iostream>
using namespace std;

bool ok(int q[], int c){

    //Male preference
    int MP[3][3] = {
        {0,2,1},
        {0,2,1},
        {1,2,0}

    };

    //Woman preference
    int WP[3][3] = {
        {2,1,0},
        {0,1,2},
        {2,0,0}
    };

    //Check if woman already with man
    for(int i = 0; i < c; i++){
        if(q[c] == q[i]) return false;
    }

    // c is new man
    // i is current
    for(int i = 0; i < c; i++){
        if( (MP[i][q[i]] > MP[i][q[c]]) && (WP[q[c]][c] > WP[q[c]][i]) ) return false;
        if( (MP[c][q[c]] > MP[c][q[i]]) && (WP[q[i]][i] > WP[q[i]][c]) ) return false;
    }

    return true;

}

int main(){
    int q[3];
    int c = -1;

NC: c++;
    if(c == 3) goto print;

    q[c] = -1;

NR: q[c]++;
    if(q[c] == 3) goto backtrack;

    //Check
    if(!ok(q,c)) goto NR;

    //Set
    goto NC;

backtrack: c--;
    if(c == -1) return 0;
    goto NR;

print: 
    for(int i = 0; i < 3; i++){
        cout<<"Man "<<i<<" gets woman "<<q[i]<<endl;
    }

    return 0;
}