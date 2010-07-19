CFLAGS = `allegro-config --cflags`
LDFLAGS = `allegro-config --libs`

tetris: main.cpp image.cpp tetrad.cpp tetris.cpp tilemap.cpp
	g++ $(CFLAGS) $(LDFLAGS) -o $@ $?

clean:
	rm tetris *~
