PROJECT = JJC_Delay-v1.0

# Define object files in relation to theur locaion in SRCPATH
SOURCES = main.c


# Path Configurations
SRCPATH = src
BUILDROOT = build

# Generate object file list
objstmp := ${SOURCES}
objstmp := $(objstmp:.c=.o)
OBJS=$(addprefix ${BUILDROOT}/,$(objstmp))


# Compiler
${BUILDROOT}/%.o: ${SRCPATH}/%.c
	gcc -c -o $@ $<

JJC_Delay: ${OBJS}
	gcc -o $@ $^

build: JJC_Delay

.phony: build