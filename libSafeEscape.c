#include <stdio.h>

#define ESC_DOUBLE_QUOTE "&quot;"
#define ESC_SINGLE_QUOTE "&apos;"
#define ESC_LESS_THAN    "&lt;"
#define ESC_GREATER_THAN "&gt;"
#define ESC_AMPERSAND    "&amp;"
#define ESC_BACKSLASH    "&bsol;"

int
safeEscape (const char * src, char * dest, size_t destSz)
{
    int n = 0;
    int trunc = 0;
    for ( ; (!trunc) && src ; src++) {
        switch (*src) {
        case '"':
            if (n + sizeof(ESC_DOUBLE_QUOTE) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_DOUBLE_QUOTE);
            break;
        case '\'':
            if (n + sizeof(ESC_SINGLE_QUOTE) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_SINGLE_QUOTE);
            break;
        case '<':
            if (n + sizeof(ESC_LESS_THAN) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_LESS_THAN);
            break;
        case '>':
            if (n + sizeof(ESC_GREATER_THAN) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_GREATER_THAN);
            break;
        case '&':
            if (n + sizeof(ESC_AMPERSAND) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_AMPERSAND);
            break;
        case '\\':
            if (n + sizeof(ESC_BACKSLASH) + 1 > destSz) {
                trunc = 1;
                break;
            }
            n += snprintf(dest + n, destSz - n, "%s", ESC_BACKSLASH);
            break;
        default:
            if (n + 2 > destSz) {
                trunc = 1;
                break;
            }
            *(dest + n) = *src;
            n++;
        }
    }

    *(dest + n) = '\0';
    return 0;
}
