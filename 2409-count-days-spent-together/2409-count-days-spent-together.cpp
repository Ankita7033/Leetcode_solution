#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Days in each month for a non-leap year
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" to the day number of the year (1-365)
    int convertToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        // Sum up days of previous months
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += daysInMonth[i];
        }
        
        return dayCount + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert all date strings to absolute day integers
        int startA = convertToDayOfYear(arriveAlice);
        int endA = convertToDayOfYear(leaveAlice);
        int startB = convertToDayOfYear(arriveBob);
        int endB = convertToDayOfYear(leaveBob);
        
        // The overlap start is the maximum of both arrivals
        int overlapStart = std::max(startA, startB);
        // The overlap end is the minimum of both departures
        int overlapEnd = std::min(endA, endB);
        
        // If they overlap, calculate the inclusive difference, otherwise return 0
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};
