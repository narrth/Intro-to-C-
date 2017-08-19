/* Author:       Narrthanan Seevananthan
   Subject:      ECOR 1606
   Assignment#4, Question #2
   Purpose:      This program allows the user to enter a langitude and longitude pf two airpots
   				 and calculate angular distance and distiance between the two airports
				 I also lets you enter the wind direction in degrees true, 
                 converts the value to a ‘compass wind direction’ to determine which way 
                 an aircraft should fly, and then land.
                 
                 USED SAMPLE ANSWERS from assignment 2 and 3
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;


int main (void) {

    // Variables
    double  EARTH_RADIUS = 6377.707,
			wDir,
			RADS_PER_DEG = M_PI/180.0,
    		deltaLng,
			lat1,
			lng1, 
			deltaY,
			lat2,
			lng2,
			deltaX,
			courseDeg,
			cosAngularDistance,
			angularDistance,
			distance,
            wVel,
            deltaAngle,
            mod,
            course, 
			airspeed = 100,
            wca,  // wind correction angle
            gs;   // ground speed
        
	int runway1 = 12;   // Runway option    
    
	// obtain input information  
	// lat and long are in degrees 
	cout << "Please enter lat and long of 1st airport: "; 
	cin >> lat1 >> lng1; 
	cout << "Please enter lat and long of 2nd airport: "; 
	cin >> lat2 >> lng2; 
	
	
	lat1 = lat1 * RADS_PER_DEG; 
	lng1 = lng1 * RADS_PER_DEG; 
	lat2 = lat2 * RADS_PER_DEG;  
	lng2 = lng2 * RADS_PER_DEG;  
	
	// compute the difference in longitude 
	deltaLng = lng1 - lng2; 
	deltaY = sin(deltaLng)*cos(lat2); 
	deltaX = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltaLng); 
	course = atan2( deltaY, deltaX ); 
	
	
	if ( course < 0 ) {
		course += 2*M_PI;
		} // add 360deg, or 2*3.1415... 
	// apply the distance formula from Chapter 2 
	cosAngularDistance = ( ( cos(lat1) * cos(lat2) * cos(fabs(deltaLng)))+( sin(lat1) * sin(lat2)));
	angularDistance = acos (cosAngularDistance); 
	distance = EARTH_RADIUS* angularDistance;  
	cout << "The points are " << distance << " km apart"       << "In direction: " << course/ RADS_PER_DEG << "."<< endl;   
	
	

    
	cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
    cout << "    or 0 and 0 to exit ";
    cin >> wVel >> wDir;

              
		for (;;){
			if (wVel < 0) {
				cout << "The wind must be a positive number: " << endl;
			}
			if (wDir  < 0 || wDir  > 360) {
     	       cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
			}
			cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
    		cout << "    or 0 and 0 to exit ";
    		cin >> wVel >> wDir;
    		if ((wVel>0) && (wDir>0 && wDir<360)){
    			break;
    		}

		}

    	for (;;) {
			if( wVel == 0 && wDir==0){
				break;
			}
			if ( wVel > airspeed*0.40 ) {
				cout << "The wind is too strong.  Best not fly in these conditiosn" << endl;
			} else {
				// Convert the wind direction from True Headings to Magnetic
				wDir  = wDir  + 14;    // Note that the +14 is valid for Ottawa
                courseDeg= ((course*180)/M_PI) +14;                  //      not everywhere on the globe
 
				if (wDir  < ( runway1*10 + 90 ) && wDir  > (runway1*10 - 90)) {
					cout << runway1;
				} else {
					cout << 18 + runway1;
				} // end if
				cout << " is the preferred runway." << endl;
	
			
				deltaAngle =  (((wDir-courseDeg) * M_PI)/180);   // difference in radians
				wca = asin( sin(deltaAngle) * wVel/airspeed );  // in radians
				gs = sqrt( airspeed*airspeed + wVel*wVel - 2*airspeed*wVel*cos( deltaAngle - wca ));

				cout << "The plane needs to fly into the wind by: " << wca*180/M_PI << "degrees." << endl;
				cout << "  It's heading would be: " << courseDeg + wca*180/M_PI << " degrees." << endl;
				cout << "  It's ground speed would be: " << gs << " knots." << endl;
			}

     	   // Ask user for the next set of inputs
	 	    cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
		    cout << "    or 0 and 0 to exit ";
		    cin >> wVel >> wDir;

			for (;;){
				if (wVel < 0) {
					cout << "The wind must be a positive number: " << endl;
				}
				if (wDir  < 0 || wDir  > 360) {
     	  	     cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
				}
				cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
    			cout << "    or 0 and 0 to exit ";
    			cin >> wVel >> wDir;
    			if ((wVel>0) && (wDir>0 && wDir<360)){
    				break;
    			}

			}
		} // end sentinel loop for

    system("PAUSE"); return 0;
}

