CC = gcc
# CFLAGS = -fPIC -Wall -Wextra -O2 -g  # C flags
CFLAGS =  -Wall -g
# LDFLAGS = -shared   # linking flags
# RM = rm -f   # rm command
AR=ar
MY_LIB = libmat.so


SRCS = main.c src1.c src2.c  # source files
# OBJS = $(SRCS:.c=.o)

# .PHONY: all
# all: ${MY_LIB}
all: $(MY_LIB) connections

$(MY_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

# $(SRCS:.c=.d):%.d:%.c
# 	$(CC) $(CFLAGS) -MM $< >$@
#
# include $(SRCS:.c=.d)
main.o: main.c my_mat.h

.PHONY: clean
clean:
#	-${RM} ${MY_LIB} ${OBJS} $(SRCS:.c=.d)
	rm -f *.o *.a *.so connections $(MY_LIB) *.txt