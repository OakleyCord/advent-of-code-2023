all: one two

one: src/challenge_one.c
	mkdir -p builds
	gcc src/challenge_one.c -o builds/one
	./builds/one
	
two: src/challenge_two.c
	mkdir -p builds
	gcc src/challenge_two.c -o builds/two
	./builds/two


clean:
	rm -rf builds
