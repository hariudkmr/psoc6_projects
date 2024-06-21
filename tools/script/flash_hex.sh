#!/bin/sh

openocd -s ./scripts -f interface/kitprog3.cfg -f target/$1.cfg -c "psoc6 sflash_restrictions 1" -c "program $2 verify reset exit"

