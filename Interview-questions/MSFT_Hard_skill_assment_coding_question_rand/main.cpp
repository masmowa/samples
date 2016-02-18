#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <list>
#include <random>

using namespace std;

const int MY_MIN = 1;
const int MY_MAX = 500000;
const int NUM_ITERATIONS = 100000;
const int COLLECTION_COUNT = 100000;


// count random7
// Write a function that that uses a standard random number generator
// to compute 100,000 random numbers between 1 and 500,000 and
// returns the total number of unique random numbers found
class RandomCollection {

    map<int, int> rand_collection;
    size_t collection_size;
    int range_min;
    int range_max;

public:
    RandomCollection(size_t csize, int cmin, int cmax)
        : collection_size(csize)
        , range_min(cmin)
        , range_max(cmax)
    {
        // generate collection with frequency count
        // the map will contain key=random_number, value = count of times value occured
        // the collection size designates the requested size of the collection
        // there will also be a count of iterations required to generate a list with collection_size values
        FillCollection();
    }
    size_t count_unique_random_values() {
        size_t ct_unique = 0;
        for (auto const &rc_it : rand_collection) {
            if (rc_it.second == 1) {
                ++ct_unique;
            }

        }
        return ct_unique;
    }
    list<int> find_numbers_repeated_most_often() {
        list<int> list_max_repeated;

        size_t high_value = rand_collection.begin()->second;

        // find the highest count of all items in the map
        for (auto const &rcent : rand_collection) {
            if (rcent.second > static_cast<int>(high_value)) {
                high_value = rcent.second;
            }
        }

        for (auto const &rcent : rand_collection) {
            if (rcent.second == static_cast<int>(high_value)) {
                list_max_repeated.push_back(rcent.first);
            }
        }


        return list_max_repeated;
    }
protected:
    int FillCollection()
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(range_min, range_max);
        size_t cycles = 0;
        cout << "generating collection of " << collection_size << " random numbers" << endl;
        while(rand_collection.size() < collection_size) {
            int number =distribution(generator);

            if (rand_collection.find(number) == rand_collection.end()) {
                rand_collection[number] = 1;
            }
            else {
                rand_collection[number] += 1;
            }
            ++cycles;
        }
        cout << "size of random collection = " << rand_collection.size() << endl;
        cout << "cycles required to generate " << rand_collection.size() << " values = " << cycles << endl;
        return rand_collection.size();
    }

};

int main()
{
    cout << "Generate colection of random numbers now!" << endl;
    RandomCollection rc = RandomCollection(COLLECTION_COUNT, MY_MIN, MY_MAX);
    size_t unique_rand = rc.count_unique_random_values();
    cout << "number of unique random numbers " << unique_rand << endl;

    list<int> max_repetions;

    max_repetions = rc.find_numbers_repeated_most_often();
    list<int>::iterator list_it;
    cout << "most repeated values :" << endl;
    for (list_it = max_repetions.begin(); list_it != max_repetions.end(); ++list_it) {
        cout << *list_it << " ";
    }
    cout << endl;
    return 0;
}
