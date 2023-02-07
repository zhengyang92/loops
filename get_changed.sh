#!/bin/bash

set -e
for i in $(cat fuvr) ; do cmp  loops.baseline.asm/$i.S loops.minotaur.asm/$i.S > /dev/null || echo $i ; done
