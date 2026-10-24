//? 2409. Count Days Spent Together

// Alice and Bob are traveling to Rome for separate business meetings.

// You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

// Return the total number of days that Alice and Bob are in Rome together.

// You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    // Days in each month for a non-leap year
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" to day of the year (1-365)
    int convertToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        return dayOfYear + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert all date strings to day-of-year integers
        int startA = convertToDayOfYear(arriveAlice);
        int endA = convertToDayOfYear(leaveAlice);
        int startB = convertToDayOfYear(arriveBob);
        int endB = convertToDayOfYear(leaveBob);
        
        // Find the overlap interval [latest arrival, earliest departure]
        int overlapStart = std::max(startA, startB);
        int overlapEnd = std::min(endA, endB);
        
        // Calculate the number of overlapping days
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0; // No overlap
    }
};
