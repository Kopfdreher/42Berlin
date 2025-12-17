#include <string.h>
#include "libft.h"

/* --- Print Helper --- */
void print_strarr(char **arr, char *name)
{
    printf("--- %s ---\n", name);
    if (!arr)
    {
        printf("(NULL)\n\n");
        return;
    }
    int i = 0;
    while (arr[i])
    {
        printf("[%d]: %s\n", i, arr[i]);
        i++;
    }
    printf("Length: %zu\n\n", ft_strarrlen((const char **)arr));
}

int main(void)
{
    printf("===== TESTING FT_STRARR HELPERS =====\n\n");

    // TEST 1: Normal Case
    const char *original[] = {
        "Hello",
        "World",
        "42",
        "Berlin",
        NULL
    };

    printf("1. Testing Normal Copy...\n");
    char **copy = ft_strarrcpy(original);
    
    print_strarr((char **)original, "Original");
    print_strarr(copy, "Copy");

    // Verify Deep Copy (Change copy, ensure original stays same)
    printf(">> Modifying copy[1] to 'Universe'...\n");
    free(copy[1]); 
    copy[1] = strdup("Universe"); // Using standard strdup for test convenience

    printf("Original[1]: %s (Should be 'World')\n", original[1]);
    printf("Copy[1]:     %s (Should be 'Universe')\n", copy[1]);
    
    if (strcmp(original[1], "World") == 0)
        printf("\033[0;32m[OK] Deep copy successful.\033[0m\n\n");
    else
        printf("\033[0;31m[FAIL] Shallow copy detected!\033[0m\n\n");

    free_strarr(copy);

    // TEST 2: Empty Array (Just NULL)
    printf("2. Testing Empty Array...\n");
    const char *empty[] = { NULL };
    char **empty_copy = ft_strarrcpy(empty);
    
    if (empty_copy && empty_copy[0] == NULL)
        printf("\033[0;32m[OK] Empty array copied correctly.\033[0m\n");
    else
        printf("\033[0;31m[FAIL] Empty array copy failed.\033[0m\n");
    
    printf("Length of empty: %zu (Expected: 0)\n\n", ft_strarrlen((const char **)empty_copy));
    free_strarr(empty_copy);

    return (0);
}
