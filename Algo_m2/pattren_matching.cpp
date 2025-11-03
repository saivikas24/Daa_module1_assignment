//writing the pattren matching algorith by using the Brute force algorithm 
#include<iostream>
using namespace std;

class PattrenMatch{
    string text;
    string pattren;
    public:
    //constructor to initialize the text and pattren
      PattrenMatch(string text, string pattren){
                this->text=text;
                this->pattren=pattren;
      }

      void bruteForce(){  //Function to perform the pattren matching
        int n=text.length();
        int m=pattren.length();
        int i, j;

        cout<<"Text: "<<text<<endl;
        cout<<"Pattren: "<<pattren<<endl;

        for(i=0;i<=n-m;i++){  //here the m-n means the last valid position to fit the pattren into the text(loop through each position in index)
            for(j=0;j<m;j++){   //compare pattren with text from index i 
                 if(text[i+j]!=pattren[j]){     //This means the Text[outer_loop i+pattren start j=0] 
                    break; 
                 }
            }
        
        //if all charecters matched
        if(j==m){
            cout<<"Pattren found at index: "<<i<<endl;
        }
      }
    }
};

int main(){
    string text;
    string pattren;
    cout<<"Enter text: ";
    cin>>text;

    cout<<"Enter pattren: ";
    cin>>pattren;

    PattrenMatch p1(text,pattren);
    p1.bruteForce();
    return 0;
}