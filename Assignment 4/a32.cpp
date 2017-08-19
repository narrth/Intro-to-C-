/* Author:       Narrthanan Seevananthan
   Subject:      ECOR 1606
   Assignment#4, Question #2
   Purpose:     You are given a certain amount of money, and you are tasked with 
                    buying the most expensive drink, and food available 
					with that amount.
	USING SAMPLE SOLUTION #3
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main (void) {

    // Variables
    double 	aDrink, aFood, money,      // Will hold the amount of money available
           	costDrink, costFood,
		   	mostExpensiveMeal,
		   	calFood,
			calDrink,
			vcFood,
			vcDrink,
			vcFinal =0,
			calFinal,
			costDrinkFinal=0,
			costFoodFinal=0,
			leastCalories,
			greatestVC,
			totalVC = 0,
			cal650Count = 0,
			mealCount = 0;
		
	// Initial input
	for (;;) {
		cout << "Please enter how much money you wish to spend on your meal:";
	    cin >> money;
		
		if ((money >= 0) && (money <= 35)) {
		break;
		}
		else{
			cout << "Error:  amount for drinks must be within the correct range." << endl;
		}	
	} 
	
	
	
	for(;;){
	if ((money) == 0){
			break;
		}	
		vcFinal=0;
		// Now loop as long as the sentinal value is not input ( 0, 0 ).
		for ((aFood=0);(aFood<money);(aFood+=0.05)) {
		
		
			aDrink=money-aFood;
				
	    	// Go through the list of possible drinks
	    	// From most expensive to least
	    	
	     	   if (aDrink >= 8.99) {
					costDrink = 8.99;
					calDrink = 101;
	  				vcDrink  = 236;
	 	       } else if (aDrink >= 4.99) {
	 		        costDrink = 4.99;
		            calDrink = 112;
		            vcDrink  = 207;
		        } else if (aDrink >= 3.50) {
		            costDrink = 3.50;
		            calDrink = 203;
		            vcDrink  = 50;
		        } else if (aDrink >= 2.50) {
		            costDrink = 2.50;
		            calDrink = 250;
	  	          	vcDrink  = 149;
	 	       	} else if (aDrink >= 1.75) {
	            	costDrink = 1.75;
	            	calDrink = 2;
	            	vcDrink  = 7;
	        	} else if (aDrink >= 1.25) {
	            	costDrink = 1.25;
	            	calDrink = 0;
	            	vcDrink  = 0;
	        	} else if (aDrink >= 0.95) {
	            	costDrink = 0.95;
	            	calDrink = 0;
	            	vcDrink  = 0;
	        	} else if (aDrink >= 0.25) {
	            	costDrink = 0.25;
	            	calDrink = 160;
	            	vcDrink  = 0;
	        	} else {
	            	costDrink = calDrink = vcDrink  = 0;
	        	} // end if selecting the most expensive meal

	    	    // Process valid money amounts
	    	    if (aFood >= 24) {
	    	        costFood = 24;
					calFood = 300;
	    	        vcFood  = 148;
	    	    } else if (aFood >= 14.99) {
	  				costFood = 14.99;
	  				calFood = 80;
	            	vcFood  = 30;
	        	} else if (aFood >= 6.75) {
	            	costFood = 6.75;
	            	calFood = 200;
	            	vcFood  = 9;
	        	} else if (aFood >= 3.50) {
	            	costFood = 3.50;
	            	calFood = 250;
	            	vcFood  = 6;
	        	} else if (aFood >= 2.50) {
	            	costFood = 2.50;
	            	calFood = 301;
	            	vcFood  = 12;
	        	} else if (aFood >= 1.00) {
	            	costFood = 1;
	            	calFood = 452;
	            	vcFood  = 2;
	        	} else if (aFood >= 0.35) {
	            	costFood = 0.35;
	            	calFood = 436;
	            	vcFood  = 0;
	        	} else {
	            	costFood = calFood = vcFood  = 0;
	        	} // end if
	  
	  		if((vcFood+vcDrink)>vcFinal){
	  		vcFinal = vcFood + vcDrink;
	  		costDrinkFinal = costDrink;
	  		costFoodFinal = costFood;
	  		calFinal = calFood+calDrink;
	  		}
	  		else if (((vcFood + vcDrink) == vcFinal) && (costFood<costFoodFinal)){
	  		costDrinkFinal = aDrink;
	  		costFoodFinal = aFood;
	  		calFinal = calFood+calDrink;
	  		} 
	    
		}
		// End of sentinal loop.	    
	    
	    
	    
	   
	    if (costDrinkFinal >= 8.99) {
         	cout << "We recommend you purchase an OJ with Carrots & Spinach, for $8.99";
	    } else if (costDrinkFinal >= 4.99) {
	    	cout << "We recommend you purchase an OJ, for $4.99";
	    } else if (costDrinkFinal >= 3.50) {
	        cout << "We recommend you purchase an Asparagus Milkshake, for $3.50";
	    } else if (costDrinkFinal >= 2.50) {
	        cout << "We recommend you purchase a Strawberry Milkshake, for $2.50";
	    } else if (costDrinkFinal >= 1.75) {
	        cout << "We recommend you purchase a Tea, for $1.75";
	    } else if (costDrinkFinal >= 1.25) {
	        cout << "We recommend you purchase a Water, for $1.25";
	    } else if (costDrinkFinal >= 0.95) {
	        cout << "We recommend you purchase a Coffee, for $0.95";
	    } else if (costDrinkFinal >= 0.25) {
	        cout << "You could purchase a Pop, for $0.25";
	    } else {
	        cout << "You cannot afford any drink";
	    } // end if outputing the selected drink
	
	    cout << endl;
	    

	    // output optimized selection for food
	    if (costFoodFinal >= 24) {
	       	cout << "We recommend you purchase Steak & Broccoli, for $24.00";
		} else if (costFoodFinal >= 14.99) {
	        cout << "We recommend you purchase an Veggie Platter, for $14.99";
	    } else if (costFoodFinal >= 6.75) {
	        cout << "We recommend you purchase an Submarine Sandwich, for $6.75";
	    } else if (costFoodFinal >= 3.50) {
	        cout << "We recommend you purchase a Pepperoni Pizza, for $3.50";
	    } else if (costFoodFinal >= 2.50) {
	        cout << "We recommend you purchase an all dressed Hamburger, for $2.50";
	    } else if (costFoodFinal >= 1.00) {
	        cout << "We recommend you purchase a Doughnuts, for $1.00";
	    } else if (costFoodFinal >= 0.35) {
	        cout << "We recommend you purchase a Noodle soup, for $0.35";
	    } else {
	        cout << "You cannot afford any food";
	    } // end if
	
	    
	    
	   	cout << endl;
	    cout << "This meal would cost $" << (costFoodFinal+costDrinkFinal)
				<< ", with " << calFinal 
				<< " Calories and " << vcFinal 
				<< "% of the daily required Vitamin C" << endl;
	    cout << endl; 
		    
		// Gather statistics
		if (costFoodFinal+costDrinkFinal > 0) {

			mealCount++;
	
			if ( mealCount == 1 || mostExpensiveMeal < (costFoodFinal+costDrinkFinal) ) {
				mostExpensiveMeal = costFoodFinal+costDrinkFinal;
			}
			if ( mealCount == 1 || leastCalories > (calFinal)) {
				leastCalories = calFinal;
			}
			totalVC += vcFinal;
			if ( mealCount == 1 || greatestVC < (vcFinal)/(costFoodFinal+costDrinkFinal) )  {
				greatestVC = (vcFinal)/(costFoodFinal+costDrinkFinal);
			}
			if ( calFinal > 650) {
				cal650Count++;
			}	
		}  
		
		for (;;) {
		cout << "Please enter how much money you wish to spend on your meal:";
	    cin >> money;
		
			if ((money >= 0) && (money <= 35)) {
			break;
			}
			else{
			cout << "Error:  amount for drinks must be within the correct range." << endl;
			}	
		} 


	}


	if (mealCount > 0) {
		cout <<	"The most expensive meal costs: $" << mostExpensiveMeal 
			  << endl;
		cout << "The meal with the least calories had: " 
			 << leastCalories << " calories"
			  << endl;
		cout << "The average vitamin C per meal was: " << fixed << setprecision(2) << totalVC/mealCount
		      << endl;
		cout << "The most econmical source of 'C' was: " << greatestVC << "%/dollar"
		      << endl;
		cout << fixed << setprecision(2)<< 100*cal650Count/mealCount << "% of the meals had more than 650 calories."
			  << endl;
	}

    system("PAUSE"); return 0;

}

