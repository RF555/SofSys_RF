CC = gcc
FLAGS = -Wall -g
MY_DYNAMIC_LIB = libseq.so
AR = ar
OBJECT_LIB = my_seq.o
OBJECT_MAIN = main.o

all: stringProg

# # DYNAMIC linking
stringProg: $(OBJECT_MAIN) $(MY_DYNAMIC_LIB)
	$(CC) $(FLAGS) -o stringProg $(OBJECT_MAIN) ./$(MY_DYNAMIC_LIB) -lm

# DYNAMIC library
$(MY_DYNAMIC_LIB): $(OBJECT_LIB)
	$(CC) -shared -o $(MY_DYNAMIC_LIB) $(OBJECT_LIB)

$(OBJECT_LIB): my_seq.c my_seq.h
	$(CC) $(FLAGS) -c my_seq.c

$(OBJECT_MAIN): my_seq.c my_seq.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean
clean:
#	-${RM} ${MY_DYNAMIC_LIB} ${OBJS} $(SRCS:.c=.d)
	rm -f *.o *.a *.so stringProg $(MY_DYNAMIC_LIB) $(MY_STATIC_LIB)