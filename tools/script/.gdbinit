set mem inaccessible-by-default off
set remotetimeout 15
monitor reset run
monitor sleep 200
monitor psoc6 reset_halt sysresetreq 
monitor gdb_sync
