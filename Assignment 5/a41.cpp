/* Author:       Narrthanan Seevananthan
   Subject:      ECOR 1606
   Assignment#5, Question #1
   Purpose:      You are given a certain amount of money, and you are tasked with 
                 buying the meal wigh most Vitamin C with that amount.
                    
                    USING SAMPLE CODE FROM ANSWER PROVIDED ON WEBSITE!!!!
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;



// getMaxDollars()
// (1) Requests the user the amount of money they want to spend
// (2) If the values are not valid, has the user
// try again, until a value in the range desired is
// entered
// Returns: the maximum dollars to spend.
//
double getMaxDollars( void ){
	double aTotal;
for (;;) {
    	
    	    cout << "Please enter the total amout of money you wish to spend on Food & Drinks:";
    	    cin >> aTotal ;
    		if ( aTotal < 0) {
    			cout << "Error: amount must be positive" << endl;
    		}
    		else if ( aTotal > 35 ) {
    			cout << "Error: maximum amount you may spend is $35" << endl;
    		}
    		else {
    		    break;
    		}
    	}
		return aTotal;	
}

// fequals() tests if two floating point values are (approximately) equal
//
// Returns: true if ||b - a|| < 0.0001
// false otherwise
bool fequals( double a , double b ){
	double x;
	x = fabs(b - a);
	if (x < 0.0001){
	return true;		
	}else{
		return false;
	}
	
}

// selectFood()
// Selects a food choice, given a maximum amount of money, but
//does not print anything.
// Returns : cost of most expensive food that could be bought for
// the given 'amount'
// Also populates/"returns" the vitamin - C, and calories for the selection
double selectFood( double amount, int &vcFood, int &calFood ){
		//amount is now being used as the cost of the food/ drink selection
		if (amount >= 24) {
            amount =24;
			calFood = 300;
            vcFood  = 148;
        } else if (amount >= 14.99) {
            amount =14.99;
            calFood = 80;
            vcFood  = 30;
        } else if (amount >= 6.75) {
            amount =6.75;
            calFood = 200;
            vcFood  = 9;
        } else if (amount >= 3.50) {
            amount =3.5;
            calFood = 250;
            vcFood  = 6;
        } else if (amount >= 2.50) {
           amount =2.5;
            calFood = 301;
            vcFood  = 12;
        } else if (amount >= 1.00) {
            amount =1.0;
            calFood = 452;
            vcFood  = 2;
        } else if (amount >= 0.35) {
            amount =0.35
            calFood = 436;
            vcFood  = 0;
        } else {
            amount =calFood = vcFood  = 0;
        } // end if
        return amount;
}

// selectDrink()
// Selects a drink choice, given a maximum amount of money, but
//does not print anything.
// Returns: cost of most expensive drink that could be bought for
//the given 'amount'
// Also populates/"returns" the vitamin-C and calories for the
//selected drink
double selectDrink( double amount, int &vcDrink, int &calDrink ){
	 
	 	if (amount >= 8.99) {
	 		amount =8.99;
            calDrink = 101;
            vcDrink  = 236;
        } else if (amount >= 4.99) {
        	amount =4.99;
            calDrink = 112;
            vcDrink  = 207;
        } else if (amount >= 3.50) {
        	amount =3.5;
            calDrink = 203;
            vcDrink  = 50;
        } else if (amount >= 2.50) {
        	amount =2.5;
            calDrink = 250;
            vcDrink  = 149;
        } else if (amount >= 1.75) {
        	amount =1.75;
            calDrink = 2;
            vcDrink  = 7;
        } else if (amount >= 1.25) {
        	amount =1.25;
            calDrink = 0;
            vcDrink  = 0;
        } else if (amount >= 0.95) {
        	amount =0.95;
            calDrink = 0;
            vcDrink  = 0;
        } else if (amount >= 0.25) {
        	amount =0.25;
            calDrink = 160;
            vcDrink  = 0;
        } else {
            amount = calDrink = vcDrink  = 0;
        } // end if selecting the most expensive meal
        return amount;
}

// Prints the name of the drink selected, for a given dollar value.
// This function should use the fequals() function defined above
// The function only prints the food (e.g. "a Strawberry Milkshake")
// so that the same function can be used in a table and elsewhere.
void printDrink( double amount ) {
	if ( fequals( amount, 8.99)) {
		cout << "OJ with Carrots & Spinach";
	} else if ( fequals( amount, 4.99)) {
		cout << "an OJ";
	} else if ( fequals( amount, 3.50)) {
		cout << "an Asparagus Milkshake";
	} else if ( fequals( amount, 2.50)) {
		cout << "a Strawberry Milkshake";
	} else if ( fequals( amount, 1.75)) {
		cout << "a Tea";
	} else if ( fequals( amount, 1.25)) {
		cout << "a Water";
	} else if ( fequals( amount, 0.95)) {
		cout << "a Coffee";
	} else if ( fequals( amount, 0.25)) {
		cout << "a Pop";
	} else {
		cout << "no drink";
	} // end if selecting the most expensive meal
}

// Prints the name of the food selected, for a given dollar value.
// This function uses the fequals() function defined above
// The function should only print the food (e.g. "a Hamburger")
// so that the same function can be used in a table or
// as in an output string.
void printFood( double amount ) {
	if ( fequals( amount, 24.00 ) ) {
	cout << "Steak & Broccoli";
	} else if ( fequals( amount, 14.99)) {
	cout << "a Veggie Platter";
	} else if ( fequals( amount, 6.75)) {
	cout << "a Submarine Sandwich";
	} else if ( fequals( amount, 3.50)) {
	cout << "a Pepperoni Pizza";
	} else if ( fequals( amount, 2.50)) {
	cout << "an all dressed Hamburger";
	} else if ( fequals( amount, 1.00)) {
	cout << "a Doughnut";
	} else if ( fequals( amount, 0.35)) {
	cout << "a Noodle soup";
	} else {
	cout << "no food";
	} // end if
}

int main (void) {

    // Variables
    double aTotal, aDrink, aFood,      // Will hold the amount of money available
           costDrink, costFood,
		   mostExpensiveMeal,
           bestVC,                     // The meal combination with the most vitamin C
           bestComboFood, 
           bestComboDrink;
           
	int calFood,
		calDrink,
		vcFood,
		vcDrink,
		leastCalories,
		greatestVC,
		totalVC = 0,
		cal650Count = 0,
		mealCount = 0,
		iFor,
		iMax,
		count = 0;
		
    // Sentinel loop.  Exit if amount to spend is zero.
    for (;;) {
        	
    aTotal = getMaxDollars();
	
	    if ( aTotal == 0 ) {
	        break;
	    }
		iMax=int(aTotal/0.05 + 0.001);
		
		cout<<"Some options are:"<< endl;
		
    	// Now loop through all the possible values to determine the best meal
    	for ( iFor = 0 ; iFor <= iMax ; iFor++ ) {
    	    
    	    aFood=iFor*0.05;
    	    aDrink = aTotal - aFood;
    	    // Go through the list of possible drinks
    	    // From most expensive to least
	        // Process valid money amounts
	        costDrink = selectDrink(aDrink, vcDrink, calDrink);

	        // Process valid money amounts
	        costFood = selectFood(aFood, vcFood, calFood);
    	    
    	    
    	    if ( aFood == 0 || bestVC < (vcFood + vcDrink) ) {
    	        bestVC = vcFood + vcDrink;
    	        bestComboFood = aFood;
    	        bestComboDrink = aDrink;
    	        count++;
    	        cout<<"Option	Cost	Calories	Vit.C	Description\n";
    	        cout<<"   "<<count<<"   "<<"   "<<costDrink+costFood<<"   "<<calDrink + calFood <<"   "<<bestVC<<"   ";
    	        printFood(aFood);
    	        cout<<" with "
				printDrink(aDrink);
				cout<<endl;
    	    }
    	}
    	     
    	// Now Print the best solution:
    	aFood = bestComboFood;
    	aDrink = bestComboDrink;

        if (aDrink >= 8.99) {
            cout << "We recommend you purchase an OJ with Carrots & Spinach, for $8.99";
        } else if (aDrink >= 4.99) {
            cout << "We recommend you purchase an OJ, for $4.99";
        } else if (aDrink >= 3.50) {
            cout << "We recommend you purchase an Asparagus Milkshake, for $3.50";
        } else if (aDrink >= 2.50) {
            cout << "We recommend you purchase a Strawberry Milkshake, for $2.50";
        } else if (aDrink >= 1.75) {
            cout << "We recommend you purchase a Tea, for $1.75";
        } else if (aDrink >= 1.25) {
            cout << "We recommend you purchase a Water, for $1.25";
        } else if (aDrink >= 0.95) {
            cout << "We recommend you purchase a Coffee, for $0.95";
        } else if (aDrink >= 0.25) {
            cout << "You could purchase a Pop, for $0.25";
        } else {
            cout << "You cannot afford any drink";
        } // end if selecting the most expensive meal
	
	    cout << endl;

        if (aFood >= 24) {
            cout << "We recommend you purchase Steak & Broccoli, for $24.00";
        } else if (aFood >= 14.99) {
            cout << "We recommend you purchase an Veggie Platter, for $14.99";
        } else if (aFood >= 6.75) {
            cout << "We recommend you purchase an Submarine Sandwich, for $6.75";
        } else if (aFood >= 3.50) {
            cout << "We recommend you purchase a Pepperoni Pizza, for $3.50";
        } else if (aFood >= 2.50) {
            cout << "We recommend you purchase an all dressed Hamburger, for $2.50";
        } else if (aFood >= 1.00) {
            cout << "We recommend you purchase a Doughnuts, for $1.00";
        } else if (aFood >= 0.35) {
            cout << "We recommend you purchase a Noodle soup, for $0.35";
        } else {
            cout << "You cannot afford any food";
        } // end if
	  
	    cout << endl;
		// Gather statistics
		if (costFood+costDrink > 0) {
	
		    cout << "This meal would cost $" << costFood+costDrink
					<< ", with " << calFood+calDrink 
					<< " Calories and " << vcFood+vcDrink 
					<< "% of the daily required Vitamin C" << endl;
		    cout << endl;
		    
			mealCount++;
	
			if ( mealCount == 1 || mostExpensiveMeal < (costFood+costDrink) ) {
				mostExpensiveMeal = costFood+costDrink;
			}
			if ( mealCount == 1 || leastCalories > (calFood+calDrink)) {
				leastCalories = calFood+calDrink;
			}
			totalVC += vcFood + vcDrink;
			if ( mealCount == 1 || greatestVC < (vcFood+vcDrink)/(costFood+costDrink) )  {
				greatestVC = (vcFood+vcDrink)/(costFood+costDrink);
			}
			if ( calFood+calDrink > 650) {
				cal650Count++;
			}
			
		}
		
	} // End of sentinal loop.

	if (mealCount > 0) {
		cout <<	"The most expensive meal costs: $" << mostExpensiveMeal 
			  << endl;
		cout << "The meal with the least calories had: " 
			 << leastCalories << " calories"
			  << endl;
		cout << "The average vitamin C per meal was: " << totalVC/mealCount
		      << endl;
		cout << "The most econmical source of 'C' was: " << greatestVC << "%/dollar"
		      << endl;
		cout << 100*cal650Count/mealCount << "% of the meals had more than 650 calories."
			  << endl;
	}

    system("PAUSE"); return 0;

}

