#include <stdio.h>

#include "safeEscape.h"

int
main (int argc, const char ** argv)
{
    int i;

    char dest[100];
    char * testcases[] = {
        "\"double quotes\"",
        "'single quotes'",
        "<angle brackets>",
        "This & that",
        "\\r\\n",
    };
    
    for (i = 0; i < sizeof(testcases) / sizeof(testcases[0]); i++) {
        safeEscape(testcases[i], dest, sizeof(dest));
        printf("%s\n", dest);
    }
}
