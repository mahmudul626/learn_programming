/*
There is a string, s, of lowercase English letters that is repeated infinitely many times.
Given an integer, n, find and print the number of letter 'a's in the first n letters of the infinite string.

Example:
s = 'abcac'
n = 10

The substring we consider is 'abcacabcac', the first 10 characters of the infinite string. 
There are 4 occurrences of 'a' in the substring.

Function Description:
Complete the repeatedString function in the editor below.

repeatedString has the following parameter(s):
- string s: a string to repeat
- int n: the number of characters to consider

Returns:
- int: the frequency of 'a' in the substring
*/

#include <stdio.h>
#include <string.h>

long repeatedString(char* s, long n) {

    long long str_len = strlen(s) ;
    long long a = 0;

    for(int i = 0; i<str_len; i++) {
        if(s[i] == 'a')
            a++;
    }

    long long last = n%str_len;

    long long as = 0;

    for(int i = 0; i<last; i++) {
                if(s[i] == 'a')
                        as++;
        }

    long long round = n/str_len;

    long long result = (round * a) + as;

    return result;
}

int main() {
	char str[64];
	long r;

	scanf("%s", str);
	scanf("%ld", &r);

	long num = repeatedString(str, r);
	printf("%ld\n", num);
	return 0;
}
