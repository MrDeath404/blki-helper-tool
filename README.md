# Information about tool
- Tool to help user download and manage BlackIron Project ROM for Nothing Phone (2).

# Warning
- Read below information before using bootloader locking option.

# What is bootloader ?
- Bootloader is the frist program that starts with cpu boots
- The main goal of bootloader is to load system images that have valid root of trust, otherwise the phone will displace that the system has been corrupted

# Why you need to unlock bootloader ?
- When bootloader is locked you are not able to flash/boot any other operating system that doesn't have valid root of trust.

# Why you may want to relock bootloader ?
- The main reason is when the bootloader is lock no one is allowed to format or change operating system on your phone, so simplest answer is to protect your data.

# What not to do when your bootloader is locked ?
- Simple do not touch any partition, apply update only by this tool or OTA updates

# What can happend when I do something wrong ?
- When you will modify any partition your phone won't boot and if you will disable posibility of unlocking bootloader you won't be able to use your phone anymore.
- If you will leave OEM unlocking alone (on) only what you will lost when something bad will happend is your data.
- DO NOT TOUCH ANY PARTITION !!!
- And an exmple when the partition is touched: while updating KernelSU Next, installing suspicious modules that editing (flashing) partitions
