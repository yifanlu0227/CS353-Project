cmd_/home/luyifan/cs353-lab/lab1/module1/module1.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id=sha1  -T ./scripts/module-common.lds -o /home/luyifan/cs353-lab/lab1/module1/module1.ko /home/luyifan/cs353-lab/lab1/module1/module1.o /home/luyifan/cs353-lab/lab1/module1/module1.mod.o;  true