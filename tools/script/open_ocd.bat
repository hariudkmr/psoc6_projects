@echo off
REM Connect to FX3G2 Device via OpenOCD
openocd.exe -s ./scripts -f interface/kitprog3.cfg -c "adapter serial 1918101D03201400" -f target/%1.cfg -c "psoc6 sflash_restrictions 1" -c "init; reset init"

