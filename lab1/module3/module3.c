//<module3.c>
//read-only proc file
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int hello_proc_show(struct seq_file *m, void *v)
{
	/* 这里不能使用printfk之类的函数，要使用seq_file输出的一组特殊函数 */
	seq_printf(m, "Hello?\n");
 
	//必须返回0，否则什么也显示不出来
	return 0;
}


static int hello_proc_open(struct inode *inode, struct file *file) { 
    //定义文件操作
    printk(KERN_INFO "hello proc opened successfully\n");
    // single_open 从内核导出信息到用户空间
    return single_open(file, hello_proc_show, NULL);
}
static const struct proc_ops hello_proc_fops = { 
    //TODO: 指定文件操作
    .proc_open  = hello_proc_open,
    .proc_read = seq_read, //这个一定要有，否则回报Input/output error
    .proc_release = single_release,
};
static int __init hello_proc_init(void){
    //TODO: 加载模块时printk输出信息 
    printk(KERN_INFO "Loading Module\n");
    struct proc_dir_entry *file;
    file = proc_create("hello_proc",0444,NULL,&hello_proc_fops);
    if(!file)
        return -ENOMEM;
    return 0;
}
static void __exit hello_proc_exit(void){ 
    //TODO: 卸载模块时printk输出信息
    remove_proc_entry("hello_proc",NULL);
    printk(KERN_INFO "Uninstalling Module\n");
    
}
module_init(hello_proc_init);
module_exit(hello_proc_exit);