#!/bin/bash

# MY ARCHITETURE
os=$(uname -a)
# MY CPU INFO (PHYSICAL)
cpuf=$(lscpu | grep "Socket(s):" | head -n 1 | awk '{print $2}')
# MY CPU INFO VIRTUAL
cpuv=$(lscpu | grep "CPU(s):" | head -n 1 | awk '{print $2}')
# MY MEMORY RAM USAGE
mem=$(free -m | awk '$1 == "Mem:" {printf("%iMiB/%iMiB (%.2f%%)", $3, $2, $3/$2*100)}')
# MY DISK USAGE
disk=$(df -m --output=source,used,avail | grep "^/dev/" | awk '{used+=$2; avail+=$3} END {printf("%dMB/%.2fGB (%.2f%%)\n", used, avail/1024, used/avail*100)}')
#MY CPU LOAD
cpul=$(top -bn3 | grep "%Cpu" | awk 'END {printf("%.2f%%\n"), 100-$8}')
#LAST BOOT TIME
lboot=$(uptime -s)
#NUMBER TCPS CONNECTIONS
tcps=$(ss -ta | grep "ESTAB" | wc -l)
#USERS LOGGED
users=$(users | wc -w)
#MY IP AND MAC ADDRESS
ipadd=$(echo "IP: $(ip -o -4 addr | grep "enp" | head -n1 | awk '{print $4}' | cut -d/ -f1) | ")
macadd=$(echo "MAC: $(ip a | grep "link/ether" | head -n1 | awk '{print "(" $2 ")"}')")
netw= "$ipadd $macadd"
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
		#Connections TCP : $tcps
		#User log: $users
		#Network: $netw
		#Sudo : $sudo
"