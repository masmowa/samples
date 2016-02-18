#include <iostream>
#include <vector>
#include <algorithm>    // std::copy
#include <exception>
#include <stdexcept>

using namespace std;

//#define RunTests 1
#if !defined(_countof)
    #define _countof(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

class Problem
{
public:
    static size_t drop(int* array, int arraySize, int* dropIndices, int dropSize)
    {
        // size_t result = 0;

        cout << "++ Problem::drop(" << array << ", arraySize[" << arraySize << "], dropIndices[" << dropIndices << "], dropSize[" << dropSize << "])" << endl;
        // since this is pointers not references, the pointers are not guaranteed to be initialized
        if (!array)
            throw std::runtime_error("array not initialized");
        if (!dropIndices)
            throw std::runtime_error("dropIndices not initialized");
        if (arraySize < dropSize)
            throw std::runtime_error("arraySize < dropSize");
        if (0 > dropSize)
            throw std::runtime_error("dropSize  < 0");
        if (0 > arraySize)
            throw std::runtime_error("arraySize < 0");

        size_t last_array_index = 0;
        vector<int> result_v;
       for (int drop_indices_index = 0; drop_indices_index < dropSize; ++drop_indices_index ) {
            for (int i = last_array_index; i < arraySize; ++i) {

                cout << "array[" << i << "] = " << array[i] << ", dropIndices[" << drop_indices_index << "] = " << dropIndices[drop_indices_index] << endl;
                if (0 > dropIndices[drop_indices_index]) {
                    // invalid array index skip this
                    cout << "dropIndices[" << drop_indices_index << "] = " <<  dropIndices[drop_indices_index] << " not a valid index negative" << endl;
                    last_array_index = i;
                    break;
                }
                if (arraySize <= dropIndices[drop_indices_index]) {
                    // invalid array index skip this
                    cout << "dropIndices[" << drop_indices_index << "] = " <<  dropIndices[drop_indices_index] << " not a valid index too large" << endl;
                    last_array_index = i;
                    break;
                }
                if (drop_indices_index < dropSize && dropIndices[drop_indices_index] == i) {
                    cout << "dropping array[" << i << "] = " << array[i] << ", dropIndices[" << drop_indices_index << "] = " <<  dropIndices[drop_indices_index] << "  " << endl;
                    // found match select next drop indices index
                    if (++drop_indices_index >= dropSize) {
                        // drop index out of range copy the rest of the array
                        last_array_index = i + 1;
                        break;
                    }
                    continue;
                }
                else {
                    cout << "add value array[" << i << "] = " << array[i] << " to result " << endl;
                    result_v.push_back(array[i]);
                }
                cout << "last_array_index = " << last_array_index << " i = " << i << endl;
                last_array_index = i;
            }
        }
        // get the values that are after the last drop index, if any
        for (size_t i = last_array_index; i < static_cast<size_t>(arraySize); ++i) {
            result_v.push_back(array[i]);
        }
        std::copy(result_v.begin(), result_v.end(), array);

        for (size_t i = 0; i < result_v.size(); ++i) {
            cout << "array[" << i << "] = " << array[i] << endl;
        }
        //return (last_array_index ? result_v.size() : arraySize);
        return (result_v.size());
    }
};

bool verify_results(int *result_ary, int resultSize, int *expectedResult, int expectedSize)
{
    bool result = false;

    if (0 < expectedSize) {
        result = resultSize == expectedSize;
    }
    std::cout << "resultSize = " << resultSize << " expectedSize = " << expectedSize << " result = " << result << endl;

    for (size_t i = 0; result && i < static_cast<size_t>(expectedSize); i++)
    {
        result &= (result_ary[i] == expectedResult[i]);
        std::cout << "    " << i << " : result: " << result;
        if (!result){
            cout << " value = " << result_ary[i] << " expected = " << expectedResult[i] << endl;
        }
        else {
            cout << endl;
        }
    }

    std::cout << "result: " << result << endl;

    return result;
}

bool tc_with_negative_indexes()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int dropIndices[] = { -3, -4, -7, -8  };

    size_t new_size = Problem::drop(array, _countof(array), dropIndices, _countof(dropIndices));

    int expectedResult[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    bool result = verify_results(array, new_size, expectedResult, _countof(expectedResult));

    std::cout << "new_size = " << new_size << " _countof(expectedResult) = " << _countof(expectedResult) << " result = " << result << endl;

    std::cout << "result: " << result << endl;
    return result;
}

bool tc_with_out_of_bounds_indexes()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int dropIndices[] = { -3, 3, 11, 12  };

    size_t new_size = Problem::drop(array, _countof(array), dropIndices, _countof(dropIndices));

    int expectedResult[] = { 1, 2, 3, 5, 6, 7, 8, 9, 10 };
    bool result = verify_results(array, new_size, expectedResult, _countof(expectedResult));

    std::cout << "new_size = " << new_size << " _countof(expectedResult) = " << _countof(expectedResult) << " result = " << result << endl;

    std::cout << "result: " << result << endl;
    return result;
}

bool tc_with_edge_and_out_of_bounds_indexes()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int dropIndices[] = { 0, 11, 9  };

    size_t new_size = Problem::drop(array, _countof(array), dropIndices, _countof(dropIndices));

    int expectedResult[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    bool result = verify_results(array, new_size, expectedResult, _countof(expectedResult));

    std::cout << "new_size = " << new_size << " _countof(expectedResult) = " << _countof(expectedResult) << " result = " << result << endl;

    std::cout << "result: " << result << endl;
    return result;
}

#ifndef RunTests
int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int dropIndices[] = { 3, 4, 7, 8  };

    size_t new_size = Problem::drop(array, _countof(array), dropIndices, _countof(dropIndices));

    int expectedResult[] = { 1, 2, 3, 6, 7, 10 };

    //bool result = new_size == _countof(expectedResult);
    bool result = verify_results(array, new_size, expectedResult, _countof(expectedResult));

    std::cout << "new_size = " << new_size << " _countof(expectedResult) = " << _countof(expectedResult) << " result = " << result << endl;
    result = tc_with_negative_indexes();
    result = tc_with_out_of_bounds_indexes();
    result = tc_with_edge_and_out_of_bounds_indexes();

    std::cout << "result: " << result << endl;
    return (int)result;
}
#endif
