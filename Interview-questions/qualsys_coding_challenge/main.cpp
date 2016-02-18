#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

#include "Linked_list_with_insert.h"
#include "convert_alphanum_str_to_num_str.h"

using namespace std;

/**
Coding challenge: (Send code for the following)
1.  Insert a node into a singly linked list
    (and this should be able to be compiled)

2.  Convert an alphanumeric string to a numeric string.
    (in your answer list any assumptions that you are making,
     this code should be able to be called and reused)

**/

/**
    to enable test cases define one of the following
**/
/* testing linked list */
#define TEST_SINGLY_LINKED_LIST 1

/* testing alphanumeric string to a numeric string */
#define TEST_ALNUM_STR_TO_NUM_STR 1


int test_sll_insert_to_empty_list() {
    cout << " create SLL " << endl;
    SLL sll;
    const int val_as_head = 100;
    NODE* hint = NULL;
    sll.Insert(hint, val_as_head);
    int sll_size = sll.Size();
    cout << " delete sll " << endl;

    return sll_size;

}

int test_sll_build_small_list() {
    cout << "++ test_sll_build_small_list() create sll " << endl;
    const int head_value = 100;
    int step = 2;
    size_t list_count = 10;
    SLL sll(head_value);
    NODE* hint = sll.Head();
    NODE* hint_next = hint;
    for (int i = head_value + step, counter = list_count; counter > 0; i += step, --counter) {
        hint_next = sll.Insert(hint_next, i);
    }

    sll.Dump();
    cout << "sll.size() = " << sll.Size() << endl;
    hint = sll.Find(106);
    sll.Insert(hint, 107);

    cout << "sll.size() = " << sll.Size() << endl;
    hint = sll.Tail();
    sll.Insert(hint, 1000);

    sll.Dump();
    cout << "sll.size() = " << sll.Size() << endl;

    sll.Insert(NULL, 98);

    cout << "sll.size() = " << sll.Size() << endl;
    int sll_size = sll.Size();
    sll.Dump();
    cout << " delete sll " << endl;

    return sll_size;

}

void test_convert_alpha_numeric_to_numeric() {
    char * test_items[] = {
        "0",
        "1",
        "9",
        "19",
        "a",
        "z",
        "A",
        "Z",
        "LMNOPQRSTUVWXYZ",
        "10"
        "128",
        "r892lk",   // invalid
        "0x10",
        "0x100",
        "F001",
        "!",
        ""
    };


    for (int i=0; test_items[i][0] != '\0'; ++i) {
        cout << "converting " << test_items[i] << endl;
        char* result = alpha_numeric_to_num_str(test_items[i]);
        cout << "--- alpha_numeric_to_num_str() result = [" << result << "]" << endl;
        delete [] result;

    }

}

int main()
{
#if defined(TEST_ALNUM_STR_TO_NUM_STR)
    test_convert_alpha_numeric_to_numeric();
#endif // 1
#if defined(TEST_SINGLY_LINKED_LIST)
    int size_sll = test_sll_insert_to_empty_list();
    cout << "test_sll_insert_to_empty_list() size = " << size_sll << endl;

    size_sll = test_sll_build_small_list();
    cout << "test_sll_build_small_list() size = " << size_sll << endl;
#endif // 1

    return 0;
}
