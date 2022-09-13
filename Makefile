
SRCS = $(shell cat compilable)

OPT_PROGS = $(patsubst %.c,loops.minotaur/%.minotaur.ll,$(SRCS))
BSL_PROGS = $(patsubst %.c,loops.baseline/%.baseline.ll,$(SRCS))

prepare:
	mkdir -p loops.minotaur loops.baseline

minotaur: $(OPT_PROGS)

baseline: $(BSL_PROGS)

loops.minotaur/%.minotaur.ll: srcs/%.c
	$(CC) -O3 -march=native -c  -o $@ $<

loops.baseline/%.baseline.ll: srcs/%.c
	$(CC) -O3 -march=native -c  -o $@ $<


clean:
	rm -f loops.minotaur/*.ll
	rm -f loops.baseline/*.ll
