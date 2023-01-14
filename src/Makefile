build: interface.o history.o tokenizer.o
	gcc -o i interface.o history.o tokenizer.o

clean:
	rm -f *.o i

main.o: tokenizer.h history.h interface.c

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c
