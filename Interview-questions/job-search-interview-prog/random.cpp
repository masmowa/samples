// count random7
// Write a function that that uses a standard random number generator 
// to compute 100,000 random numbers between 1 and 500,000 and 
// returns the total number of unique random numbers found
#include <iostream>
#include <cstdlib>
#include <time>
#include <map>
#include <list>

using namespace std;

const int MY_MIN = 1;
const int MY_MAX = 500000;
const int NUM_ITERATIONS = 100000;


// return a random number between max and min including max and min
int bounded_random(int min, int max)
{
    return (rand() % max + min);
}

int count_unique_rand(int iterations)
{
	std::map<int, int> unique_vals;
	for (int i=0; i < iterations; ++i)
	{
		rand_val = bounded_random(MY_MIN, MY_MAX);
			
		if (unique_vals.find(rand_val) == unique_vals.end())
		{
			unique_vals[rand_val] = 1;
		}
		else
		{
			unique_vals[rand_val] += 1;
		}
	}
	
	cout << "number of unique values " << unique_vals.size() << endl;
	return unique_vals.size();
}

//  Write a function similar to the first but returns the top repeated value (or values if there’s a tie).
int find_most_repeated_rand(int iterations, list<int> &most_repeated)
{
	std::map<int, int> unique_vals;
	typedef map<int, int>::iterator int_int_map_it;
	
	// populate the map and count occurence
	for (int i=0; i < iterations; ++i)
	{
		rand_val =  bounded_random(MY_MIN, MY_MAX);
		
		// count the times we see this value
		if (unique_vals.find(rand_val) == unique_vals.end())
		{
			unique_vals[rand_val] = 1;
		}
		else
		{
			unique_vals[rand_val] += 1;
		}
	}
	
	int max_val = 0;
	
    // find the largest count in the map
	for (int_int_map_it iter = unique_vals.begin(); unique_vals.end() != iter; ++iter)
	{
		max_val = (max_val < iter->second) ? iter->second : max_val;
	}
    
    //TODO: there must be a way to optimize this to do fewer passes on the map;
    // now walk the list again and add the values that match the max count to the list also
	for (int_int_map_it iter = unique_vals.begin(); unique_vals.end() != iter; ++iter)
	{
        if (max_val == iter->second)
        {
            most_repeated.push_back(iter->first);
        }
	}
    
	cout << "number of unique values " << unique_vals.size() << endl;
	return most_repeated.size();
}

void main(int argc, char *argv[])
{
    // initialize random number generator
    srand(static_cast<unsigned int>(time(NULL)));
	int unique_count = 0;
    int count_most_repeated = 0;
    
	unique_count = count_unique_rand(NUM_ITERATIONS);
    std::list<int> most_repeated;
    
    count_most_repeated = find_most_repeated_rand(NUM_ITERATIONS, most_repeated);
    cout << "found " << count_most_repeated << "items repeated " << endl;
    
    for (std::list<int>::iterator list_it = most_repeated.begin(); list_it != most_repeated.end(); ++list_it)
    {
        cout << *list_it << endl;
    }
}