
/******************************************************************************
 * Copyright (C) 2017 by Vincenzo Pappano
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Vincenzo Pappano is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 *
 * @brief Contains function prototypes itoa and atoi functions
 *
 * To be added
 *
 * @author Vincenzo Pappano
 * @date 09/24/17
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include "platform.h"
#include "memory.h"


// #include <stdint.h>


/* Add Your Declarations and Function Comments here */ 


/**
 * @brief Given a base, converts a 32-bit integer to its string representation
 *
 * @param data 32-bit integer to be converted
 * @param ptr  Pointer to byte array that will hold string representation
 * @param base The base for the 32 for the 32-bit integer

 * @return byte The length of the string
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Given a string representation of a number, and a base, converts  
 *        the array to a 32-bit number
 *
 * @param num  The array holding the string representation of the 32-bit number
 * @param len  The number of digits in the array
 * @param base The base we wish to convert into

 * @return 32-bit number
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif

