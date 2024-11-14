#include <iostream>
#include <string>

using namespace std;

int main(){
  string T="0",P1="0",P2="0";
  cout<<"Enter the document: ";
  getline(cin,T);

  do{cout<<"Enter the first pattern (no longer than 1000 characters): ";
    getline(cin,P1);
    cout<<"Enter the alternative pattern (no longer than 1000 characters) : ";
    getline(cin,P2);

    if(P1.length()>1000 || P2.length()>1000)
      cout<<"The pattern is too long. Please try again."<<endl;

  }while(P1.length()>1000 || P2.length()>1000);

  //Search and replace
  for(int index=0;index<T.length();index++) {
    int k=0;
    //search the pattern in the document
    for(int j=0;j<P1.length();j++) {
      if(T[index+j]==P1[j])
        k++;
      else
        break;
      //replace the pattern with the alternative pattern
      if(k==P1.length()) {
        T.replace(index,P1.length(),P2);
      }
    }
  }

  cout<<T<<endl;
  return 0;
}
