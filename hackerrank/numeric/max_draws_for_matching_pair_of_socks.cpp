


/*
Jim is off to a party and is searching for a matching pair of socks. 
His drawer is filled with socks, each pair of a different color. 
In its worst case scenario, how many socks (x) should Jim remove 
from his drawer until he finds a matching pair?

Input Format 
The first line contains the number of test cases T. 
Next T lines contains an integer N which indicates the total pairs of socks present in the drawer.

Output Format 
Print the number of Draws (x) Jim makes in the worst case scenario.

constraints: 
1 <= T <= 1000
0 < N <= 10**6

sample input:
2
1
2
expected output
2
3
Explanation 
Case 1 : A pair of socks are present, 
hence exactly 2 draws for the socks to match. 
Case 2 : 2 pair of socks are present in the drawer. 
The first and the second draw might result in 2 socks of different color. 
The 3rd sock picked will definitely match one of previously picked socks. 
Hence, 3.
4! = 24
3! = 6
2! = 2

24 / (6 + 2) = 3

24/6 = 4
24/8 = 3
x2:
3
1
2
3

6! = 720
5! = 120
720 / (120 + 24) =

best r = 2

6

n! / (n-1)! ((n-1)-1)!

custom input

5
1
2
8
1000
23456
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int best_pick = 2;
const bool debug = false;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    try {
        string input;
        getline(cin, input);
        int count = atoi(input.c_str());
        
        for (int i=0; i < count; ++i) {
            getline(cin, input);
            if (debug) {
                cout << "input " << input << endl;
            }
            int pairs = atoi(input.c_str());
            if (debug) {
                cout << "pairs " << pairs << endl;
            }
            int items = pairs * 2;
            cout << (pairs + 1) << endl;
        }
    }
    catch (exception e) {
        cerr << "exception: " << e.what();
    }
    
    return 0;
}

 