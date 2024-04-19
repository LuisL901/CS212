#include <iostream>
using namespace std;
int main(){

        int q[8];
        int a[8][5] = {{-1},{0,-1},{0,-1},{0,1,2,-1},{0,1,3,-1},{1,4,-1},{2,3,4,-1},{3,4,5,6,-1}};
        int c = -1;
        int r;
        q[0] = 0;

nc:     c++;
        if(c == 8) goto print;
        q[c] = 0;

nr:     q[c]++;  
        if(q[c] > 8) goto backtrack;

        //Check if same number
        for(int i = 0; i < c; i++){
                if(q[i] == q[c]) goto nr;
        }

        //Check if number adjacent are 1 smaller or bigger
        r = 0;
        while(a[c][r] != -1){
            if(abs(q[c] - q[a[c][r]]) == 1) {goto nr;}
            r++;
        }

        //Next Box
        goto nc;

backtrack: c--;  
        if(c == -1) return 0;
        goto nr;

        //Print  
print:  for(int i = 0; i < 8; i++){
                cout<<q[i]<<"   ";
        }
        cout<<endl;
        goto backtrack;

        return 0;
}