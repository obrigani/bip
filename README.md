bip (Bip Is Perfect)
=====
<p align="center"><img src="https://codeberg.org/avatars/c27cbd84e131f2d7ef5d8a017371211d0d8c7d002a4380182f4dfe8dd32dd702"></p>
<p align="center"><sub>I wanted a cool banner here but Keith will be there in its place for now</sub></p>

<p align="center">
  <a href="https://codeberg.org/obrigani/bip"><img src="https://img.shields.io/badge/codeberg-repo-blue?style=for-the-badge&logo=codeberg&logoColor=white" alt="Codeberg Repo"></a>
  <a href="https://github.com/obrigani/bip"><img src="https://img.shields.io/badge/github-repo-black?style=for-the-badge&logo=github" alt="Github Mirror"></a>
  <a href="https://www.gnu.org/licenses/gpl-3.0.txt"><img src="https://img.shields.io/badge/license-gplv3.0--only-%23BD0000?style=for-the-badge
" alt="Licensed under GPLv3.0-only"></a>
</p>

## What exactly is bip?
Bip (pronounced as beep) is a piece of executable binary code larping as an operating system. Currently it supports running on 32-bit BIOS machines.
## Why is it called bip
1. It's pronounced the same as the funny computer noise
2. It's a [recursive acronym](https://en.wikipedia.org/wiki/Recursive_acronym) (Bip Is Perfect)
3. Bip Is Perfect because all the other software that I made had self-critical titles, so I thought that I should be positive for once when naming things
## How can I run this thing?
### Windows
You are screwed, buddy, good luck strugling with WSL. There are people developing operating systems on Windows, but I'm not one of them so I genuenly don't know how to run it there. The best I can do is give [this link](https://wiki.osdev.org/GCC_Cross-Compiler#Windows_Users) to the article about building a GCC cross-compiler, which has some specifics about Windows.
### Linux / UNIX-like (FreeBSD, OpenBSD, MacOS)
#### Required software
1. [i686-elf gcc cross-compiler](https://wiki.osdev.org/GCC_Cross-Compiler) (as well as crosscompiled versions of ```as``` and ```ld```)
2. GNU Make (99.98% that BSD Make will work too but I haven't tested it)
3. Bourne Again Shell (```bash```)
4. ```xorriso```, ```gzip```, ```curl``` and ```tar``` for the Limine version
5. GRUB package with ```grub-mkrescue``` for the GRUB version
6. QEMU in order to run the image
#### Build process
Just run ```make all``` in the project root to build the default iso or run ```make all-grub``` for the GRUB one. ```make run``` boots up the image in QEMU (```make run-grub``` to run the GRUB image)
## Development
If you get the "Use a cross-compiler, dumbass" error in your IDE / Text editor but not in the command line, and you use ```clangd``` as your LSP, run ```bear -- make``` in the kernel directory (you need to have [Bear](https://github.com/rizsotto/Bear) installed)
