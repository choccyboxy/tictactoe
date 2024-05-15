all: src/main.c
	rm -r build/
	@echo "Removed old build files"
	mkdir build/
	gcc src/main.c src/game.c src/computer.c -o build/main
	@echo "Built project"

build:
	mkdir build/
	gcc src/main.c src/game.c src/computer.c -o build/main
	@echo "Built project"

clean:
	rm -r build/
	@echo "Removed old build files"