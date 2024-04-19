
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){

    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
    }

    return true;
}

void print(int q[],int &solution){
    for(int i = 0; i < 8; i++){
        cout<<q[i];
    }
    cout<<endl;
    cout<<solution<<endl;
    for(int row = 1; row < 9; row++){
        for(int col = 0; col < 8; col++){
            if(q[col] == row) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;    
    }
    cout<<endl;
    solution++;
}

int main(){
    int q[8] = {0};
    int c = 0;
    int solution = 1;

    while(c >= 0){
        if(c == 8){
            print(q,solution);
            c--;
        }
        else if(q[c] == 8) {
            q[c] = 0;
            c--;
        }
        else {
            q[c]++;
            if(ok(q,c)) c++;
        }
    }

    return 0;

}