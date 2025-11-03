#include<iostream>
using namespace std;


class CombinationGenerator{
public:
       //Function to start process
       void generate(int arr[],int n,int r){
           int data[r];  //temporary array to store the current combination
            combine(arr,data,0,n-1,0,r);
       }
private:
   //Recursive Function to generate combinations
   void combine(int arr[],int data[],int start,int end, int index, int r){
    //Base case: If we have selected 'r elements
    if(index==r){
        for(int j=0;j<r;j++)
           cout<<data[j]<<" ";
         cout<<endl;
         return;
    }
    //Loop through remaining elements
    for(int i=start;i<=end&&end-i+1>=r-index;i++){
        data[index]=arr[i];   //step1:choose current element
        combine(arr,data,i+1,end,index+1,r);  //step2: Move to next position
    }
   }
};

int main(){
    CombinationGenerator cg;
    int arr[]={1,2,3,4};
    int n=4;
    int r=2;

    cg.generate(arr,n,r);
    return 0;
}