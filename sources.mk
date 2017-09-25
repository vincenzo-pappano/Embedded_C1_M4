#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

SOURCES = ./src/course1.c \
          ./src/data.c    \
          ./src/main.c    \
          ./src/memory.c  \
          ./src/stats.c


INCLUDE_DIRS = -I./include/common


ifeq ($(PLATFORM),MSP432)

SOURCES += ./src/startup_msp432p401r_gcc.c    \
 		   ./src/system_msp432p401r.c         \
		   ./src/interrupts_msp432p401r_gcc.c

INCLUDE_DIRS += -I./include/msp432   \
                -I./include/CMSIS

endif