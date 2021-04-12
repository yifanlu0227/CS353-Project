//<module1.c>
//Test for installing and removing of module.
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
static int __init hello_init(void){
    //TODO: 加载模块时printk输出信息 
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "Hello world\n");
    return 0;
}
static void __exit hello_exit(void){ 
    //TODO: 卸载模块时printk输出信息
    printk(KERN_INFO "Uninstalling Module\n");
    printk(KERN_INFO "Goodbye\n");
}
module_init(hello_init);
module_exit(hello_exit);