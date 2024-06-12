#!/bin/sh

openocd -s ./scripts -f interface/kitprog3.cfg -f target/$1.cfg -c "psoc6 sflash_restrictions 1" -c "init; reset init"

