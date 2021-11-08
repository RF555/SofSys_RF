CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g

all: maindloop maindrec mains loopd recursived recursives loops

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

loopd: libclassloops.so

loops: libclassloops.a

recursived: libclassrec.so

recursives: libclassrec.a

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
	rm -f *.o *.a *.so maindloop maindrec mains loopd recursived recursives loops *.txt
