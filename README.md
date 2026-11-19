# ~~~ANIX~~~

My OS/kernel 😃😃😃

> Age doesn't matter

## What is Anix?

ANIX is an operating system designed to do nothing (Tadaaaaaaaa). It was developed by Mflight248 in 2026 and has been on this earth for approximately 0 years.

## What can you do with Anix?

<ul>
&#x20; <li>Open it</li>
&#x20; <li>Stare at it</li>
&#x20; <li>Use it + your monitor as a leg rest</li>
&#x20; <li>Sit on it (Not a good idea )</li>
&#x20; <li>Turn it off via a button or switch</li>
&#x20; <li>Stare at it (I just said that, didn't I)</li>
</ul>

So... That sounds easier, right? Well, there could be security flaws, right? So, if you want to run it, you can't just press the play button and run this in, say VSCode. This next part will help you run this on Windows and Linux (MacOS I don't know) :P

## Installation

OSs are made up of 3 languages, C (or any other low-level language like C++, Rust or even <b>ASSEMBLY 😫</b>), Assembly, and Linker Script. If you have experience with 3rd Party Compilers, you know that you might need to use a CLI (Command Line Interfearence). The things that you need are:

<ul>
&#x20; <li>GCC</li>
&#x20; <li>NASM</li>
&#x20; <li>QEMU</li>
&#x20; <li>LD</li>
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

In Linux, you have more support to dev stuff, and this will be great for this project! <i>Miss out the steps for wsl --install for the <a href = [https://github.com/mflight248-hub/ANIX/edit/main/README.md#windows>Windows](https://github.com/mflight248-hub/ANIX/edit/main/README.md#windows>Windows)</a> section and run the compiling and QEMU code.</i>

## Alternative for WSL and Linux

If you want to run this in a VM or even run this on a real computer, you will need:

<ul>   <li>a .iso file</li>   <li>Xorriso</li>   <li>A brain</li> </ul>  First, you have to make the folder structure that Xorriso will be in:

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
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

###### Go

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

###### Scroll up!

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br>

###### You can't see the secret message!
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

###### Ok, then, if you insist:

<br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br>
<br>
<br>
<br>

Use this secret command:

```text
make
```

or, to clean it,

```text
make clean
```

Want to test it? Use:

```text
make qemu
```

Here you are, the secret commands, shhhhh 🤫🤐
