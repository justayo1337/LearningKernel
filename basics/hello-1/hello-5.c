/*
* hello-1.c - The simplest kernel module.
*/

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AYO");
MODULE_DESCRIPTION("A sample driver");
static int hello3_data __initdata = 5;

static short int myshort = 1;
static int maint = 200;
static long int mylong =9999;
static char *mystring = "blah";
static int myintarray[2] = {200, 200}; 
static int arr_argc = 0;



/*****************************************
 * module_param( param_name,param_type, param_permbits(to expose to sysfs later see `man 2 chmod`)
 * MODULE_PARM_DESC(PARAM_NAME,description)
 */
module_param (myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
MODULE_PARM_DESC(myshort, "A short integer");
module_param (maint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
MODULE_PARM_DESC(main, "An integer");
module_param (mylong, long, S_IRUSR);
MODULE_PARM_DESC(myshort, "A long integer");
module_param(mystring, charp,0000);
MODULE_PARM_DESC(mystring, "A character string");


/*module_param_array(param_name, param_type, paramcount, param_permbits)
 *also see: module_param_string 
 * */
module_param_array(myintarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintarray, "Array of Integers");




static int __init hello_5_init(void) {
	pr_info("Hello world %d.\n============================\n",hello3_data);
	pr_info("myshort is a short integer: %hd\n", myshort);
	pr_info("myint is an integer: %d\n", maint);
	pr_info("mylong is a long integer: %ld\n", mylong);
	pr_info("mystring is a string: %s\n", mystring);
	/* ARRAY_SIZE DEFINED IN include/linux/array_size.h*/ 
	for (int i=0; i < ARRAY_SIZE(myintarray); i++)
		pr_info("myintarray[%d] = %d", i , myintarray[i]);
	pr_info ("got %d arguments for myintarrray.\n", arr_argc);

	/* non 0 return meant init_module failed */
	return 0;

}

static void __exit hello_5_exit(void){
	pr_info("Goodbye world 5.\n");
}


module_init(hello_5_init);
module_exit(hello_5_exit);


