TARG1=ex1
TARG1_OBJ=ex1.o
CGC=cgc.o

$(TARG1): $(TARG1_OBJ) $(CGC)
	gcc -o $@ $^

$(CGC): ../cgc.c
	gcc -c ../cgc.c

clean:
	rm *.o $(TARG1) $(CGC)
