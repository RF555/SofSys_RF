CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g

all: maindloop maindrec mains loopd recursived recursives loops
mains:


loopd: main.o libclassloops.so
	$(CC) $(FLAGS) -o loopd main.o ./libclassloops.so

loops: main.o libclassloops.a
	$(CC) $(FLAGS) -o loops main.o libclassloops.a

recursived: main.o libclassrec.so
	$(CC) $(FLAGS) -o recursived main.o ./libclassrec.so

recursives: main.o libclassrec.a
	$(CC) $(FLAGS) -o recursives main.o libclassrec.a

maindloop:


maindrec:


libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a -o basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs  -o libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o


advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
		$(CC) $(FLAGS) -c advancedClassificationRecursion.c


basicClassification.o: basicClassification.c NumClass.h 
	$(CC) $(FLAGS) -c basicClassification.c


main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindloop maindrec mains loopd recursived recursives loops
