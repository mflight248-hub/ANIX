# ~~~ANIX~~~ #
My OS/kernel 😃😃😃
Anix is a to-be somewhat functional OS made by mflight. The goal is "Age doesn't matter" and MFlight wants to accomplish making an OS, being 9. the operating system will help users function the terminal as a middle-man between Windows, which looks like this:

```text
[any program, whatever] --install
```               

Then Linux, which, in Debian-based distros, is this:
```text
sudo apt-get install [any program] or sudo apt install [any program]
```

Then in Fedora:
```text
sudo dnf install [A program]
```

Then Arch:
```text
sudo pacman -S [A program]
```

Then SUSE:
```text
sudo zypper install [Program(LMMS???)]
```

So, MFlight wants to make it universal, so you can do all of the above. For now, ANIX is focused on Linux. Windows support may come later.


So... That sounds easier, right? Well, there could be security flaws, right? So, if you want to run it, you can't just press the play button and run this in, say VSCode. This next part will help you run this on Windows and Linux (MacOS I don't know) :P

## Installation

OSs are made up of 3 languages, C (or any other low-level language like C++, Rust or even <b>ASSEMBLY 😫</b>), Assembly, and Linker Script. If you have experience with 3rd Party Compilers, you know that you might need to use a CLI (Command Line Interfearence). The things that you need are:
<ul>
  <li>GCC</li>
  <li>NASM</li>
  <li>QEMU</li>
  <li>LD</li>
</ul>

## Windows

Windows is worser then Linux, and unless you are using a Surface laptop like me, you can switch to Linux easily. First, you will need to install WSL (Windows Subsystem for Linux). This can be done with: 
```text
wsl --install
```
Then reboot.

After that, you can use NASM to compile the .asm bootloader with:
```text
nasm -f elf32 boot.asm -o boot.o
```
Then, you can compile the main.c file using:
```text
gcc -m32 -c main.c -o main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
```
Now, link them together with LD:
```text
gcc -T linker.ld -o my_kernel.bin -ffreestanding -O2 -nostdlib boot.o main.o
```
And finally, run with QEMU:
```text
qemu-system-i386 -kernel my_kernel.bin
```

And enjoy using this in the QEMU window!  

## Linux

In Linux, you have more support to dev stuff, and this will be great for this project! <i>Miss out the steps for wsl --install for the <a href = https://github.com/mflight248-hub/ANIX/edit/main/README.md#windows>Windows</a> section and run the compiling and QEMU code.</i>

## Alternative for WSL and Linux
                                                                                                                                                                                            
If you want to run this in a VM or even run this on a real computer, you will need:
<ul>
  <li>a .iso file</li>
  <li>Xorriso</li>
  <li>A brain</li>
</ul>
 First, you have to make the folder structure that Xorriso will be in:
 
 ```text
 mkdir -p iso_root/boot/grub
 ```
Then, you have to move your newly linked kernel.bin into that directory:

```text
cp kernel.bin iso_root/boot/
```
Now, you can create the text file iso_root/boot/grub/grub.cfg so the CD knows what to do when it boots up:

```text
nano iso_root/boot/grub/grub.cfg
```

In there, you can add this code:

```text
menuentry "My OS" {
    multiboot /boot/kernel.bin
    boot
}
```

You can finally create the .iso file with:

```text
grub-mkrescue -o anix.iso iso_root
```

Then check your ANIX folder (eg: C:/users/superman/ANIX) and add the .iso file to the VM that you are using, no CLI, just GUI!!!

<hr>

Well that is it for the README.md file, I hope you didn't have the pain I had, and bye!!! 😃😃😃


 
