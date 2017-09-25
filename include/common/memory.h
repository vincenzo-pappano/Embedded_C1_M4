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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMremORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
#include "platform.h"


// ------------------------------------------------------------------------

/**
 * @brief Copies a source array into a destination array 
 *
 * Given a pointer to a source array, and a pointer to a destination
 * array, copies the source array into the destination array. The 
 * behavior is undefined if there is overlap of source and destination.
 * 
 * @param  src     Pointer to source data array
 * @param  dest    Pointer to destination data array
 * @param  length  The length (in bytes) of the source array 
 *
 * @return A pointer to the destination array
 */

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Sets all elements in a source array to a given value
 *
 * 
 * @param  src     Pointer to source data array
 * @param  length  The length (in bytes) of the source array 
 * @param  value   Pointer to destination data array
 *
 * @return A pointer to the array
 */

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all elements in a source array to zero
 *
 * 
 * @param  src     Pointer to source data array
 * @param  length  The length (in bytes) of the source array 
 *
 * @return A pointer to the source array
 */

uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief Reverses the order of all the bytes in an array
 *
 * 
 * @param  src     Pointer to source data array
 * @param  length  The length (in bytes) of the source array 
 *
 * @return A pointer to the source array
 */

uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates a given number of words in dynamic memory
 *
 * 
 * @param  length  The length (in bytes) of the memory to allocate 
 *
 * @return A pointer to the allocated memory (if successfull)
 *         Otherwise a NULL pointer
 */

int32_t * reserve_words(size_t length);


/**
 * @brief Frees previously allocated dynamic memory
 *
 * 
 * @param  src  Pointer to previously allocated memory
 *
 * @return void
 */

void free_words(int32_t * src);



// ------------------------------------------------------------------------
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets to zero all elements in an array to bytes
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


uint8_t * my_memzero(uint8_t * src, size_t length);


uint8_t * my_reverse(uint8_t * src, size_t length);


int32_t * reserve_words(size_t length);


void free_words(int32_t * src);



#endif /* __MEMORY_H__ */
