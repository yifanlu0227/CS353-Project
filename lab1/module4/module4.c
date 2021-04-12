//<module4.c>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h> // for basic filesystem
#include <linux/proc_fs.h> // for the proc filesystem
#include <linux/seq_file.h> // for sequence files
#include <linux/slab.h> // for kzalloc, kfree
#include <linux/uaccess.h> // for copy_from_user
#define BUF_SIZE 10

//TODO: 可以在这里声明需要的变量，注意static关键字的使用
static char buf[BUF_SIZE];
static struct proc_dir_entry *hello_dir;
static struct proc_dir_entry *hello;

static int hello_proc_show(struct seq_file *m, void *v)
{
	/* 这里不能使用printfk之类的函数，要使用seq_file输出的一组特殊函数 */
	seq_printf(m, "%s",buf);
 
	//必须返回0，否则什么也显示不出来
	return 0;
}

// file_operations -> write
static ssize_t hello_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos)
{
    //TODO: 定义文件操作 
    if(copy_from_user(buf,buffer,count)){
        return -EFAULT;
    }
    buf[count] = '\0';
    return count;
}
// seq_operations -> open
static int hello_open(struct inode *inode, struct file *file)
{
    //TODO: 定义文件操作 
    return single_open(file, hello_proc_show, NULL);
}
static const struct proc_ops hello_fops =
{
    //TODO: 指定文件操作 
    .proc_read = seq_read,
    .proc_open = hello_open,
    .proc_write = hello_write,
};
// module init
static int __init hello_init(void)
{
    //TODO: 创建proc目录、创建proc文件 
    buf[0] = '\0';
    hello_dir = proc_mkdir("hello_dir",NULL);
    hello = proc_create("hello",0644,hello_dir,&hello_fops);
    return 0;
}
// module exit
static void __exit hello_exit(void)
{
    //TODO: 删除proc目录、删除proc文件，如有手动分配内存空间，记得释放 
    remove_proc_entry("hello",hello_dir);
    remove_proc_entry("hello_dir",NULL);
}
module_init(hello_init);
module_exit(hello_exit);