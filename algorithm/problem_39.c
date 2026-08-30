/*
 * Problem Name: Time Conversion (HackerRank)
 *
 * Problem Description:
 * Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
 *
 * Note:
 * - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
 * - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
 *
 * Example:
 * - Input: s = "07:05:45PM"
 * - Output: "19:05:45"
 *
 * - Input: s = "12:40:22AM"
 * - Output: "00:40:22"
 */

#include <stdio.h>
#include <string.h>

char* timeConversion(char* s) {
    int h, m, sc;
    char c;

    sscanf(s, "%d:%d:%d%c", &h,&m,&sc,&c);

    if(c == 'P' || h == 12) {
        if(c == 'P' && h != 12) {
            h+=12;
        }
    }

    if(c == 'A' && h == 12) {
        h = 0;
    }

    sprintf(s, "%02d:%02d:%02d", h,m,sc);
    return s;
}

int main() {
	char buf[64];
	scanf("%s", buf);

	timeConversion(buf);
	printf("%s\n", buf);
	return 0;
}
