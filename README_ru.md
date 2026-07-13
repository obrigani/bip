bip (Bip Is Perfect)
=====
<p align="center"><img src="https://codeberg.org/avatars/c27cbd84e131f2d7ef5d8a017371211d0d8c7d002a4380182f4dfe8dd32dd702"></p>
<p align="center"><sub>Я хотел вставить сюда крутой банер, но пока здесь будет Кит</sub></p>

<p align="center">
  <a href="https://codeberg.org/obrigani/bip"><img src="https://img.shields.io/badge/codeberg-repo-blue?style=for-the-badge&logo=codeberg&logoColor=white" alt="Codeberg Repo"></a>
  <a href="https://github.com/obrigani/bip"><img src="https://img.shields.io/badge/github-repo-black?style=for-the-badge&logo=github" alt="Github Mirror"></a>
  <a href="https://www.gnu.org/licenses/gpl-3.0.txt"><img src="https://img.shields.io/badge/license-gplv3.0--only-%23BD0000?style=for-the-badge" alt="Licensed under GPLv3.0-only"></a>
</p>

## Чем именно является bip?
Bip (произносится как бип) это кусок запускаемого двоичного кода, пытающийся казаться операционной системой. На данный момент он поддерживает 32-битные BIOS системы
## Почему она называется bip
1. Произносится также, как **смешной компьютерный звук**
2. Bip это [рекурсивный акроним](https://ru.wikipedia.org/wiki/%D0%A0%D0%B5%D0%BA%D1%83%D1%80%D1%81%D0%B8%D0%B2%D0%BD%D1%8B%D0%B9_%D0%B0%D0%BA%D1%80%D0%BE%D0%BD%D0%B8%D0%BC) (Bip Is Perfect) (Bip идеален)
3. "Bip идеален" из-за того, что всё другое ПО которое я делал имело самокритичные названия, так-что я решил что мне надо быть более позитивным в данном вопросе во имя разнообразия.
## Как мне запустить эту штуку?
### Windows
Удачи тебе страдать с WSL, дружок. Есть люди которые програмируют операционные системы на Windows, но я не являюсь одним из них, так что я не знаю как запустить её там. Лучшее что я могу сделать это дать [эту ссылку](https://wiki.osdev.org/GCC_Cross-Compiler#Windows_Users) на статью о компилировании кросс-компилятора, В которой присутсвуют некоторые специфики о Windows.
### Linux / UNIXо-подобные (FreeBSD, OpenBSD, MacOS)
#### Необходимые программы
1. [i686-elf gcc кросс-компилятор](https://wiki.osdev.org/GCC_Cross-Compiler) (наряду с кросс-компилированными версиями ```as``` и ```ld```)
2. GNU Make (99.98% уверен что сойдет и BSD Make но я это не проверял)
3. Bourne Again Shell (```bash```)
4. ```xorriso```, ```gzip```, ```curl``` и ```tar``` для Limine версии
5. Пакет GRUB с ```grub-mkrescue``` для GRUB версии
6. QEMU для запуска образа ОС
#### Процесс компиляции
Надо просто запустить ```make all``` в корневой директории проекта для создания основного образа или же ```make all-grub``` для образа с GRUB. ```make run``` запускает образ в QEMU (```make run-grub``` для запуска GRUB образа)
## Разработка
Если вы получаете "Use a cross-compiler, dumbass" ошибку в своем IDE / текстовом редакторе но не в коммандной строке, и вы изпользуетет ```clangd``` в качестве LSP, запустите ```bear -- make``` в директории ядра (перед этим надо установить [Bear](https://github.com/rizsotto/Bear))
