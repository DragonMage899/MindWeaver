https://blog.programster.org/kvm-missing-default-network

in vm
ip link
ip link set eth0 up
udhcpc -i eth0
