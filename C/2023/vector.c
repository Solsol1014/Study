#include <stdio.h>
#include <stdlib.h>

char* createvector() {
	char* vec;

	vec = (char *)calloc(6, sizeof(char));

	vec[0] = 6;

	return vec;
}

void putvector(char* vec, char c) {

	int i;
	for (i=1;i<vec[0];i++)
	{
		if(vec[i]==NULL)
			break;
	}

	if (i==vec[0])
	{
		vec = (char*)realloc(vec, vec[0]+5);

		vec[0] = vec[0]+5;
		vec[i] = c;
	}
	else
		vec[i] = c;

}

int main(void) {

    char* vec;

    vec = createvector();

    putvector(vec, 'c');
    putvector(vec, 'O');
    putvector(vec, 'O');
    putvector(vec, 'O');
    putvector(vec, 'O');

    putvector(vec, '9');

    printf("%c", vec[6]);
    
    return 0;
}