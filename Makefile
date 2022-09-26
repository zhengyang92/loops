
SRCS = $(shell cat integer)

OPT_PROGS = $(patsubst %.c,loops.minotaur.asm/%.minotaur.S,$(SRCS))
OPT_LLVMS = $(patsubst %.c,loops.minotaur.llvm/%.minotaur.ll,$(SRCS))
BSL_PROGS = $(patsubst %.c,loops.baseline.asm/%.baseline.S,$(SRCS))
BSL_LLVMS = $(patsubst %.c,loops.baseline.llvm/%.baseline.ll,$(SRCS))

prepare:
	mkdir -p loops.minotaur.asm loops.baseline.asm loops.minotaur.llvm loops.baseline.llvm loops.minotaur.mca loops.baseline.mca

minotaur: $(OPT_PROGS) $(OPT_LLVMS)

baseline: $(BSL_PROGS) $(BSL_LLVMS)

loops.minotaur.asm/%.minotaur.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.minotaur.llvm/%.minotaur.ll : srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm  -o $@ $<

loops.baseline.asm/%.baseline.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.baseline.llvm/%.baseline.ll: srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm -o $@ $<


clean:
	rm -rf loops.minotaur.asm loops.baseline.asm loops.minotaur.llvm loops.baseline.llvm loops.minotaur.mca loops.baseline.mca 
