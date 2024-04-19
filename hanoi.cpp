#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a[3];
    int n, move, from, to, candidate = 0;

    cout<<"Enter positive number of rings to sort: ";
    cin>>n;

    //Code to set all Towers
    for(int i = n+1; i > 0; i--){
        a[0].push_back(i);
    }

    //n+1 is used as a base for comparison
    a[1].push_back(n+1);
    a[2].push_back(n+1);


    //Set all towers and candidate
    from = 0;

    if(n % 2 != 0){ 
        to = 1;
    }
    else {
        to = 2;
    }
    candidate = 1;

    //While tower B has  less than the n amount of rings plus the base
    while (a[1].size() < n+1) {
        cout<<"Move number "<<++move<<" : Transfer ring "<<candidate<<" from tower "<<char(from + 65)<<" to tower "<<char(to + 65)<<endl;

        //Transfer Ring
        a[to].push_back(a[from].back());
        a[from].pop_back();

        //Change "from"
        if(n % 2 != 0){ //ODD
            if(a[(to + 1) % 3].back() < a[(to + 2) % 3].back()){
                from = (to + 1) % 3;
            }
            else{
            from = (to + 2) % 3;
            }    
        }
        else { //EVEM
            if(a[(to + 2) % 3].back() < a[(to + 1) % 3].back()){
                from = (to + 2) % 3;
            }
            else{
                from = (to + 1) % 3;
            }

        }

        //Change "to"
        if(n % 2 != 0){ //ODD
            if (a[(from + 1) % 3].back() < a[from].back()) {
                to = (from + 2) % 3;
            }
            else {
                to = (from + 1) % 3;
            }
        }
        else { //EVEN
            if (a[(from + 2) % 3].back() < a[from].back()) {
                to = (from + 1) % 3;
            }
            else {
                to = (from + 2) % 3;
            }
        }

 

        //Next Candidate
        candidate = a[from].back();

        cout<<from<<"   "<<to<<"   "<<candidate<<endl;

    }

    return 0;
}