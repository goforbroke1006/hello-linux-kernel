#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/usb.h>

#define DRIVER_AUTHOR "Sergey Cherkesov <sergey.cherkesov.1006@gmail.com>"
#define DRIVER_DESC "USB ??? Driver"

#define VENDOR_ID	0x0fc5
#define PRODUCT_ID	0x1223


/* table of devices that work with this driver */
static struct usb_device_id gfb_usb_id_table [] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { },
};
MODULE_DEVICE_TABLE (usb, gfb_usb_id_table);


static int gfb_usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "gfb_usb_probe");

    //struct usb_device *udev = interface_to_usbdev(interface);
    //struct usb_led *dev = NULL;
    //int retval = -ENOMEM;

    //dev = kmalloc(sizeof(struct usb_led), GFP_KERNEL);
    //if (dev == NULL) {
    //    dev_err(&interface->dev, "Out of memory\n");
    //    goto error;
    //}
    //memset (dev, 0x00, sizeof (*dev));

    //dev->udev = usb_get_dev(udev);

    //usb_set_intfdata (interface, dev);

    //device_create_file(&interface->dev, &dev_attr_blue);
    //device_create_file(&interface->dev, &dev_attr_red);
    //device_create_file(&interface->dev, &dev_attr_green);

    //dev_info(&interface->dev, "USB LED device now attached\n");
    return 0;

//    error:
    //kfree(dev);
    //return retval;
}

static void gfb_usb_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "gfb_usb_disconnect");

    //struct usb_led *dev;

    //dev = usb_get_intfdata (interface);
    usb_set_intfdata (interface, NULL);

    //device_remove_file(&interface->dev, &dev_attr_blue);
    //device_remove_file(&interface->dev, &dev_attr_red);
    //device_remove_file(&interface->dev, &dev_attr_green);

    //usb_put_dev(dev->udev);

    //kfree(dev);

    //dev_info(&interface->dev, "USB LED now disconnected\n");
}

static struct usb_driver gfb_usb_driver = {
    .name        = "gfb_usb_driver",
    .probe       = gfb_usb_probe,
    .disconnect  = gfb_usb_disconnect,
    .id_table    = gfb_usb_id_table,
};

static int __init gfb_usb_init(void)
{
    int result;

    /* register this driver with the USB subsystem */
    result = usb_register(&gfb_usb_driver);
    if (result < 0) {
        printk(KERN_ERR "gfb_usb_driver failed for the "__FILE__ "driver. Error number "+ result);
        return -1;
    }

    printk(KERN_INFO "gfb_usb_init");

    return 0;
}

static void __exit gfb_usb_exit(void)
{
    /* deregister this driver with the USB subsystem */
    usb_deregister(&gfb_usb_driver);

    printk(KERN_INFO "gfb_usb_exit");
}

module_init(gfb_usb_init);
module_exit(gfb_usb_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");
