exploit: mmu.c exploit.c
	gcc -Wall -ggdb -o exploit mmu.c exploit.c
clean:
	rm exploit
