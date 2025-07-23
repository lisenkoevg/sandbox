all: prog_nolib prog_lib prog_lib2 prog_shared libdemo.so

prog_nolib: prog.c mod1.c mod2.c
	gcc -g -c prog.c mod1.c mod2.c
	gcc -g -o prog_nolib prog.o mod1.o mod2.o
	objdump -x $@ > $@.objdump

prog_lib: prog.o libdemo.a
	gcc -g -o $@ $?
	objdump -x $@ > $@.objdump

prog_lib2: prog.o libdemo.a
	gcc -g -o $@ $< -L. -ldemo
	objdump -x $@ > $@.objdump

prog_shared: prog.o libdemo.so
	gcc -g -Wall -o $@ $?

libdemo.a: mod1.o mod2.o
	ar r $@ $?

libdemo.so: mod1.c mod2.c
	gcc -g -c -fPIC -Wall -Wextra mod1.c mod2.c
	gcc -g -shared -Wl,-soname,libfoo.so -o $@ mod1.o mod2.o
	ln -s libdemo.so libfoo.so

%.o: %.c
	gcc -g -c -o $@ $?

clean:
	@rm -rf *.o *.exe *.a *.so *.objdump
	@for f in $$(find -executable); do \
      if $$(file $$f | grep -Pqs "ELF.*executable"); then \
        rm $$f; \
      fi \
    done

.PHONY: clean
