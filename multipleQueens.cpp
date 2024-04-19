#include <iostream>
#include <cmath>
using namespace std;

bool ok(int * q, int c){
        for(int i = 0; i < c; i++){
                if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
        }
        return true;
}

int queen(int k){
        int count = 0;
        int * q = new int[k];
        int c = 0;

        while(c >= 0){
                if(c == k){
                        count++;
                        c--;
                }
                else if(q[c] == k){
                        q[c] = 0;
                        c--;
                }
                else{
                        q[c]++;
                        if(ok(q,c)) c++;

                }
        }
        delete [] q;
        return count;
}

int main(){
        int solutions;
        int n;

        cout<<"PLease";
        cin>>n;

        for(int i = 1; i <= n; i++){
                solutions = queen(i);
                cout<<"Queen "<<i<<" solution : "<<solutions<<endl;
        }

        return 0;
}