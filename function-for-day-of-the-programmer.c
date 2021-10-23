char* dayOfProgrammer(int year) {
    
    int n = year;
    char yearStr[5];
    yearStr[4] = '\0';
    yearStr[3] = n % 10 + '0';
    n /= 10;
    yearStr[2] = n % 10 + '0';
    n /= 10;
    yearStr[1] = n % 10 + '0';
    n /= 10;
    yearStr[0] = n % 10 + '0';

    n = year;
    static char dateStr[40] = {'1', '2', '.', '0', '9', '.', '\0'};
    if (  ((n > 1918) && (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))) || (n <= 1917 && n % 4 == 0)) {

        strcat(dateStr, yearStr);
        return dateStr;
    }
    if (n == 1918) {
        dateStr[0] = '2';
        dateStr[1] = '6';
        strcat(dateStr, yearStr);
        return dateStr;
    }
    else {
        dateStr[1] = '3';
        strcat(dateStr, yearStr);
        return dateStr;
    }
}
