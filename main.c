/*
 CSI 333
 Programming Assignment 1
 AK146316
 WED_9_20
 This is a program that will take date input from the user and
 print out the number of days between each date.
 */

#include <stdio.h>

int main(void)
{
    int m1, m2, d1, d2;
    int rd1, rd2, i, days1 = 0, days2 = 0, totDays;
    /*
     * int variables for month and day
     * m1 and m2 are the first and second months entered respectively
     * d1 and d2 are the first and second days entered respectively
     * rd 1 and 2 are for the calculated value of remaining days
     * days 1 and 2 are for the days before date 1 and after date 2
     */
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    /*
     * An array to represent the months of the year where each
     * index value represents the number of days in each month.
     * It is of size 13 to be able to have an index 12.
     * Index 0 will not be used because there is no "0" month.
     */
    
    int monthLength = sizeof(month) / sizeof(month[0]);
    /*
     * This variable is the length of int array month.
     * This is used so I don't have to keep using the
     * array length formula every time I need it.
     */
    
    printf("Date Program\n");
    printf("The first date must precede the second date\n\n");
    printf("Enter First Date:\n"); /* User enters first date here */
    scanf("%d %d", &m1, &d1);
    
    if (m1 > 12 || m1 < 1)
    /*
     * Test to see if the month entered is valid.
     * If not valid, close program.
     */
    {
        printf("\nERROR: INVALID DATE\n");
        printf("PROGRAM CLOSING\n");
        exit(0);
    }
    
    if (d1 > month[m1] || d1 < 1)
    /*
     * Test to see if the day entered is valid.
     * If not valid, close program.
     */
    {
        printf("\nERROR: INVALID DATE\n");
        printf("PROGRAM CLOSING\n");
        exit(0);
    }
    
    printf("\nEnter Second Date:\n"); /* User enters second date here */
    scanf("%d %d", &m2, &d2);
    
    if (m2 > 12 || m2 < 1)
    /*
     * Test to see if the month entered is valid.
     * If not valid, close program.
     */
    {
        printf("\nERROR: INVALID DATE\n");
        printf("PROGRAM CLOSING\n");
        exit(0);
    }
    
    if (d2 > month[m1] || d2 < 1)
    /*
     * Test to see if the day entered is valid.
     * If not valid, close program.
     */
    {
        printf("\nERROR: INVALID DATE\n");
        printf("PROGRAM CLOSING\n");
        exit(0);
    }
    
    if (m1 > m2)
    /*
     * Test to see if the second month precedes
     * the first month. If it does, print error
     * message and close program.
     */
    {
        printf("\nERROR: ");
        printf("SECOND DATE PRECEDES FIRST DATE\n");
        printf("PROGRAM CLOSING\n");
        exit(0);
    }
    
    else if (m1 == m2)
    {
        /*
         * Test to see if month is the same.
         */
        if (d1 > d2)
        /*
         * Test to see if second day precedes first
         * day if both months are equal.
         * If it  does, print error message and
         * close program.
         */
        {
            printf("\nERROR: ");
            printf("SECOND DATE PRECEDES FIRST DATE\n");
            printf("PROGRAM CLOSING\n");
            exit(0);
        }
    }
    
    printf("\nFirst date: %d/%d\n", m1, d1);
    printf("Second date: %d/%d\n", m2, d2);
    
    
    if (m1 == m2)
    /*
     *  Calculate days between dates
     *  Test to see if the months are the same
     *  If they are the same, day 1 can be
     *  subtracted from day 2 to find days
     *  between dates.
     */
    {
        if (d1 == d2)
        /*
         * Test to see if the days are the same day.
         * If they are the same day, subtract day 1
         * from day 2.
         */
        {
            days1 = d2 - d1;
        }
        
        else
        /*
         * For days that are not equal
         * subtract day 1 from day 2 and then
         * subtract 1 from the difference to get
         * the days strictly in between dates.
         */
        {
            days1 = (d2 - d1) - 1;
        }
    }
    
    
    else
    {
        /*
         * This computes the days
         * if the dates are not in
         * the same month.
         */
        rd1 = (month[m1] - d1) - 1; /* Finds remaining days of first month*/
        
        for (i = 1; i <= m1; i++)
        /*
         * Sums dates for 1/1 until
         * the month the user entered
         */
        {
            days1 += month[i];
        }
        
        days1 -= rd1;
        /*
         * Finds difference
         * of the days until the
         * month of the first date
         * and the the remaining days
         * of the first month
         */
        
        
        for (i = m2; i < monthLength; i++)
        /*
         * Sums the dates from the month
         * the user entered and the end
         * of the year
         */
        {
            days2 += month[i];
        }
        /*
         * Calculates remaining dates
         */
        
        days2 -= d2;
        
        totDays = 365 - (days1 + days2);
    }
    
    printf("Number of days between dates: %d", totDays);
}