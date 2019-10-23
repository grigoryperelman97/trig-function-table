#include <stdio.h>
#include <math.h>

//constants
const double xMinLowerLim = -1.0;
const double xMinUpperLim = 1.0;

//get the value of xMin from the user
double getXMin(){
	double xMin = 0.0;
	printf("enter xMin, the smallest x used in the table  -1.000 < x <   1.000\n");
	if(scanf("%lf", &xMin) == 1){
		if (xMin < xMinLowerLim || xMin > xMinUpperLim) {
			printf("You entered a value  of xMin that was out of range, Try again\n");
			return getXMin();
		}
		else return xMin;
	}
	else printf("Input not a number. Exiting...\n");
}

int main(){
	double xMin = getXMin();
	return 0;
}