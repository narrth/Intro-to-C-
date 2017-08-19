/* Author:       Narrthanan Seevananthan
   Subject:      ECOR 1606
   Assignment#5, Question #2
   Purpose:      This program allows the user to enter the location of two airports,
                 and a wind direction in degrees true.  The program does the necessary 
                 unit convertions to determine which way an aircraft should take off & fly.
                
				USING SAMPLE CODE FROM ANSWER PROVIDED ON WEBSITE!!!!
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>


using namespace std;

// Function to input thelatitude/Longitude of an airport,and
// validates that the numbers are in range.
// If isDestination is set, the function will prompt the
// user “Please enter lat and long of Destination airport”
// otherwise: “Please enter lat and long of Departure airport”
bool inputPosition( bool isDestination, double &lat, double &lng ){
	for (;;) {
		if (isDestination == true){
			cout << "Please enter lat and long of Destination airport: ";
		}else{
			cout << "Please enter lat and long of Departure airport: ";
		}
		cin >> lat >> lng;
		
		if ( lat < -90 || lat > 90) {
			cout << "latitude must be between -90 and 90 degrees";
		}
		else if (lng < -180 || lng > 180) {
			cout << "longitude must be between  -180 and 180 degrees";
		}
		else {
			break;
		}
		cout << endl << endl;
	}
}

// Calculates the distance between two latitude/longitude positions
// on the earth, using the great circle route calculations
// Inputs:lat/long angles in degrees for the two points
// Returns: distance in kilometers.
double calcDistanceDegrees( double lat1, double lng1, double lat2, double lng2){
	const double EARTH_RADIUS = 6377.707; // in kilometers
	
	double 	distance,
			cosAngularDistance,
			angularDistance,
			deltaLng;
	
	// compute the difference in longitude
	deltaLng = lng1 - lng2;
	// apply the distance formula from Chapter 2
	cosAngularDistance =  ( ( cos (lat1) * cos (lat2) * cos (fabs(deltaLng)) ) 
	     				   +( sin (lat1) * sin (lat2) ) 
						  );
	angularDistance = acos (cosAngularDistance);
	
	return distance = EARTH_RADIUS * angularDistance;
}

// Calculate the initial course between two lat/long positions on
//the earth, using the great circle route calculations
// Inputs: lat/long angles in degrees for the two points
// Returns: course in degrees - true.
double calcCourseDegrees( double lat1, double lng1, double lat2, double lng2){
	const double 	RADS_PER_DEG = M_PI/180.0,
					DEGS_PER_RAD = 1/RADS_PER_DEG;
	double	course,
			deltaLng,
			deltaY,
			deltaX;
			
	// compute the difference in longitude
	deltaLng = lng1 - lng2;
	deltaY = sin(deltaLng)*cos(lat2);
	deltaX = cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(deltaLng);
	course = atan2( deltaY, deltaX );

	if ( course < 0 ) course += 2*M_PI;
	
	// convert back to degrees
	return course *= DEGS_PER_RAD;
}

// Select an airport runway given the current wind direction,
// and a runway direction between 0 and 180 degrees
// Note: For this assignment use rw_dir = 120
// Returns: Runway number between 01 and 36
int selectRunway ( double windDir, int rw_dir){
	double runway1 = 12;
	if (windDir  < ( runway1*10 + 90 ) && windDir  > (runway1*10 - 90)) {
				return runway1;
	} else {
				return 18 + runway1;
	} // end if
}


int main (void) {


    // Constants
    const int 	airspeed = 100,
    			rw_dir = 120;
	
	
	// If calculating in Nautical miles, can use the constants below:
	//const double EARTH_CIRCUMFRENCE = 360 /* degrees */  * 60 /* minutes/deg */;
	//const double EARTH_RADIUS = earthCircumfrence / (2*M_PI) ; // in NM
	const double RADS_PER_DEG = M_PI/180.0,
	             DEGS_PER_RAD = 1/RADS_PER_DEG;

    // Variables
    double  wDir, 
            wVel,
            deltaAngle,
            wca,  // wind correction angle
            gs,   // ground speed
            lat1, lng1, lat2, lng2,
            course,
            distance;
			
	int		runway;
	bool isDestination = false;
	
    // obtain route information
	
	inputPosition(isDestination,lat1,lng1);
	isDestination = false;
	inputPosition(isDestination,lat2,lng2);

    // convert angles to radians
	lat1 *= RADS_PER_DEG;
	lng1 *= RADS_PER_DEG;
	lat2 *= RADS_PER_DEG;
	lng2 *= RADS_PER_DEG;


	
	
	distance= calcDistanceDegrees(lat1,lng1,lat2,lng2);
	course  = calcCourseDegrees(lat1,lng1,lat2,lng2);

	// Set the formatting to 2 decimal places    
    cout << setiosflags (ios::showpoint | ios::fixed)
         << setprecision (2);
    cout << endl;
	cout << "The airports are " << distance << " km apart" 
		 << "In direction: " << course << ". (degrees True)" 
         << endl << endl ;

	// convert to degrees magnetic
	course += 14;
	if (course > 360) {
		course -= 360;
	}

	for (;;) { // sentinal loop
	
		for (;;) { // Valid input check

		    cout << "Please enter wind velocity (in knots), and wind direction (in degrees True):";
		    cout << "    or 0 and 0 to exit ";
		    cin >> wVel >> wDir;
		
			if (wVel < 0) {
				cout << "The wind must be a positive number: " << endl;
			}
			else if (wDir  < 0 || wDir  > 360) {
	            cout << "Sorry: " << wDir << " is not a valid angle.  Angles should be between 0 and 360 degrees." << endl;
			}
			else {
				break;
			}		
		}
			
	    if ( wVel == 0 && wDir==0 ) {
	    	break;
		}
		
		if ( wVel > airspeed*0.40 ) {
			cout << "The wind is too strong.  Best not fly in these conditiosn" << endl;
		} else {
			// Convert the wind direction from True Headings to Magnetic
			wDir += 14;    // Note that the +14 is valid for Ottawa
                                   //      not everywhere on the globe
 			
 			runway = selectRunway ( wDir, rw_dir);
			
		    cout << runway <<" is the preferred runway." << endl;
	
			deltaAngle =  (wDir - course)*RADS_PER_DEG;   // difference in radians
			wca = asin( sin(deltaAngle) * wVel/airspeed );  // in radians
			gs = sqrt( airspeed*airspeed + wVel*wVel - 2*airspeed*wVel*cos( deltaAngle - wca ));

			cout << "The plane needs to fly into the wind by: " << wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "  It's heading would be: " << course + wca*DEGS_PER_RAD << " degrees." << endl;
			cout << "  It's ground speed would be: " << gs << " knots." << endl;
			cout << endl;
		}
	} // end sentinel loopwhile(wVel != 0 && wDir!=0)
	
	
 
    system("PAUSE"); return 0;
}

