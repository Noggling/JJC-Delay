PROJECT = JJC_Delay-v1.0

# Define object files in relation to theur locaion in SRCPATH
SOURCES = main.c
SOURCES += drivers/dac_adc.c
SOURCES += fx/delay.c

# Path Configurations
SRCPATH = src
BUILDROOT = build

# Generate object file list
objstmp := ${SOURCES}
objstmp := $(objstmp:.c=.o)
OBJS=$(addprefix ${BUILDROOT}/,$(objstmp))


# Compiler
${BUILDROOT}/%.o: ${SRCPATH}/%.c
	gcc -I ${SRCPATH} -c -o $@ $<

JJC_Delay: ${OBJS}
	gcc -o $@ $^

build: JJC_Delay

.phony: build