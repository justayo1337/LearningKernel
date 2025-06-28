/*
* hello-1.c - The simplest kernel module.
*/

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AYO");
MODULE_DESCRIPTION("A sample driver");
static int hello3_data __initdata = 4;

static int __init hello_4_init(void) {
	pr_info("Hello world %d.\n",hello3_data);
	/* non 0 return meant init_module failed */
	return 0;

}

static void __exit hello_4_exit(void){
	pr_info("Goodbye world 4.\n");
}


module_init(hello_4_init);
module_exit(hello_4_exit);


