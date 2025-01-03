#include <dirent.h>
#include <stdio.h>

int my_double_ls(const char* name) {
	struct dirent *d;
	DIR *dp;
	
	if ((dp = opendir(name)) == NULL)
		return -1;

	while (d = readdir(dp)) {
		if (d->d_ino != 0)
			printf("%s\n", d->d_name);
	}

	rewinddir(dp);

	while (d = readdir(dp)) {
		if (d->d_ino != 0)
			printf("%s\n", d->d_name);
	}

	closedir(dp);

	return 0;
}

int main(void) {
	int dent;	
	dent = my_double_ls("test");
       	
	printf("%d\n", dent);	

	return 0;
}
