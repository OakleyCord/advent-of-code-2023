all: one two two_p2

one: src/challenge_one.c
	mkdir -p builds
	gcc src/challenge_one.c -o builds/one
	./builds/one
	
two: src/challenge_two.c
	mkdir -p builds
	gcc src/challenge_two.c -o builds/two
	./builds/two

two_p2: src/challenge_two_p2.c
	mkdir -p builds
	gcc src/challenge_two_p2.c -o builds/two_p2
	./builds/two_p2

clean:
	rm -rf builds
