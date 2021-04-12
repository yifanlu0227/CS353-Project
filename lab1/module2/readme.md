make

sudo insmod module2.ko test1=2 test2=1,2,3 test3=Helloworld

or 

sudo insmod module2.ko test1=2 test2=1,2,3 test3="Helloworld"

sudo dmesg -c

sudo rmmod module2.ko

sudo dmesg -c