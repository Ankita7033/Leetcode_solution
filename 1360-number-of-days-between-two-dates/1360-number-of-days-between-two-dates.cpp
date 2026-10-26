class Solution {
public:
    bool isleap(int year) {
        return (year%4 == 0 && year%100 != 0) || year%400 == 0;
    }
    int todays(string date) {
        int day = stoi(date.substr(8 , 2));
        int month = stoi(date.substr(5 , 2));
        int year = stoi(date.substr(0 , 4));
        int monthinyr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total = 0;
        for(int y = 1971; y < year; y++) {
            if(isleap(y)) total += 366;
            else total += 365;
        }
        for(int m = 0; m < month-1; m++) {
            total += monthinyr[m];
            if(m == 1 && isleap(year)) {
                total ++;
            }
        }
        total += day;
        return total;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(todays(date1) - todays(date2));
    }
};