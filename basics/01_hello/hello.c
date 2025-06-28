#include <linux/module.h>
#include <linux/init.h>



int my_init(){
	printk("hello - Hello, Kernel!\n");
	return 0
}



void my_exit() {
	printk("hello - Goodbye, Kernel!\n");
}

module_init(my_init);
module_exit(my_exit);

GPL
