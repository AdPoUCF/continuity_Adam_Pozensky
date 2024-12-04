//Adam Pozensky
//5684573

#include <stdio.h>

//DeterminMaxItems
//Total Count
//Total Spent
//Current Cost

//Determine Max Items 
int determineMaxItems(int maximumLimit){
    
    int totalCount = 0; 
    int totalSpent = 0; 
    int currentCost = 2; 

    
    //Accounting money. Spent, cost, and limit
    while (totalSpent + currentCost <= maximumLimit){

        int itemCost = currentCost;

        //66% off = 0.34
        if((totalCount + 1) % 3 == 0){
            itemCost *= 0.34;  
        }
        
        //Fail if money is overspent 
        if(totalSpent + itemCost > maximumLimit){
            break; 
        }

        //Add to spent money
        totalSpent += itemCost;
        totalCount++; 

        //Add to current cost
        currentCost++; 
    }
    
    //User output for the affordable items
    printf("I can only afford %d items\n", totalCount);

    return 0;
}

//Output Process Grader

char outputProcessGrade(double calculatedGrade){
    char letterGrade;


    //Letter Grade calculator A 90 B 80 C 70 D 60 if else F
    if(calculatedGrade >= 90.0){
        letterGrade = 'A';

    }else if(calculatedGrade >= 80.0){
        letterGrade = 'B';

    }else if(calculatedGrade >= 70.0){
        letterGrade = 'C';

    }else if(calculatedGrade >= 60.0){
        letterGrade = 'D';
        
    } else {
        letterGrade = 'F';
    }

    //Print grade and letter grade
    printf("Your grade based on %.2f will be %c\n", calculatedGrade, letterGrade);

}


//Average grade calculator

int determineNumericalGrade(){
    
    //Array for grades. Number of grades and grade weight
    int grades[8]; 
    double weightAvg = 0.0; //Base Grade
    double weight[8] = {0.10, 0.10, 0.10, 0.20, 0.20, 0.05, 0.05, 0.20}; 

    //Loop scan for user input of grades
    for(int i = 0; i < 8; i++){
        
        printf("Enter your grade %d: ", i + 1); 
        scanf("%d", &grades[i]);
        
        //Calculating Array grades for weighted average
        weightAvg += grades[i] * weight[i]; 

    }

    //Output Grade
    printf("The weighted average based on the entered values is %.2f\n", weightAvg);

    outputProcessGrade(weightAvg);

    return 0;
}

//Shakespear Email Send

//Send emails
void sendEmails(int daysLeft, int hoursLeft){
    
    //Calculate total hours left 
    int hoursRemaining = (daysLeft * 24) + hoursLeft;

    //If Hours remaining are under 24 print 
    if(hoursRemaining > 24){
        printf("Sent an email with %d hours remaining.\n", hoursRemaining);
        printf("%d will be the calculated hours left before the deadline\n ", hoursRemaining);
    } 
}

//int main

int main(int argc, char **argv){
    int maximumLimit, daysLeft, hoursLeft;

    //Spending min and max input and output
    printf("Enter max limit for spending: \n");
    scanf("%d", &maximumLimit);
    determineMaxItems(maximumLimit);

    determineNumericalGrade();

    //Days and hours left input and output
    printf("Enter the days and hours left: \n");
    scanf("%d %d", &daysLeft, &hoursLeft);
    sendEmails(daysLeft, hoursLeft);
    
    return 0;
}
