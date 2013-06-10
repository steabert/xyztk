# files
EXE = xyztk-translate.exe \
	  xyztk-rotate.exe \
	  xyztk-scale.exe \
	  xyztk-strip.exe
OBJ = xyztk-label.o \
	  xyztk-molecule.o \
	  xyztk-quat.o \

# environment
LIB = -largtable2 -lm

# compiler options
CFLAGS = -O2 -Wall

# rules
%.o: %.c
	$(CC) -c $<

%.exe: %.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $< $(OBJ) $(LIB) $(LIB_ARG)

# build targets
default: $(EXE)

.PHONY: clean
clean:
	rm $(EXE)
