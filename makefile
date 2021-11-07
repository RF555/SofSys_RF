CC=gcc
Ar=ar
OBJECT_MAIN=main.o
OBJECTS_LIB=mylib.o
ADVREC=advancedClassificationRecursion.o
ADVLOOP=advancedClassificationLoop.o
BASICCLASS=basicClassification.o
FLAGS= -Wall -g

all: libclassloops.a libclassrec.a libclassrec.so maindloop maindrec mains
maindloop:

maindrec:

mains:

loops: 

libclassloops.a: $(OBJECT_MAIN) $(BASICCLASS) $(ADVLOOP)
	???
libclassrec.a: $(OBJECT_MAIN) $(BASICCLASS) $(ADVREC)
	???


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
	rm -f *.o *.a *.so maindloop maindrec mains
