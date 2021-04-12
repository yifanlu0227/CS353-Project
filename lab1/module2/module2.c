//<module2.c>
//Support for int&str&array parameter
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
//TODO: 声明用于接收参数的变量
static int test1;
static int test2[20];
static char* test3;
static int n_test2;


//TODO: 使用module_param来指定模块可接受的参数 
module_param(test1,int,0644);
module_param_array(test2,int,&n_test2,0644);
module_param(test3,charp,0644);

static int __init hello_init(void)
{
//TODO: 加载模块时printk输出信息，打印参数的值
    int i;
    printk(KERN_INFO "test1 %d\n",test1);
    for(i=0;i<n_test2;i++)
        printk(KERN_INFO "test2 %d\n",test2[i]);
    printk(KERN_INFO "test3 %s\n",test3);
    return 0;
}
static void __exit hello_exit(void)
{
//TODO: 卸载模块时printk输出信息 
    printk(KERN_INFO "Silence Wench!\n");
}
module_init(hello_init);
module_exit(hello_exit);