LDLIBS = -lglut -lGLU -lGL -lm

simple: simple.o graphics.o
	gcc -o simple simple.o graphics.o $(LDLIBS)

simple.o: simple.c
	gcc -c simple.c $(LDLIBS)

graphics.o: graphics.c
	gcc -c graphics.c $(LDLIBS)


test: simple
	./simple

clean:
	rm -f simple *~ *.o
