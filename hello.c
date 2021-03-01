#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
MODULE_LICENSE("GPL");

/* declaring the parameters */
char* message = "hello";
module_param(message, charp, 0);
int number = 3;
module_param(number, int, 0);


static int __init hello_init(void)
{
	printk(KERN_ALERT "Hello World CSCE-3402 :) \n");
	int i;
	for(i=0;i<number;i++)
		printk(KERN_ALERT "(%d) , %s\n", i, message);

	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_ALERT "Bye Bye CSCE-3402 :) \n");
}

module_init(hello_init);
module_exit(hello_cleanup);

