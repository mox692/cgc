TARG=cgc
OBJS=cgc.o

$(TARG): $(OBJS)
	gcc -o $@ $^

clean:
	rm *.o $(TARG)
