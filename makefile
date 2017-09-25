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

#------------------------------------------------------------------------------
# Makefile: Course 1 Module 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

MSG = PLATFORM_NOT_INITIALIZED
CFLAGS = -g -Werror -std=c99 -O0
TARGET = c1m4
INCLUDES = $(INCLUDE_DIRS)
CPPFLAGS = -MD -MP
OBJS = $(SOURCES:.c=.o)


#---------------------------------------------------------------------------------------
ifeq ($(PLATFORM),HOST)
#---------------------------------------------------------------------------------------

MSG = HOST
#CPPFLAGS += -DHOST -DCOURSE1 -DVERBOSE
CPPFLAGS += -DHOST -DCOURSE1
CC = gcc
SIZE = size 

#---------------------------------------------------------------------------------------
else ifeq ($(PLATFORM),MSP432)
#---------------------------------------------------------------------------------------

MSG = MSP432
CPPFLAGS += -DMSP432
CC = arm-none-eabi-gcc
CFLAGS += -mcpu=cortex-m4 -mthumb -march=armv7e-m  --specs=nosys.specs -mfloat-abi=soft -mfpu=fpv4-sp-d16
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
LINKER_FILE = ./msp432p401r.lds
SIZE = arm-none-eabi-size 

#---------------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------------

MSG = NOT_SUPPORTED

#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------

%.i : %.c
	$(CC)  -E  $(CPPFLAGS)  $(INCLUDES)  $(CFLAGS)  $<  -o  $@


%.asm : %.c
	$(CC)  -S  $(CPPFLAGS)  $(INCLUDES)  $(CFLAGS)  $<  -o  $@

%.o : %.c
	$(CC)  -c  $(CPPFLAGS)  $(INCLUDES)  $(CFLAGS)  $<  -o  $@
	objdump -p $@


$(TARGET).out: $(OBJS)
	$(CC)  $(INCLUDES)  $(CPPFLAGS)  $(OBJS)  $(CFLAGS)  $(LDFLAGS)  -o $@
	@echo
	@echo 
	@echo ... Output from 'size' utility
	@echo 
	$(SIZE) -Atd $@
	@echo


# ----------------------------------
#   build, compile-all, clean
# ----------------------------------

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean: 
	rm  -f  ./src/*.d  ./src/*.o  *.map  ./src/*.out  ./src/*.i *.out

.PHONY: build
build: $(TARGET).out



#debug rule
.PHONY: debug
debug:
	@echo  
	@echo SOURCES: $(SOURCES)
	@echo MSG: $(MSG)
	@echo

