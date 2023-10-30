# 42cursus_get_next_line
The get next line project challenges us to make a function capable of returning the next line of a file descriptor passed as a parameter. Each time the function is called, it reads with a buffer size that can be specified when compiling the files using `-D BUFFER_SIZE=n`. This project is also good for understanding the use of static variables. Once get_next_line() is finished, we can include it in the libft and use it when allowed.

![C](https://img.shields.io/badge/C-a?style=for-the-badge&logo=C&color=grey)

You can see the subject [**HERE**](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/gnl_subject_en.pdf)

## Example Usage
Example usage once our get_next_line function is included in our libft:
```C
#include "libft.h"

int main(void)
{
    int  fd = open("example.txt", O_RDONLY);
    int  lines = 1;
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d -> %s\n", lines++, line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/norm_en.pdf), the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.
