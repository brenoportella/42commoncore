# Born2beRoot

## Overview
**Born2beRoot** is a system administration project from 42 school designed to introduce students to the fundamentals of virtualization, server configuration, and system security.
You will be tasked with creating a secure virtual server following strict rules and best practices.

## Objectives
- Set up a Virtual Machine using **VirtualBox** (or **UTM** if VirtualBox is not available).
- Install a minimal operating system (**Debian** recommended or **Rocky** Linux).
- Configure the system according to security standards.
- Implement mandatory server functionalities.
- Submit a `signature.txt` file containing the SHA1 signature of your virtual disk.

## Mandatory Requirements

### System Setup
- No graphical interface installation allowed (no X.org or equivalent).
- Two encrypted partitions must be created using **LVM**.
- The system firewall (**UFW** for Debian, **firewalld** for Rocky) must allow only port `4242`.
- An **SSH** service must run on port `4242`, **root login via SSH must be disabled**.

### Hostname and Users
- The hostname must match your login followed by `42` (e.g., `wil42`).
- Create a non-root user with:
  - Username = your login.
  - Membership in `user42` and `sudo` groups.

### Password Policy
- Password must:
  - Expire every 30 days.
  - Be changeable only after 2 days minimum.
  - Warn users 7 days before expiration.
  - Be at least 10 characters, with uppercase, lowercase, and numeric characters.
  - Not include the username or more than 3 identical consecutive characters.
- Root password must also comply with these rules.

### Sudo Configuration
- Limit sudo authentication attempts to 3.
- Display a custom error message upon wrong sudo password attempts.
- Log all sudo actions (input/output) in `/var/log/sudo/`.
- Enable TTY requirement for sudo.
- Restrict `secure_path` to essential directories.

### Monitoring Script
- Create a `monitoring.sh` bash script that displays system information every 10 minutes via `wall`.
- Details to be displayed:
  - Architecture and kernel version.
  - OS distribution.
  - Number of physical CPUs.
  - Number of virtual CPUs.
  - RAM usage.
  - Disk usage.
  - CPU load.
  - Last boot time.
  - LVM usage.
  - Number of active TCP connections.
  - Number of logged-in users.
  - IP and MAC address.
  - Number of commands executed with `sudo`.

Example `monitoring.sh` script:
```bash
#!/bin/bash

mach=$(echo "$(id -un)@$(hostname)")
os=$(uname -rm)
dist=$(grep "PRETTY_NAME" /etc/os-release | cut -d\" -f2)
cpuf=$(lscpu | grep "Socket(s):" | head -n 1 | awk '{print $2}')
cpuv=$(lscpu | grep "CPU(s):" | head -n 1 | awk '{print $2}')
mem=$(free -m | awk '$1 == "Mem:" {printf("%iMiB/%iMiB (%.2f%%)", $3, $2, $3/$2*100)}')
disk=$(df -m --output=source,used,avail | grep "^/dev/" | awk '{used+=$2; avail+=$3} END {printf("%dMB/%.2fGB (%.2f%%)\n", used, avail/1024, used/avail*100)}')
cpul=$(top -bn3 | grep "%Cpu" | awk 'END {printf("%.2f%%"), 100-$8}')
lboot=$(uptime -s)
lvm=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")
tcps=$(ss -ta | grep "ESTAB" | wc -l)
users=$(users | sort -u |wc -w)
ipadd=$(echo "IP $(ip -o -4 addr | grep "enp" | head -n1 | awk '{print $4}' | cut -d/ -f1) |")
macadd=$(echo "MAC $(ip a | grep "link/ether" | head -n1 | awk '{print "(" $2 ")"}')")
netw="$ipadd $macadd"
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l | awk '{print $1 " cmd"}')

wall "
    $mach
    -------------------------------------------
    #Architecture: $os
    #Distro: $dist
    #CPU physical: $cpuf
    #vCPU: $cpuv
    #Memory usage: $mem
    #Disk usage: $disk
    #CPU load: $cpul
    #Last boot: $lboot
    #LVM use: $lvm
    #Connections TCP: $tcps
    #User log: $users
    #Network: $netw
    #Sudo: $sudo
"
```
---

## Status

Project successfully implemented and tested.
