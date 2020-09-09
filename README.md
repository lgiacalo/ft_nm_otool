# Nm-otool

> Let's analyze the format of MacOS executables and understand how the kernel launches the binaries, by rewriting these two system tools. Essential for all those who want to make security, this project is more generally an opening on the UNIX culture system.

This is the second project of the Advanced Unix branch at School 42 Paris

---
Project
------------

Re write the programs `nm` and `otool -t`.

Display the symbols of an object file, a binary, an archive and a dynamic library.

The programs can handle the architectures 32 and 64 bits.

---
Installation
------------
Run `make fclean && make`

## Usage

### NM

To run the program: `ft_nm [options] [file_name ...]`

Some options are available for the nm program:

	-g     Display only global (external) symbols.
	-j     Just display the symbol names (no value or type).
	-u     Display only undefined symbols.
	-U     Don't display undefined symbols.
	-r	   Sort in reverse order (alphabetically by default)
	-a	   Display all arch


### OTOOL

To run the program: `ft_otool [options] [file_name ...]`

Some options are available for the nm program:

	-t	    Print the text section
	-d		Print the data section
	-m		Display like print memory

## Example
```
> ./ft_nm tests/test_facile
0000000100000000 T __mh_execute_header
0000000100000f60 T _main
                 U _puts
                 U dyld_stub_binder
```

```
> ./ft_otool tests/test_facile
tests/test_facile:
Contents of (__TEXT,__text) section
0000000100000f60	55 48 89 e5 48 83 ec 10 48 8d 3d 3b 00 00 00 c7
0000000100000f70	45 fc 00 00 00 00 e8 0d 00 00 00 31 c9 89 45 f8
0000000100000f80	89 c8 48 83 c4 10 5d c3
```


### DOC
- [mach-o/loader.h](https://opensource.apple.com/source/xnu/xnu-792/EXTERNAL_HEADERS/mach-o/loader.h)
- [mach-o/ar.h](https://opensource.apple.com/source/xnu/xnu-1228/EXTERNAL_HEADERS/ar.h.auto.html)
- [mach-o/n-list.h](https://opensource.apple.com/source/xnu/xnu-201/EXTERNAL_HEADERS/mach-o/nlist.h.auto.html)
- [mach-o/fat.h](https://opensource.apple.com/source/xnu/xnu-344/EXTERNAL_HEADERS/mach-o/fat.h)
- [mach-o/machine.h](https://opensource.apple.com/source/xnu/xnu-4570.41.2/osfmk/mach/machine.h.auto.html)
- [OS X ABI Mach-O File Format Reference](https://github.com/aidansteele/osx-abi-macho-file-format-reference)


