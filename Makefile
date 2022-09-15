
SRCS = $(shell cat compilable)

OPT_PROGS = $(patsubst %.c,loops.minotaur/%.minotaur.S,$(SRCS))
OPT_LLVMS = $(patsubst %.c,loops.minotaur.llvm/%.minotaur.ll,$(SRCS))
BSL_PROGS = $(patsubst %.c,loops.baseline/%.baseline.S,$(SRCS))
BSL_LLVMS = $(patsubst %.c,loops.baseline.llvm/%.baseline.ll,$(SRCS))

prepare:
	mkdir -p loops.minotaur loops.baseline loops.minotaur.llvm loops.baseline.llvm

minotaur: $(OPT_PROGS) $(OPT_LLVMS)

baseline: $(BSL_PROGS) $(BSL_LLVMS)

loops.minotaur/%.minotaur.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.minotaur.llvm/%.minotaur.ll : srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm  -o $@ $<

loops.baseline/%.baseline.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.baseline.llvm/%.baseline.ll: srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm -o $@ $<


clean:
	rm -f loops.minotaur/*.S
	rm -f loops.baseline/*.S
