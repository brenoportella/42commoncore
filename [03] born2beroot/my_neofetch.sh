#!/bin/bash

# MY OS INFO
os=$(uname -a)

# MY CPU INFO (PHYSICAL)
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# MY CPU INFO VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# MY MEMORY RAM
mem=$(free --mega | awk '$1 == "Mem:" {printf("%i/%iMB (%.2f%%)\n", $3, $2, $3/$2*100)}')

# MY DISK USAGE
disk=$(df -m | grep "/dev" | grep -v "/boot" | awk '{memory_use += $3} {total += $2} END {printf("%d/%dGb (%d%%)\n",memory_use,total/1024, memory_use/total*100)}')


# MY NEOFETCH HEHEHE
my_os= $(grep 'PRETTY_NAME=' /etc/os-release | cut -d'"' -f2)
my_host=
my_kernel=
my_uptime=
my_packages=
my_shell=
my_resolution=
my_terminal=
my_cpu=
my_gpu=
my_memory=