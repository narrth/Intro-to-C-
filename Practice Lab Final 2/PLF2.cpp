/* Author:       Narrthanan Seevananthan
   Subject:      ECOR 1606
   Practice Lab final 2
   Purpose:      
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>


using namespace std;

double computeSolidity(double b1, double b2){
	double o, solidity, LHS, lowest;
	
	cout<<fixed<<showpoint;
	cout<<"  Soliditary      LHS Value"<<endl;
	cout<<"------------------------------------"<<endl;
	
	for(o=0.6;o<2.2;o+=0.1){
		LHS = 33.5291+(0.469188+0.002096*b2)*b2-b1+(0.187148*b2-15.2599)*(log(1/o)) - 0.677212*(pow(log(1/o),2));
		if(o==0.6){
			lowest=LHS;
			solidity = o;
		}else if(fabs(LHS)<fabs(lowest)){
			lowest = LHS;
			solidity=o;
		}
		
		cout<<setprecision(1)<<"     "<<o<<"          ";
		
		cout<<setprecision(4)<<LHS<<endl;
	}
	
	cout<<setprecision(1)<<"Leaving function. The chosen value is "<<solidity<<endl;
	return solidity;
}

double computeBladeExitAngle (double a1, double b2, double o){
	double a2;
	a2=(b2-(a1*(0.23+(b2/500))*(pow((1/o), 0.5))))/(1-(0.23+(b2/500))*(pow((1/o), 0.5)));
	return a2;	
}

bool testval(double b1, double b2, double i){
	double check;
	if(b1==-1 && b2==-1 && i==-1){
		return true;
	}
	check = (36- 0.45*b2)/(b1-b2);
	if (0.75<check && check<1.25){
		if(b2>-10 && b2<50){
			if(i>(-3) && i<3){
				return true;
			}
		}
	}
}

int main (void) {
	double o, a2, a1, b1, b2, i;
	bool checkval;
	for(;;){
	checkval=false;
		for(;;){
			cout<<"Enter flow entry angle, flow exit angle, and incidence: "<<endl;
			cin>>b1>>b2>>i;	
			
			checkval=testval(b1,b2,i);
			
			if(checkval==true){
				break;
			}else{
				cout<<"Invalid values ignored."<<endl;
			}
		}
	
		if(b1==-1 && b2==-1 && i==-1){
			break;
		}
	a1=b1-i;
	
	o=computeSolidity(b1,b2);
	a2=computeBladeExitAngle(a1,b2,o);
	cout<<endl;
	cout<<setprecision(1)<<"Blade entry angle: "<<a1<<endl;
	cout<<"Solidity: "<<o<<endl;
	cout<<"Blade exit angle: "<<a2<<endl;	
	}

    system("PAUSE"); return 0;
}

