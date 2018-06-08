
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("MIT");

static int __init foo_driver_init(void) {
  printk(KERN_INFO "Hello world (from FooDriver)!\n");
  return 0;
}

static void __exit foo_driver_exit(void) {
  printk(KERN_INFO "Bye, cruel world (from FooDriver)\n");
}

module_init(foo_driver_init);
module_exit(foo_driver_exit);
