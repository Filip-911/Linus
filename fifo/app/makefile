all: app
app: app.o
	gcc -o app app.o
app.o: app.c
	gcc -c app.c
clean:
	rm app.o app
