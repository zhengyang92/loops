#!/bin/bash

set -e
for i in $(cat fuvr) ; do cmp  loops.baseline.asm/$i.baseline.S loops.minotaur.asm/$i.minotaur.S > /dev/null || echo $i ; done
