#include <iostream>

using namespace std;

int main()
{
    int n=0;
    for(;;) {
        cout<<"Enter the length of the binary number: ";
        cin>>n;  //cin se fall vi du lieu nhap khong phai kieu int

        if(n>=1&&n<=20){
            for(int i=0;i<(1<<n);i++) {
                for(int j=n-1;j>=0;j--) {
                    cout<<((i&(1<<j))?1:0);
                }
                cout<<endl;
            }
            break;
        }else if(cin.fail()) {
            cout<<"Invalid number!\n";
            cin.clear();
            cin.ignore(21,'\n');
        }else
            cout<<"Invalid number!\n";
    }

    return 0;
}