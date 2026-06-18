#include<bits/stdc++.h>
using namespace std;

/*
 Problem: Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
          Answers within 10-5 of the actual value will be accepted as correct.
Solution: Minutes hand:
          A full circle is: 360°, and it completes it in: 60 minutes, So per minute: 360 / 60 = 6°, Therefore: minuteAngle = minutes*6
          Hours hand:
          A full circle is: 360°, and it completes it in: 12 hours, So per hour: 360 / 12 = 30°, But the hour hand doesn't stay fixed between hours.

          For example: 3:30, The hour hand is not at 3, it's halfway between 3 and 4. Since it moves: 30° per hour, it moves: 30 / 60 = 0.5° per minute.

          Therefore: hourAngle = hour * 30 + minutes * 0.5, For 12 o'clock, treat: hour %= 12;
          Find the angle between them: diff = abs(hourAngle - minuteAngle), But there are always two angles between the hands.

          Example: diff = 270°, The smaller angle is: 360 - 270 = 90°, So answer is: min(diff, 360 - diff);
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hoursAngle = hour*30 + minutes*0.5;
        double minutesAngle = minutes*6.0;

        double diff = abs(hoursAngle - minutesAngle);

        return min(diff, 360.0-diff);
    }
};
int main()
{
    int hours, minutes;
    cin>>hours>>minutes;
    Solution s;
    cout<<fixed<<setprecision(5)<<s.angleClock(hours, minutes)<<endl;
}

