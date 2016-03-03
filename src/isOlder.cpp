/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int length(char*);
int month_validation(int);
int day_validation(int, int, int);
int year_validation(int);
int isOlder(char *dob1, char *dob2) {
		int i, x, index = 0, y, q = 0, yv1, yv2, mv1, mv2, dv1, dv2;
		int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
		x = length(dob1);
		y = length(dob2);
		if (x != y){
			return -1;
		}
		else{
			for (i = 0; dob1[i] - '0' != -3; i++){
				if (dob1[i] - '0' >= 0 && dob1[i] - '0' <= 9){
					d1 = d1 * 10 + (dob1[i] - '0');
					d2 = d2 * 10 + (dob2[i] - '0');
				}
				else{
					return -1;
				}
			}
			for (i++; dob1[i] - '0' >= 0 && dob1[i] - '0' <= 9; i++){
				if (dob1[i] - '0' >= 0 && dob1[i] - '0' <= 9){
					m1 = m1 * 10 + (dob1[i] - '0');
					m2 = m2 * 10 + (dob2[i] - '0');
				}
				else{
					return -1;
				}
			}
			for (i++; i<x; i++){
				if (dob1[i] - '0' >= 0 && dob1[i] - '0' <= 9){
					y1 = y1 * 10 + (dob1[i] - '0');
					y2 = y2 * 10 + (dob2[i] - '0');
				}
				else{
					return -1;
				}
			}
			yv1 = year_validation(y1);
			yv2 = year_validation(y2);
			mv1 = month_validation(m1);
			mv2 = month_validation(m2);
			if (mv1 == 1){
				dv1 = day_validation(d1, m1, yv1);
				dv2 = day_validation(d2, m2, yv2);
				if (dv1 == 1 && dv2 == 1){
					if (y1 > y2){
						return 2;
					}
					else if (y2 > y1 ){
						return 1;
					}
					else if (y1 == y2 ){
						if (m1 > m2)
							return 2;
						else if (m2 > m1 )
							return 1;
						else if (m1==m2){
							if (d1 >d2 )
								return 2;
							else if (d2 >d1)
								return 1;
							else if (d1 == d2)
								return 0;
						}

					}
				}
				else
					return -1;
			}
			else{
				return -1;
			}
			return 0;
		}
	}
	int length(char *dob){
		int i, count = 0;
		for (i = 0; dob[i] != '\0'; i++){
			count++;
		}
		return count;
	}
	int year_validation(int year){
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
			return 1;
		}
		else
			return 0;
	}
	int month_validation(int month){
		if (month >= 1 && month <= 12){
			return 1;
		}
		else
			return 0;

	}
	int day_validation(int day, int month, int ytype){
		if ((month == 01) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if (month == 2){
			if ((ytype == 1) && (day >= 1 && day <= 29))
				return 1;
			else if ((ytype == 0) && (day >= 1 && day <= 28))
				return 1;
		}
		else if ((month == 3) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if ((month == 4) && (day >= 1 && day <= 30)){
			return 1;
		}
		else if ((month == 5) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if ((month == 6) && (day >= 1 && day <= 30)){
			return 1;
		}
		else if ((month == 7) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if ((month == 8) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if ((month == 9) && (day >= 1 && day <= 30)){
			return 1;
		}
		else if ((month == 10) && (day >= 1 && day <= 31)){
			return 1;
		}
		else if ((month == 11) && (day >= 1 && day <= 30)){
			return 1;
		}
		else if ((month == 12) && (day >= 1 && day <= 31)){
			return 1;
		}
		return 0;
}
