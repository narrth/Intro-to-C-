/* Name: Narrthanan Seevananthan
   Student Number: 100980168
   
   
   ECOR 1606, Assignment 3, Q1 */
// Purpose: Ask the user for the wind directions and determine which way the aircraft should land

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) {
    return value * value;
}

int main (void) {

    // Variables
    double pi = 3.14159;
	double wDir;
	double wVel;
	double tAS;
	double course;
	double WCA;
	double heading;
	double GS;
	tAS =100;
	course = ((pi / 180) * 140);
cout << "Please enter a windspeed(knots) and a wind direction(degrees true) enter 0 0 to stop (# #):";
    cin >> wVel >> wDir;
	while((wVel != 0) || (wDir != 0)){

    

	if((wVel > 40) || (wVel < 0)){
		cout << "The wind speed is too high it is unsafe to fly or it a negative number."<<endl;
	}
    else if (((wDir) < 0) || ((wDir) > 360)) {
        cout << "The wind direction entered is invalid"<<endl;
    } else {
        wDir = (wDir) + 14;

        if (30<(wDir) && (wDir)<210) {
            cout << "Use runway 12 for landing."<<endl;
            wDir = (wDir/180)*pi;
           	WCA=asin(sin(wDir-course)*(wVel/tAS))*(180/pi);
           	cout << "The plane needs to fly into the wind by: "<<WCA<<" degrees."<<endl;
           	
		    heading = (course*180/pi) + WCA;
       		cout <<"Its heading would be: "<<heading<<" degrees."<<endl;
       		
       		GS = sqrt( sqr(tAS) + sqr(wVel) - 2*tAS*wVel*(cos((wDir - course - (WCA/180)*pi)) ));
       		cout<<"Its ground speed would be: "<<GS<<" knots"<<endl;
        } else {
            cout << "Use runway 30 for landing."<<endl;
            wDir = (wDir/180)*pi;
           	WCA=asin(sin(wDir-course)*(wVel/tAS))*(180/pi);
           	cout << "The plane needs to fly into the wind by: "<<WCA<<" degrees."<<endl;
           	
		    heading = (course*180/pi) + WCA;
       		cout <<"Its heading would be: "<<heading<<" degrees."<<endl;
       		
       		GS = sqrt( sqr(tAS) + sqr(wVel) - 2*tAS*wVel*(cos((wDir - course - (WCA/180)*pi)) ));
       		cout<<"Its ground speed would be: "<<GS<<" knots"<<endl;
        } // end if
    } // end if
    
    cout << "Please enter a windspeed(knots) and a wind direction(degrees true) (# #):";
    cin >> wVel >> wDir;
	} // end while
    system("PAUSE"); return 0;

}
