#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>

#define GROOT "I am Groot\n"

static ssize_t groot_read(struct file *file, char *buf, size_t count, loff_t *ppos) {
	int length = 0;
	char *groot_str = NULL;

	groot_str = GROOT;
	length = (int)strlen(groot_str);

	if (count < length) {
		return -EINVAL;
	}

	if (*ppos != 0) {
		return 0;
	}

	if (copy_to_user(buf, groot_str, length)) {
		return -EINVAL;
	}

	*ppos = length;

	return length;
}

static const struct file_operations groot_fops = {
	.owner = THIS_MODULE,
	.read  = groot_read
};

static struct miscdevice groot_dev = {
	MISC_DYNAMIC_MINOR,
	"groot",
	&groot_fops
};

static int __init groot_init(void) {
	int ret = 0;

	ret = misc_register(&groot_dev);

	if (ret) {
		printk(KERN_ERR "Unable to register \"Groot\" misc device\n");
	}

	return ret;
}

module_init(groot_init);

static void __exit groot_exit(void) {
	misc_deregister(&groot_dev);
}

module_exit(groot_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Selwyn <kevinselwyn@gmail.com>");
MODULE_DESCRIPTION("I am Groot");
MODULE_VERSION("dev");