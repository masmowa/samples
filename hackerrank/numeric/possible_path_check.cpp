#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const bool debug = false;

const size_t MIN_LINES = 1;
const size_t MAX_LINES = 1000;
const size_t MIN_POINT_COORD = 1;
const size_t MAX_POINT_COORD = 10000000000000000000;
struct Delta;

struct Delta {
    public:
        int dx;
        int dy;
        //Delta(const Point& p, const Point& q) {
        //    dx = q.x - p.x;
        //    dy = q.y - p.y;
        //}
        Delta(const int px, const int py, const int qx, const int qy) {
            dx = qx - px;
            dy = qy - py;
        }
        string ToString() const { 
            stringstream ss; 
            ss << dx << " " << dy; 
            return ss.str();
        }
        void Dump() { cout << this->ToString() << endl; }
};


class Point {
    public:
        int x;
        int y;
        
        Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
        Point(const Point& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
        }
        Point& operator=(const Point& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            return *this;
        }
        bool Equal(const Point& val) {
            return ((this->x == val.x) && (this->y == val.y));
        }
        string ToString() const { 
            stringstream ss; 
            ss << x << " " << y; 
            return ss.str();
        }
        void Dump() { cout << this->ToString() << endl; }
        
        Point MoveX(const int du) const {
        if (debug) {
            cout << "MoveX start " << this->ToString() << " du: " << du << endl;
        }
            return Point(this->x+du, this->y);
        }
        Point MoveY(const int du) const {
    if (debug) {
            cout << "MoveY start " << this->ToString() << " du: " << du << endl;
    }
            return Point(this->x, this->x+du);
        }
        bool Xcloser(const Point& dest, const Delta& d) {
            if (debug) {
                cout << "Xcloser start this(" 
                    << this->ToString() 
                    << ") dest(" 
                    << dest.ToString() 
                    << ") d(" 
                    << d.ToString() 
                    << ")" 
                    << endl;
            }
            Delta here(this->x, this->y, dest.x, dest.y);
            if (debug) {
                cout << "Xcloser delta here(" << here.ToString()  <<")" << endl;
            }
            return (here.dx < d.dx);
        }
        bool Ycloser(const Point& dest, const Delta& d) {
            if (debug) {
                cout << "Xcloser start this(" 
                    << this->ToString() 
                    << ") dest(" 
                    << dest.ToString() 
                    << ") d(" 
                    << d.ToString() 
                    << ")" 
                    << endl;
            }
            Delta here(this->x, this->y, dest.x, dest.y);
            if (debug) {
                cout << "Ycloser delta here(" << here.ToString() <<")" << endl;
            }
            return (here.dy < d.dy);
        }
        bool Xequal(const Point& val) const {
            return (this->x == val.x);
        }
        bool Yequal(const Point& val) const {
            return (this->y == val.y);
        }
};

bool MoveNext(const Point& start, const Point& dest, Point& nextpt) {
    Point tmp;
    bool result = false;
    Delta dxdy(start.x, start.y, dest.x, dest.y);
    if (debug) {
        cout << "move from " << start.ToString() << " to " << dest.ToString() << endl;
    }
    do {
        // try move x by y
        if (!start.Xequal(dest)) {
            tmp = start.MoveX(start.y);
    if (debug) {
            tmp.Dump();
    }
            if (tmp.Xcloser(dest, dxdy)) {
                nextpt = tmp;
                (result=true);
                break;
            }
            tmp = start.MoveX(-start.y);
    if (debug) {
            tmp.Dump();
    }
            if (tmp.Xcloser(dest, dxdy)) {
                nextpt = tmp;
                (result=true);
                break;
            }
        }
        else if (!start.Yequal(dest)) {
            tmp = start.MoveY(start.y);
    if (debug) {
            tmp.Dump();
    }
            if (tmp.Ycloser(dest, dxdy)) {
                nextpt = tmp;
                (result=true);
                break;
            }
            tmp = start.MoveY(-start.y);
    if (debug) {
            tmp.Dump();
    }
            if (tmp.Ycloser(dest, dxdy)) {
                nextpt = tmp;
                (result=true);
                break;
            }
        }
        else {
            cerr << "didn't try X or Y" << endl;
        }
    } while (false);

    return result;
}

void ShowSteps(const vector<Point>& steps) {
    
    // print steps
    bool first = true;
    for (int i=0; i<steps.size(); ++i) {
        if (!first) { cout << "->"; }
        first = false;
        cout << steps[i].ToString();
    }
    cout << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    try {
        string input;
        getline(cin, input);
        int count = atoi(input.c_str());

        if (MIN_LINES > count || MAX_LINES < count) {
            cerr << "count of lines out of range " << count << endl;
        }
        vector<int> coord;
        string tmp;
        
        for (int i=0; i < count; ++i) {
            getline(cin, input);
            if (debug) {
                cout << "input " << input << endl;
            }

            stringstream ss(input);
            while (getline(ss, tmp, ' ')) {
                coord.push_back(atoi(tmp.c_str()));
            }
            if (coord.size() != 4) {
                cerr << "invalid input " << input << endl;
            }
            if ((coord[0] < MIN_POINT_COORD) || 
                (coord[1] < MIN_POINT_COORD) || 
                (coord[2] < MIN_POINT_COORD) || 
                (coord[3] < MIN_POINT_COORD) ) {
                cerr << "input out of range " << "value < " << MIN_POINT_COORD << endl;
            }
            if ((coord[0] > MAX_POINT_COORD) || 
                (coord[1] > MAX_POINT_COORD) || 
                (coord[2] > MAX_POINT_COORD) || 
                (coord[3] > MAX_POINT_COORD) ) {
                cerr << "input out of range " << "value > " << MAX_POINT_COORD << endl;
            }
            vector<Point> steps;
            
            Point ab(coord[0], coord[1]);
            steps.push_back(ab);
            Point xy(coord[2], coord[3]);
            if (debug) { 
                cout << "points: " << endl;
                ab.Dump();
                xy.Dump();
            }
            bool done = false;
            Point stepStart = ab;
            Delta dxdy(stepStart.x, stepStart.y, xy.x, xy.y);
            int steplimit = dxdy.dx + dxdy.dy + 1;
            
            for (int i=0; i < steplimit && !done; ++i) {
                Point ptNext;
                bool isnear = MoveNext(stepStart, xy, ptNext);
                if (isnear) {
                    steps.push_back(ptNext);
                }
                stepStart = ptNext;
                if (xy.Equal(ptNext)) {
                    if (debug) {
                        ShowSteps(steps);
                    }
                    done = true;
                }
            }
            string YN( (done ? "YES" : "NO") );
            cout << YN << endl;

            coord.clear();
            coord.shrink_to_fit();
        }
    }
    catch (exception e) {
        cerr << "exception: " << e.what();
    }
    
    return 0;
}
