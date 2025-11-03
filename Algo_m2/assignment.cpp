#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //cost matrix]
    int cost[4][4]{
        {9, 2, 7, 8},  // p1
        {6, 4, 3, 7},  
        {5, 8, 1, 8},  
        {7, 6, 9, 4}     
    };

    int jobs[4]={0,1,2,3};  //.jobbs
    int minCost=999;     
    int best[4];   //to store the best assignment

    do{
        int total=0;
        for(int i=0;i<4;i++){
            total=total+cost[i][jobs[i]]; //assgining the job[i]  to person i
        }

        if(total<minCost){
            minCost=total;
            for(int i=0;i<4;i++){
                best[i]=jobs[i];
            }
        }
    } 
    while(next_permutation(jobs,jobs+4));  //stl function from<algorithm> changes the permutations(start,end)

    cout<<"Minimum Cost="<<minCost<<endl;
    cout<<"Best Assignment: \n";
    for(int i=0;i<4;i++){
        cout<<"person"<<i+1<<"->job"<<best[i]+1<<" Cost="<<cost[i][best[i]]<<best[i]<<endl;
        }
        return 0;

}