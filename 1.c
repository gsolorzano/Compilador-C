#define A 2
#define B 8 + A

int print1 (int argc, char* argv[]) {
	print("%d", B)
}

#define A 6

int print2 (int argc, char* argv[]) {
	print("%d", B)
}

#define B 99

int print2 (int argc, char* argv[]) {
	print("%d", B)
}

#define B ejemplo+3

int print2 (int argc, char* argv[]) {
	print("%d", B)
}

#define B

int print2 (int argc, char* argv[]) {
	print("%d", B)
}

#define A B+2
#define B A+3

int print2 (int argc, char* argv[]) {
	print("%d", B)
}
