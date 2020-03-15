#include <cmath>
#include <cstdio>
#include <iterator>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

class Part {
public:
	string name() {
		return "X";
	}
};

class Operation {
public:
	const string name;

	Operation(string _name) : name(_name) {}

	void operate(Part p) {
		cout << "Operation " << name << " on part " << p.name() << endl;
	}
};
template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val) {
    while (first != last) {
        if (*first == val) {
            return first;
        }
        ++first;
    }
    return last;
}
class StepManager {
public:
    // map operation-name to index in operation-vector
    map<string, int> opMap;
    // map operation-name to prerequisit-name
    map<string, string> opPrerequisiteMap;
    vector<Operation> operationList;

    void dump_operation_map() {
        cout << "opMap ==> " << endl;
        for ( map<string, int>::const_iterator it = opMap.begin();
            it != opMap.end(); ++it
        )
        {
            cout << it->first << ": " << it->second << "\n";
        }
        cout << endl;

        cout << "opPrerequisiteMap ==> " << endl;
        for ( map<string, string>::const_iterator it = opPrerequisiteMap.begin();
            it != opPrerequisiteMap.end(); ++it
        )
        {
            cout << it->first << ": " << it->second << "\n";
        }
        cout << endl;
    }
	void add_operation(Operation operation, vector<string> prerequisites) {
		// Add your implementation here. This method is called
		// once for each type of operation during setup.
		cout << "add_operation: op[" << operation.name << "] count prerequisites [" << prerequisites.size() << "] ";
		if (prerequisites.size() > 0) {
            cout << "prerequisites[0][" << prerequisites[0] << "]";
		}
		cout << endl;
		cout << "opMap[" << operationList.size() << "] <= " << operation.name << endl;
		map<string, int>::iterator omit = opMap.find(operation.name);
		if (omit == opMap.end()) {
            opMap[operation.name] = operationList.size();
            operationList.push_back(operation);
		}
        string preqstr = ((prerequisites.empty()) ? "" : prerequisites[0]);
        opPrerequisiteMap[operation.name] = preqstr;

        do {
            if (prerequisites.empty()) {
                // no prerequisites
                break;
            }
            int distance = (prerequisites.empty() ? 0 : 1);
            vector<string>::iterator start = prerequisites.begin();
            std::advance( start, distance );

            vector<string> remaining(start, prerequisites.end());
            this->add_operation(Operation(prerequisites[0]), remaining);
        } while (false);
        dump_operation_map();
	}

	void perform_operation(string operation_name, Part p) {
		// Add your implementation here. When this method is called,
		// you must call the 'operate()' method for the named operation,
		// as well as all prerequisites for that operation.
        if (opPrerequisiteMap[operation_name] != "") {
            this->perform_operation(opPrerequisiteMap[operation_name], p);
        }
        int index = opMap[operation_name];
        operationList[index].operate(p);
	}
};

int main() {
	StepManager step_mgr;

	string s;
	while (getline(cin, s)) {
		if (s[0] == '#')
			continue;

		stringstream ss(s);
		string name, tmp;
		vector<string> prerequisites;

		getline(ss, name, ',');
		while (getline(ss, tmp, ',')) {
			prerequisites.push_back(tmp);
		}

		step_mgr.add_operation(Operation(name), prerequisites);
	}

	step_mgr.perform_operation("final", Part());
}
