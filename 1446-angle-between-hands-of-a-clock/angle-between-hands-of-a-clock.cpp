class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12)
        hour = 0;
        double hourAngle = 30 * hour + 0.5 * minutes;

        double minuteAngle = 6 * minutes;
        double angle = abs(hourAngle - minuteAngle);
        return min(angle, 360.0 - angle);
    }
};