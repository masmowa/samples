#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

#include "convert_alphanum_str_to_num_str.h"

using namespace std;


// convert the nibble representation of either upper or lower nibble of a byte
char numeric_from(char nibble) {
    //std::cout << "to_alnum(" << (int)nibble << ")" << std::endl;
    char res = (nibble + 0x30);
    if (0x0A <= nibble && 0x0F >= nibble) {
        res = (nibble - 0x0A) + 0x41;
    }
    return res;
}

// this will only work with 8-bit ASCII values;
// it will need to be adapted to work with values outside the printable ASCII range
// convert alphanumeric string to numeric string
// numeric string is hex (radix 16) baseds
// no prefix is added only the digit ASCII representation of the hex values.
char* alpha_numeric_to_num_str(char * str) {

    std::cout << "++ alpha_numeric_to_num_str(" << str << ")" << std::endl;
    char * pch = str;
    char hi_byte = 0;
    char lo_byte = 0;
    int len_str = strlen(str);
    int len_an_str = (len_str * 2 + 1);
    cout << "len_str = " << len_str << " len_an_str = " << len_an_str << endl;
    char * result = new char[len_an_str];
    for (int i=0; i < len_an_str; ++i) {
        result[i] = 0;
    }
    char * pchr = &result[0];
    if (pch != NULL) {
        while (*pch != 0) {
            if ((*pch > 0x29 && *pch < 0x3A) || (*pch > 0x40 && *pch < 0x91) || (*pch > 0x60 && *pch < 0x7B)) {
                hi_byte = numeric_from((char)(*pch & 0xF0) >> 4);
                // std::cout << "high nibble: " << (int)hi_byte << ":" <<(char)hi_byte << std::endl;
                *pchr++ = (char)hi_byte;
                lo_byte = numeric_from((char)(*pch & 0x0F));
                // std::cout << "low nibble: " << (int)lo_byte << ":" <<(char)lo_byte << std::endl;
                *pchr++ = (char)lo_byte;
                ++pch;
            }
            else {
                std::cout << "string [" << str << "] contains non-alpha non-numeric values" << std::endl;
                break;
            }

        }
    }
    cout << "-- alpha_numeric_to_num_str() result = [" << result << "]" << endl;

    return result;
}

