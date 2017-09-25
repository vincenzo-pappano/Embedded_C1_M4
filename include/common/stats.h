/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>
#include "platform.h"

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/**
 * @brief Given an array of integer data and its length, prints the array to the screen
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return void
 */
void print_array(uint8_t * num, int len);

/**
 * @brief Given an array of integer data and its length, returns its mean
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return mean The mean of the array
 */
unsigned int find_mean(unsigned int num[], int len);

/**
 * @brief Given an array of integer data and its length, returns its maximum
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return maximum The largest value in the array
 */
unsigned int find_maximum(unsigned int num[], int len);


/**
 * @brief Given an array of integer data and its length, returns its minimum
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return minimum The largest value in the array
 */
unsigned int find_minimum(unsigned int num[], int len);

/**
 * @brief Given an array of integer data and its length, sorts the array from the largest to the smallest
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return void
 */
void sort_array(unsigned int num[], int len);

/**
 * @brief Given an array of integer data and its length, returns the median value
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return median The median value of the array
 */
unsigned int find_median(unsigned int num[], int len);

/**
 * @brief Given an array of integer data and its length, prints the array statistics (minimum, m
 *        maximum, mean, and median
 *
 * @param num  The array to print
 * @param len  The length of the array

 * @return void
 */
void print_statistics(unsigned int num[], int len);



#endif /* __STATS_H__ */
