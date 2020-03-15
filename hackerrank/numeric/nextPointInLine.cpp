#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
/*
The first line contains an integer T representing the number of testcases 
Each test case is a line containing four space separated integers Px Py Qx Qy representing the (x, y) coordinates of P and Q.

constraints:
    1 <= T <= 15
    
    -100 <= (x, y) <= 100
*/

class Point {
    public:
        int x;
        int y;
        
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
        string ToString() { 
            stringstream ss; 
            ss << x << " " << y; 
            return ss.str();
        }
        void Dump() { cout << this->ToString() << endl; }
};

struct Delta {
    public:
    int dx;
    int dy;
    Delta(Point p, Point q) {
        dx = q.x - p.x;
        dy = q.y - p.y;
    }
};
class Line {
    public:
        Point P;
        Point Q;
        Line(Point p, Point q) : P(p), Q(q) {}
    
    Point NextPoint() {
        Point result; 
        Delta d(P, Q);
        result.x = Q.x + d.dx; 
        result.y = Q.y + d.dy;
        
        return result;
    }
    
};
             
//Given two points P and Q, output the symmetric point of point P about Q.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // get count of input
    try {
    string input;
    getline(cin, input);
    int count = atoi(input.c_str());
        vector<int> coord;
        string tmp;
        for (int i=0; i < count; ++i) {
            getline(cin, input);
            cout << "input: " << input << endl;
            stringstream ss(input);
            while (getline(ss, tmp, ' ')) {
                coord.push_back(atoi(tmp.c_str()));
            }
            if (coord.size() != 4) {
                cerr << "invalid input " << input << endl;
            }
            if ((coord[0] < -100) || (coord[1] < -100) || (coord[2] < -100) || (coord[3] < -100) ) {
                cerr << "input out of range " << endl;
            }
            if ((coord[0] > 100) || (coord[1] > 100) || (coord[2] > 100) || (coord[3] > 100) ) {
                cerr << "input out of range " << endl;
            }
            Point p(coord[0], coord[1]);
            Point q(coord[2], coord[3]);
            if (debug) { 
                cout << "points: " << endl;
                p.Dump();
                q.Dump();
            }
            Line l(p, q);
            Point R = l.NextPoint();
            R.Dump();
            
            coord.clear();
            coord.shrink_to_fit();
        }
    }
    catch (exception e) {
        cerr << "exception: " << e.what();
    }
    return 0;
}
