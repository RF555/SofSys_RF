CC = gcc
FLAGS = -Wall -g
# MY_DYNAMIC_LIB = 
# MY_STATIC_LIB = 
AR = ar
# OBJECT_LIB = 
# OBJECT_MAIN = 

all: #??

# # DYNAMIC linking
??: $(OBJECT_MAIN) $(MY_DYNAMIC_LIB)
	$(CC) $(FLAGS) -o ?? $(OBJECT_MAIN) ./$(MY_DYNAMIC_LIB) -lm

# DYNAMIC library
$(MY_DYNAMIC_LIB): $(OBJECT_LIB)
	$(CC) -shared -o $(MY_DYNAMIC_LIB) $(OBJECT_LIB)

$(OBJECT_LIB): ???.c ????.h
	$(CC) $(FLAGS) -c ???.c

$(OBJECT_MAIN): ???.c ???.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean
clean:
#	-${RM} ${MY_DYNAMIC_LIB} ${OBJS} $(SRCS:.c=.d)
	rm -f *.o *.a *.so ?? $(MY_DYNAMIC_LIB) $(MY_STATIC_LIB)