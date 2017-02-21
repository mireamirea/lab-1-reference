#include <stdio.h>

struct package {
	int x;
	char c[255];
	float f;
};

#define AHAHAFAIL -1

int main(void) {
	struct package p;
	FILE *f;
	if (!(f = fopen("data.dat", "rb"))) { /* data.dat is a binary file, hence r_b_ mode */
		return AHAHAFAIL;
	}
	int i = 0;
	while(fread(&p, sizeof(struct package), 1, f)) { /* fread(&where_to, how_much, how_many_chunks, where_from) */
		printf("| %d | %s | %f |\n", p.x, p.c, p.f); 
		i++;
	}

	fclose(f); /* discard after use ;-) */
	return 0;
}