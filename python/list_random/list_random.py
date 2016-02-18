import math
import random
import sys

# from math import random


"""
comment

"""

# count random7
# Write a function that that uses a standard random number generator
# to compute 100,000 random numbers between 1 and 500,000 and
# returns the total number of unique random numbers found
class RandRange:

    rand_val_map = dict()

    def find_most_frequent(self, in_dict, key_value):
        return [k for k,v in in_dict.items() if v == key_value]

    def print_most_frequent_rand(self):
        bigest_value = 0
        for k, v in self.rand_val_map.items():
            if v >= bigest_value:
                bigest_value = v
        # create a list of keys that have the same value (count)
        print ("Largest frequency is {}".format(bigest_value))

        my_freq_list = self.find_most_frequent(self.rand_val_map, bigest_value)

        print ("list len {} values {}".format(my_freq_list.__len__(),my_freq_list))

        return my_freq_list

    def print_unique_rand_values(self):
        unique_list = self.find_most_frequent(self.rand_val_map, 1)
        print ("unique list len {} values {}".format(unique_list.__len__(), unique_list))

        return unique_list.__len__()

    def fill_map_with_random(self, lowest, highest, map_size):
        count = 0
        while (count < map_size):
            num = random.randint(lowest, highest)
            if num not in self.rand_val_map:
                self.rand_val_map[num] = 1
                count += 1
            else:
                # saw this value before incrient the ount
                self.rand_val_map[num] += 1

        print ("length of rand_val_map {}".format(self.rand_val_map.__len__()))

    def rand_test(self):
        print ("in rand_test")

        self.fill_map_with_random(1, 500001, 100000)

        freq_list = self.print_most_frequent_rand()
        unique_count = self.print_unique_rand_values()



def main():
    rr = RandRange()
    most_frequent = rr.rand_test()

if __name__ == '__main__':
    sys.exit(main())