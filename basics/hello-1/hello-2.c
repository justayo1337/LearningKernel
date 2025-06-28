/*
* hello-1.c - The simplest kernel module.
*/

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>

static int __init hello_2_init(void) {
	pr_info("Hello world 2.\n");
	/* non 0 return meant init_module failed */
	return 0;

}

static void __exit hello_2_exit(void){
	pr_info("Goodbye world 2.\n");
}


module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_LICENSE("GPL");

