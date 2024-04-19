#include <iostream>
using namespace std;
int main(){

    int size;
    cout<<"Enter size of timestable: ";
    cin>>size;

    while (size <= 0){
        cout<<"Try again: ";
        cin>>size;
    }

    cout<<"   ";
    for (int c = 1; c <= size; c++)
        cout<<" "<<c<<" ";
    cout<<endl;

    cout<<"   ";
    for (int c = 1; c <= size; c++)
        cout<<"---";
    cout<<endl;

    for (int r = 1; r <= size; r++){
        cout<<r<<"* ";
        for(int c = 1; c <= size; c++){
            if (c * r < 10) cout<<" ";
            cout<<c*r<<" ";
        }
        cout<<endl;
    }

    return 0;
}