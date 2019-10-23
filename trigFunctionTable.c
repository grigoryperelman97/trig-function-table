#include <stdio.h>
#include <math.h>

//constants
const double xLowerLim = -1.0;
const double xUpperLim = 1.0;
const int rowsLowerLim = 3;
const int rowsUpperLim = 27;

//get the value of xMin from the user
double getXMin(){
	double xMin = 0.0;
	printf("enter xMin, the smallest x used in the table  -1.000 < x <   1.000\n");
	if(scanf("%lf", &xMin) == 1){
		if (xMin < xLowerLim || xMin > xUpperLim) {
			printf("You entered a value  of xMin that was out of range, Try again\n");
			return getXMin();
		}
		else return xMin;
	}
	else printf("Input not a number. Exiting...\n");
}
//get the value of xMax from the user
double getXMax(){
	double xMax = 0.0;
	printf("enter xMax, the largest x used in the table  -1.000 < x <   1.000\n");
	if(scanf("%lf", &xMax) == 1){
		if (xMax < xLowerLim || xMax > xUpperLim) {
			printf("You entered a value  of xMax that was out of range, Try again\n");
			return getXMax();
		}
		else return xMax;
	}
	else printf("Input not a number. Exiting...\n");
}

int getRows(){
	int rows = 0;
	printf("Enter the number of rows in the table (an integer) ");
	if(scanf("%d", &rows) == 1){
		if (rows < rowsLowerLim || rows > rowsUpperLim) {
			printf("You entered a value  of number of rows that was out of range, Try again\n");
			return getRows();
		}
		else return rows;
	}
	else printf("Input not an integer. Exiting...\n");
}

double xIncrease(double xMin, double xMax, int rows){
	return (xMax - xMin) / (rows - 1);
}

double sin3T(double x){
	return 1 - (pow(x, 2)/2) + (pow(x, 4)/24);
}

double cos3T(double x){
	return x - (pow(x, 3)/6) + (pow(x, 5)/120);
}

void tableGenerator(double xMin, double xMax, int rows){
	double currentX = xMin;
	printf("%9s%10s%13s%10s%13s%10s%13s\n", "X", "sin3T(x)", "error1", "cos3T(x)", "error2", "sin3T(2x)", "error3");
	for (int i = 0; i < rows; i++){
		printf("%9lf%10lf%13lf%10lf%13lf%10lf%13lf\n", currentX, sin3T(currentX), (sin(currentX) - sin3T(currentX)), cos3T(currentX), (cos(currentX) - cos3T(currentX)), sin3T(2 * currentX), (sin(2 * currentX) - sin3T(2 * currentX)));
		currentX += xIncrease(xMin, xMax, rows);
	};
}

int main(){
	//init variables
	double xMin = 0.0;
	double xMax = 0.0;
	int rows = 0;
	//set values for xMin and xMax until they are correct
	do{
		xMin = getXMin();
		xMax = getXMax();
		//print error
		if (xMin > xMax) printf("You entered a minimum limit larger than your maximum!  Try again\n");
	}while (xMin > xMax);
	rows = getRows();
	tableGenerator(xMin, xMax, rows);
	return 0;
}