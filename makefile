strtest: info.c
	gcc info.c -o strtest

clean:
	rm *~

run: strtest
	./strtest
