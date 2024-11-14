#include <iostream>

using namespace std;


int main() {
    int result = 0;
    int n = 0;

    Start:
    cout<<"Enter a number (1<=n<=9999): ";
    cin>>n;

    if(1<=n&&n<=9999) {
        for(int i=1;i<=9999/n;i++) {
            result = n*i;
            cout<<result<<" ";
        }
    }else if(cin.fail()) {
        cout<<"Invalid number!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        goto Start;
    }else{
        cout<<"Invalid number!"<<endl;
        goto Start;
    }

    return 0;
}