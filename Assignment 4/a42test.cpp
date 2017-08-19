

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>


using namespace std;

void filterStatus(){
	static int num_bottles = 0;
	string response;
	if(num_botles < 15){
		
		if (num_bottles == 10){
			cout<<"You should change the filter in the fountain within the next 5 uses!"<<endl;
			cout<<"Would you like to change the water filter (Y/y for yes and N/n for no)?"<<endl;
			cin>>response;
			
			if((response=="y") || (rsponse=="Y")){
			num_bottles=0;
			cout<<"Changing filter ... Water filter has been changed!"<<endl;
			}
		}
		
		cout<<"enter Y/y if you want to fill up your bottle:"<<endl;
		cin>> response;
		
		if((response=="y") || (rsponse=="Y")) {
		num_bottles++;
		} else{
			cout<<"You have entered an invalid response please try again!"<<endl;
		}
		
		if(num_bottles==15){
			cout<<"The water fountain should no longer be used! Pleas change the filter."<<endl;
			cout<<"To use the fountain again you must change the filter first!"<<endl;
			cout<<"Would you like to change the filter (Y/y for yes N/n for no)?"
			cin>>response;
			
			if((response=="y") || (rsponse=="Y")){
			num_bottles=0;
			cout<<"Changing filter ... Water filter has been changed! Fountain ready to be used again!"<<endl;
			}
		}
	}else if (num_bottles==15){
			cout<<"You can't proceed without a new filter would you like to change the filter now?"	
			cin>>response;
			
			if((response=="y") || (rsponse=="Y")){
			num_bottles=0;
			cout<<"Changing filter ... Water filter has been changed! Fountain ready to be used again!"<<endl;
			}	
	}
}
int main (void) {


    system("PAUSE"); return 0;
}

