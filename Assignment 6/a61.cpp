/* Author:      Narrthanan Seevananthan
   Subject:     ECOR 1606
   Assignment   #6, Question #1
   Purpose:     You are given a certain amount of money, and you are tasked with 
                buying the meal with most Vitamin C with that amount. 
				Saving the best options into arrays and displaying them in table format
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;


//  getMaxDollars()
//      (1) Requests the user the amount of money they want to spend
//      (2) If the values are not valid, has the user 
//          try again, until a value in the range desired is 
//          entered
//  Returns:  the maximum dollars to spend.
// 
double getMaxDollars( void ) {
    
    double amount;
    
    // Input amount to spend
    for (;;) {
    
        cout << "Please enter the total amount of money you wish to spend on Food & Drinks:";
        cin >> amount ;
    	if ( amount < 0) {
    		cout << "Error: amount must be positive" << endl;
    	}
    	else if ( amount > 35 ) {
    		cout << "Error: maximum amount you may spend is $35" << endl;
    	}
    	else {
    	    return amount;
    	}
    }
   
}

//  fequals() - tests if two floating point values are (approximately) equal//
//  Returns: true if  ||b-a|| < 0.0001
//           false otherwise
bool fequals( double a , double b ) {
 
    return fabs( b-a ) < 0.0001;
    
}


// selectFood() 
//    Selects a food choice, given a maximum amount of money, but does not print anything.
// Returns:  cost of most expensive food that could be bought for the given 'amount'
//           also populates/"returns" the vitamin-C, and calories for the selected food
double selectFood( double amount, int &vcFood, int &calFood ) 
{
    double costFood = 0;
    
        if (amount >= 24) {
            costFood = 24;
			calFood = 300;
            vcFood  = 148;
        } else if (amount >= 14.99) {
            costFood = 14.99;
            calFood = 80;
            vcFood  = 30;
        } else if (amount >= 6.75) {
            costFood = 6.75;
            calFood = 200;
            vcFood  = 9;
        } else if (amount >= 3.50) {
            costFood = 3.50;
            calFood = 250;
            vcFood  = 6;
        } else if (amount >= 2.50) {
            costFood = 2.50;
            calFood = 301;
            vcFood  = 12;
        } else if (amount >= 1.00) {
            costFood = 1;
            calFood = 452;
            vcFood  = 2;
        } else if (amount >= 0.35) {
            costFood = 0.35;
            calFood = 436;
            vcFood  = 0;
        } else {
            costFood = calFood = vcFood  = 0;
        } // end if
        
	  return costFood;

}

// Prints the name of the food choice selected, for a given dollar value.
// This function uses the fequals() function defined above
//    The function should only print the food (e.g. "a Hamburger")
//    so that the same function can be used in a table as in an output string.
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


// selectDrink() 
//    Selects a drink choice, given a maximum amount of money, but does not print anything.
// Returns:  cost of most expensive drink that could be bought for the given 'amount'
//           also populates/"returns" the vitamin-C, and calories for the selected drink
double selectDrink( double amount, int &vcDrink, int &calDrink ) {

    double costDrink = 0;
        if (amount >= 8.99) {
            costDrink = 8.99;
            calDrink = 101;
            vcDrink  = 236;
        } else if (amount >= 4.99) {
            costDrink = 4.99;
            calDrink = 112;
            vcDrink  = 207;
       } else if (amount >= 3.50) {        
            costDrink = 3.50;
            calDrink = 203;
            vcDrink  = 50;
        } else if (amount >= 2.50) {        
            costDrink = 2.50;
            calDrink = 250;
            vcDrink  = 149;
        } else if (amount >= 1.75) {
            costDrink = 1.75;
            calDrink = 2;
            vcDrink  = 7;
        } else if (amount >= 1.25) {    
            costDrink = 1.25;
            calDrink = 0;
            vcDrink  = 0;
        } else if (amount >= 0.95) {        
            costDrink = 0.95;
            calDrink = 0;
            vcDrink  = 0;
        } else if (amount >= 0.25) {        
            costDrink = 0.25;
            calDrink = 160;
            vcDrink  = 0;
        } else {
            costDrink =  calDrink = vcDrink  = 0;
        } // end if selecting the most expensive meal
        
	return costDrink;

}
 
 
// Prints the name of the drink choice selected, for a given dollar value.
// This function should use the fequals() function defined above
//    The function should only print the food (e.g. "a Strawberry Milkshake")
//    so that the same function can be used in a table as in an output string.
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
//isKnownSolution
//Searches the mealCost[] array for a value of ‘food+drink’, and
//then checks the corresponding drinkCosts[] array for the ‘drink’
//value to see if it also matches.
// n is the number of valid mealthat have been found so far
// and are contained in the arrays.
//
// Returns: true if an array position is equal for both food&drink
// e.g. mealCosts[i] == meal && drinkCosts[i] == drink
// false otherwise
//
bool isKnownSolution( double meal, double drink, double mealCosts[], double drinkCosts[], int n){
	int countl;

	for(countl=0;countl<n;countl++){
		if(fequals(mealCosts[countl],(meal+drink)) && fequals(drinkCosts[countl], drink)){
			return true;
		}
	}

	return false;
}
// swapElements()
// Swaps elements ‘i’ and ‘j’ in a key array, and also in the
//three other corresponding arrays
void swapElements( int i, int j, double key[], double data1[], double data2[], double data3[]){
	double temp;
	
	temp = key[i];
	key[i] = key[j];
	key[j] = temp;
	
	temp = data1[i];
	data1[i] = data1[j];
	data1[j] = temp;
	
	temp = data2[i];
	data2[i] = data2[j];
	data2[j] = temp;
	
	temp = data3[i];
	data3[i] = data3[j];
	data3 [j] = temp;
}

// sortElements()
// Sorts a set of arrays depending on the first "key" array, and
//ensures elements in all the other data
// arrays are swapped to keep in sync with the key by doing the
// same swaps.
void sortElements( int size, double key[], double data1[], double data2[], double data3[] ){
	int i, j;
	bool swapOccured = false;
	for(i=0;i<(size-1);i++){
		swapOccured = false;
		for(j=(0);j<size-1-i;j++){
			if(key[j]<key[j+1]){
			swapElements(j,j+1,key,data1,data2,data3);
			swapOccured = true;
			}
		}
		if(swapOccured == false){
			break;
		}
	}
}

int main (void) {

    // Variables
    double 	aTotal, aDrink, aFood,      // Will hold the amount of money available
           	costDrink, costFood,
		   	mostExpensiveMeal,
		   	greatestVC,
         	bestVC,                     // The meal combination with the most vitamin C
         	bestCal,
          	bestComboFood, 
          	bestComboDrink,
		  	totalCosts [72],
		  	drinkCosts [72],
		   	vcMeals[72],
			calMeals[72];
           
           
	int calFood,
		calDrink,
		vcFood,
		vcDrink,
		leastCalories,
        option,
		totalVC = 0,
		cal650Count = 0,
		mealCount = 0,
		iFor,
		iMax,
		count;
		
	bool check;
    	
	// Set the formatting to 2 decimal places    
    cout << setiosflags (ios::showpoint | ios::fixed)
         << setprecision(2);
         
        
    // Sentinel loop.  Exit if amount to spend is zero.
    for (;;) {
        	
 	    aTotal = getMaxDollars();
	    if ( aTotal == 0 ) {
	        break;
	    }
	   
	    
	    count = 0;
	   
		iMax=int(aTotal/0.05 + 0.001);
    	// Now loop through all the possible values to determine the best meal
    	for ( iFor = 0 ; iFor <= iMax ; iFor++ ) {

    	    aFood=iFor*0.05;
    	    aDrink = aTotal - aFood;
    	    costFood = selectFood( aFood , vcFood , calFood );
    	    costDrink= selectDrink( aDrink, vcDrink, calDrink );
    	    
 			check = isKnownSolution(costFood, costDrink, totalCosts, drinkCosts, count);
			
			if(check == false){
			totalCosts [count] = costFood + costDrink;
			drinkCosts [count] = costDrink;
			vcMeals [count] = vcFood + vcDrink;
			calMeals [count] = calFood + calDrink;
			count++;
			}
    	    
			if ( iFor == 0 || bestVC < (vcFood + vcDrink) ) {
    	        bestVC = vcFood + vcDrink;
    	        bestCal = calFood + calDrink;
    	        bestComboFood = costFood;
    	        bestComboDrink = costDrink;

               
    	    }

    	}

    	     sortElements(count, totalCosts, drinkCosts, vcMeals, calMeals);
 		// Print table of options...    	        
 			for(option=0;option<6;option++){
 				if ( option >= count ) break;
				if (option == 0) {
                    cout << endl << "Some options for closest cost are:" << endl;
        	        cout << "Option  Cost Calories Vit.C  Description" << endl;
        	    }
    	     
			    cout << setw(4) << (option+1)
                     << setw(8) << totalCosts [option] 
                     << setw(6) << int(calMeals[option] + 0.5)
                     << setw(8) << int(vcMeals[option] + 0.5)
                     << "   " ;
                printFood( totalCosts [option] - drinkCosts[option] );
                cout << " and ";
                printDrink( drinkCosts[option] );
                cout << endl;
            }
            
            sortElements(count, calMeals, drinkCosts, vcMeals, totalCosts);
        	for(option=count+1;(count+1-option)<6;option--){
        		if((count+1-option)>count)break;
				if ((count+1-option) == 0) {
                    cout << endl << "Some options for lowest calories are:" << endl;
        	        cout << "Option  Cost Calories Vit.C  Description" << endl;
        	    }
    	     
			    cout << setw(4) << ((count+1-option)+1)
                     << setw(8) << totalCosts [option-2] 
                     << setw(6) << int(calMeals[option-2]+0.5)
                     << setw(8) << int(vcMeals[option-2] +0.5)
                     << "   " ;
                printFood( totalCosts [option-2] - drinkCosts[option-2] );
                cout << " and ";
                printDrink( drinkCosts[option-2] );
                cout << endl;
            }
            
            sortElements(count, vcMeals, drinkCosts, calMeals, totalCosts);
        	for(option=0;option<6;option++){
        			if ( option >= count ) break;
				if (option == 0) {
                    cout << endl << "Some options for highest vitamin C are:" << endl;
        	        cout << "Option  Cost Calories Vit.C  Description" << endl;
        	    }
    	     
			    cout << setw(4) << (option+1)
                     << setw(8) << totalCosts [option] 
                     << setw(6) << int(calMeals[option])
                     << setw(8) << int(vcMeals[option] )
                     << "   " ;
                printFood( totalCosts [option] - drinkCosts[option] );
                cout << " and ";
                printDrink( drinkCosts[option] );
                cout << endl;
            }
        // Gather statistics
		if (bestComboFood+bestComboDrink > 0) {
    	
        	// Now Print the best solution:
        	cout << endl;
        	cout << "We recommend you purchase " ; 
            printDrink( bestComboDrink );
            cout << " for $" << bestComboDrink << " along with ";
            printFood( bestComboFood );
            cout << " for $" << bestComboFood;
            
    	    cout << endl << endl ;

		    cout << "This meal would cost $" << bestComboFood+bestComboDrink
					<< ", with " << bestCal 
					<< " Calories and " << endl 
                    << "                     " << bestVC
					<< "% of the daily required Vitamin C" << endl;
		    cout << endl;
		    
			mealCount++;
	
			if ( mealCount == 1 || mostExpensiveMeal < (bestComboFood+bestComboDrink) ) {
				mostExpensiveMeal = bestComboFood+bestComboDrink;
			}
			if ( mealCount == 1 || leastCalories > (bestCal)) {
				leastCalories = bestCal;
			}
			totalVC += bestVC;
			if ( mealCount == 1 || greatestVC < bestVC/(bestComboFood+bestComboDrink) ) {
				greatestVC = bestVC/(bestComboFood+bestComboDrink);
			}
			if ( bestCal > 650) {
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
		cout << "The average vitamin C per meal was: " << double(totalVC)/mealCount  <<"% "
		      << endl;
		cout << "The most economical source of 'C' was: " << greatestVC << "%/dollar"
		      << endl;
		cout << 100*cal650Count/mealCount << "% of the meals had more than 650 calories."
			  << endl;
	}

    system("PAUSE"); return 0;

}

