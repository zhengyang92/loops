
SRCS = $(wildcard *.c)

OPT_PROGS = $(patsubst %.c,%.minotaur.ll,$(SRCS))
ORG_PROGS = $(patsubst %.c,%.origin.ll,$(SRCS))

minotaur: $(OPT_PROGS)

origin: $(ORG_PROGS)

%.minotaur.ll: %.c
	$(CC) -O3 -march=native -c  -o $@.minotaur.ll $<

%.origin.ll: %.c
	$(CC) -O3 -march=native -c  -o $@.origin.ll $<
