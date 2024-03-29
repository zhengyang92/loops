
SRCS = $(shell cat compilable)

OPT_OBJS  = $(patsubst %.c,loops.minotaur.obj/%.o,$(SRCS))
OPT_PROGS = $(patsubst %.c,loops.minotaur.asm/%.S,$(SRCS))
OPT_LLVMS = $(patsubst %.c,loops.minotaur.llvm/%.ll,$(SRCS))
BSL_OBJS  = $(patsubst %.c,loops.baseline.obj/%.o,$(SRCS))
BSL_PROGS = $(patsubst %.c,loops.baseline.asm/%.S,$(SRCS))
BSL_LLVMS = $(patsubst %.c,loops.baseline.llvm/%.ll,$(SRCS))
VEG_OBJS  = $(patsubst %.c,loops.vegen.obj/%.o,$(SRCS))
VEG_PROGS = $(patsubst %.c,loops.vegen.asm/%.S,$(SRCS))
VEG_LLVMS = $(patsubst %.c,loops.vegen.llvm/%.ll,$(SRCS))

prepare:
	mkdir -p loops.minotaur.obj loops.baseline.obj loops.vegen.obj loops.minotaur.asm loops.baseline.asm loops.vegen.asm loops.minotaur.llvm loops.baseline.llvm loops.vegen.llvm loops.minotaur.mca loops.baseline.mca loops.vegen.mca

minotaur.asm: $(OPT_PROGS) 
minotaur.ll: $(OPT_LLVMS)
minotaur.obj: $(OPT_OBJS)

baseline.asm: $(BSL_PROGS)
baseline.ll: $(BSL_LLVMS)
baseline.obj: $(BSL_OBJS)

vegen.asm: $(VEG_PROGS)
vegen.ll: $(VEG_LLVMS)
vegen.obj: $(VEG_OBJS)

CFLAGS = -O3 -march=native 
#CFLAGS = -O3 -march=native -mllvm -force-vector-width=4 -mllvm -force-vector-interleave=1

loops.minotaur.obj/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c  -o $@ $<

loops.minotaur.asm/%.S: srcs/%.c
	$(CC) $(CFLAGS) -S  -o $@ $<

loops.minotaur.llvm/%.ll : srcs/%.c
	$(CC) $(CFLAGS) -S -emit-llvm  -o $@ $<

loops.baseline.obj/%.o: srcs.iaca/%.c
	$(CC) $(CFLAGS) -c  -o $@ $<

loops.baseline.asm/%.S: srcs/%.c
	$(CC) $(CFLAGS) -S  -o $@ $<

loops.baseline.llvm/%.ll: srcs/%.c
	$(CC) $(CFLAGS) -S -emit-llvm -o $@ $<

loops.vegen.obj/%.o: srcs.iaca/%.c
	$(CC) $(CFLAGS) -c  -o $@ $<

loops.vegen.asm/%.S: srcs/%.c
	$(CC) $(CFLAGS) -S  -o $@ $<

loops.vegen.llvm/%.ll: srcs/%.c
	$(CC) $(CFLAGS) -S -emit-llvm -o $@ $<


clean:
	rm -rf  loops.minotaur.obj loops.baseline.obj loops.vegen.obj  loops.minotaur.asm loops.baseline.asm loops.vegen.asm loops.minotaur.llvm loops.baseline.llvm loops.vegen.llvm loops.minotaur.mca loops.baseline.mca loops.vegen.mca
