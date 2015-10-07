BINARIES = tokenize.tpc parse.tpc encode.tpc py2bc.tpc example.py

.PHONY: all clean

all: tinypy

clean:
	rm -rf tinypy *.tpc *.pyc *.o

%.tpc: %.py
	python2 py2bc.py "$<" "$@" -nopos

%.o: %.c
	gcc -Os -c -o "$@" "$<"

tinypy: tpmain.o $(BINARIES)
	gcc -s -Os -o "$@" -Wl,--format=binary $(BINARIES) -Wl,--format=default "$<" -lm
