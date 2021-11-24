CC = gcc
FLAGS = -Wall -g
MY_DYNAMIC_LIB = libmat.so
MY_STATIC_LIB = libmat.a
AR = ar
OBJECT_LIB = my_mat_OG.o
OBJECT_MAIN = main_OG.o

all: connections

# # DYNAMIC linking
connections: $(OBJECT_MAIN) $(MY_DYNAMIC_LIB)
	$(CC) $(FLAGS) -o connections $(OBJECT_MAIN) ./$(MY_DYNAMIC_LIB) -lm

# DYNAMIC library
$(MY_DYNAMIC_LIB): $(OBJECT_LIB)
	$(CC) -shared -o $(MY_DYNAMIC_LIB) $(OBJECT_LIB)

# # STATIC linking
# connections: $(OBJECT_MAIN) $(MY_STATIC_LIB)
# 	$(CC) $(FLAGS) -o connections $(OBJECT_MAIN) $(MY_STATIC_LIB) -lm

# # STATIC library
# $(MY_STATIC_LIB): $(OBJECT_LIB)
# 	$(AR) -o $(MY_STATIC_LIB) $(OBJECT_LIB)

$(OBJECT_LIB): my_mat_OG.c my_mat_OG.h
	$(CC) $(FLAGS) -c my_mat_OG.c

$(OBJECT_MAIN): main_OG.c my_mat_OG.h
	$(CC) $(FLAGS) -c main_OG.c

.PHONY: clean
clean:
#	-${RM} ${MY_DYNAMIC_LIB} ${OBJS} $(SRCS:.c=.d)
	rm -f *.o *.a *.so connections $(MY_DYNAMIC_LIB) $(MY_STATIC_LIB) *.txt