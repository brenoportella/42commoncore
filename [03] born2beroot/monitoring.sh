#!/bin/bash

# MY ARCHITETURE
os=$(uname -a)

# MY CPU INFO (PHYSICAL)
cpuf=$(lscpu | grep "Socket(s):" | head -n 1 | awk '{print $2}')

# MY CPU INFO VIRTUAL
cpuv=$(lscpu | grep "CPU(s):" | head -n 1 | awk '{print $2}')

# MY MEMORY RAM USAGE
mem=$(free -m | awk '$1 == "Mem:" {printf("%i/%iMB (%.2f%%)", $3, $2, $3/$2*100)}')

# MY DISK USAGE
disk=$(df -m | grep "/dev" | grep -v "/boot" | awk '{memory_use += $3} {total += $2} END {printf("%d/%dGb (%d%%)",memory_use,total/1024, memory_use/total*100)}')

#MY CPU LOAD
cpul=$(top -bn1 | grep "Cpu(s)" | awk '{printf "%.1f", $2 + $4}')

#LAST BOOT TIME
lboot=$(who -b | grep "system" | awk '{printf $3 " " $4}')

#NUMBER TCPS CONNECTIONS
tcps=$(ss -ta | grep "ESTAB" | wc -l)

#USERS LOGGED
user=$(users | wc -w)

#MY IP AND MAC ADDRESS
netw=$echo "IP $(hostname -i) $(ip link | grep "link/ether" | awk '{printf($2)}')"

#SUDO COMMANDS NUMBER
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#THE OUTPUT
wall "	
	#Architecture: $os
	#CPU physical : $cpuf
	#vCPU : $cpuv
	#Memory usage: $mem
	#Disk usage: $disk
	#CPU load: $cpul
	#Last boot: $lboot
	#LVM use: 
	#Connections TCP : $tcps
	#User log: $users
	#Network: $netw
	#Sudo : $sudo
"