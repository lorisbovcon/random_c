CFLAGS = -Wno-implicit-function-declaration

all: random single

random: random.c
	@gcc $(CFLAGS) -o random random.c

single: single_random.c
	@gcc $(CFLAGS) -o single_random single_random.c
