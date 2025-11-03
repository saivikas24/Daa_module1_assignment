#include<iostream>
#include<iomanip>
using namespace std;

class Otpsystem{
private:
  int actual_otp;
public:
  void set_otp(){
    cout<<"Enter a 4 digit OTP(for testing):";
    cin>>actual_otp;
  }

  void hack_otp(){
    int guess;
    int tries=0;
    cout<<"\nstarting brute force attack..\n";

    for(guess=0;guess<9999;++guess){
        ++tries;
        cout<<"Trying otp:"<<setw(4)<<setfill('0')<<guess<<endl;
        if(guess==actual_otp){
            cout<<"\nOtp found succesfully\n"<<"The otp is:"<<setw(4)<<setfill('0')<<guess<<endl;
            cout<<"\nTotal attempts: "<<tries<<endl;
            break; //stops loop when found
        }
    }
  }
};


int main(){
    Otpsystem digi;
    digi.set_otp();
    digi.hack_otp();
    return 0;
}