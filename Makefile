
SDL_INCLUDE=/usr/local/include
SDL_LIBDIR=-L/usr/local/lib
SDL_LIBS=-lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
IDIR =include -I$(SDL_INCLUDE)
CC=g++
CFLAGS=-I$(IDIR)

ODIR =obj
LDIR =-Llib $(SDL_LIBDIR)
SRCDIR =src
LIBS = $(SDL_LIBS)
EXECUTABLE =blocky


all: $(EXECUTABLE)

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LDIR)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

list:
	@grep '^[^#[:space:]].*:' Makefile
