
SRCS = $(shell cat integer)

OPT_PROGS = $(patsubst %.c,loops.minotaur.asm/%.minotaur.S,$(SRCS))
OPT_LLVMS = $(patsubst %.c,loops.minotaur.llvm/%.minotaur.ll,$(SRCS))
BSL_PROGS = $(patsubst %.c,loops.baseline.asm/%.baseline.S,$(SRCS))
BSL_LLVMS = $(patsubst %.c,loops.baseline.llvm/%.baseline.ll,$(SRCS))
VEG_PROGS = $(patsubst %.c,loops.vegen.asm/%.vegen.S,$(SRCS))
VEG_LLVMS = $(patsubst %.c,loops.vegen.llvm/%.vegen.ll,$(SRCS))

prepare:
	mkdir -p loops.minotaur.asm loops.baseline.asm loops.vegen.asm loops.minotaur.llvm loops.baseline.llvm loops.vegen.llvm loops.minotaur.mca loops.baseline.mca loops.vegen.mca

minotaur.asm: $(OPT_PROGS) 

minotaur.ll: $(OPT_LLVMS)

baseline.asm: $(BSL_PROGS)

baseline.ll: $(BSL_LLVMS)

vegen.asm: $(VEG_PROGS)
vegen.ll: $(VEG_LLVMS)

loops.minotaur.asm/%.minotaur.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.minotaur.llvm/%.minotaur.ll : srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm  -o $@ $<

loops.baseline.asm/%.baseline.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.baseline.llvm/%.baseline.ll: srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm -o $@ $<

loops.vegen.asm/%.vegen.S: srcs/%.c
	$(CC) -O3 -march=native -S  -o $@ $<

loops.vegen.llvm/%.vegen.ll: srcs/%.c
	$(CC) -O3 -march=native -S -emit-llvm -o $@ $<


clean:
	rm -rf  loops.minotaur.asm loops.baseline.asm loops.vegen.asm loops.minotaur.llvm loops.baseline.llvm loops.vegen.llvm loops.minotaur.mca loops.baseline.mca loops.vegen.mca
