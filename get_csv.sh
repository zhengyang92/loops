#!/bin/bash

set -e

for i in $(cat changed) ;  do  echo -n "$i," ; grep "Total uOps" loops.baseline.mca/$i.baseline.mca |  tr -dc '0-9'; echo -n "," ; grep "Total uOps" loops.minotaur.mca/$i.minotaur.mca |  tr -dc '0-9'  ; echo "" ; done
