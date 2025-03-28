#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"
#include "debug.h"
#include "hash.h"
#include "hex_dump.h"
#include "limits.h"
#include "list.h"
#include "round.h"

int string_split(char *str, char argv[10][30]);

int main()
{
    int argc;
    char input[110], argv[10][30] = {};
    struct list **main_list = (struct list **)calloc(15, sizeof(struct list *));
    struct hash **main_hash = (struct hash **)calloc(15, sizeof(struct hash *));

    while (fgets(input, 110, stdin) != NULL)
    {
        argc = string_split(input, argv);

        if (!strcmp(argv[0], "quit"))
            break;

        if (!strncmp(argv[0], "list", 4) || !strncmp(argv[1], "list", 4))
        {
            if (!strcmp(argv[0], "create"))
            {
                create_list(main_list, argv[2]);
            }
            else if (!strcmp(argv[0], "delete"))
            {
                delete_list(main_list, argv[1]);
            }
            else if (!strcmp(argv[0], "dumpdata"))
            {
                dumpdata_list(main_list, argv[1]);
            }

            else if (!strcmp(argv[0], "list_push_front"))
            {
                insert_elem_list(main_list, argv[1], 0, atoi(argv[2]));
            }
            else if (!strcmp(argv[0], "list_push_back"))
            {
                insert_elem_list(main_list, argv[1], -1, atoi(argv[2]));
            }
            else if (!strcmp(argv[0], "list_insert"))
            {
                insert_elem_list(main_list, argv[1], atoi(argv[2]), atoi(argv[3]));
            }
            else if (!strcmp(argv[0], "list_insert_ordered"))
            {
                ordered_insert_elem_list(main_list, argv[1], atoi(argv[2]));
            }

            else if (!strcmp(argv[0], "list_pop_front"))
            {
                remove_elem_list(main_list, argv[1], 0);
            }
            else if (!strcmp(argv[0], "list_pop_back"))
            {
                remove_elem_list(main_list, argv[1], -1);
            }
            else if (!strcmp(argv[0], "list_remove"))
            {
                remove_elem_list(main_list, argv[1], atoi(argv[2]));
            }

            else if (!strcmp(argv[0], "list_max"))
            {
                print_max_elem_list(main_list, argv[1]);
            }
            else if (!strcmp(argv[0], "list_min"))
            {
                print_min_elem_list(main_list, argv[1]);
            }
            else if (!strcmp(argv[0], "list_size"))
            {
                printf("%zu\n", list_size(main_list[atoi(argv[1] + 4)]));
            }
            else if (!strcmp(argv[0], "list_empty"))
            {
                if (list_empty(main_list[atoi(argv[1] + 4)]))
                    printf("true\n");
                else
                    printf("false\n");
            }

            else if (!strcmp(argv[0], "list_reverse"))
            {
                list_reverse(main_list[atoi(argv[1] + 4)]);
            }
            else if (!strcmp(argv[0], "list_shuffle"))
            {
                shuffle_list(main_list, argv[1]);
            }
            else if (!strcmp(argv[0], "list_sort"))
            {
                list_sort(main_list[atoi(argv[1] + 4)], less, NULL);
            }
            else if (!strcmp(argv[0], "list_splice"))
            {
                splice_list(main_list[atoi(argv[1] + 4)], main_list[atoi(argv[3] + 4)], atoi(argv[2]), atoi(argv[4]), atoi(argv[5]));
            }
            else if (!strcmp(argv[0], "list_swap"))
            {
                swap_list(main_list, argv[1], atoi(argv[2]), atoi(argv[3]));
            }
            else if (!strcmp(argv[0], "list_unique"))
            {
                if (argc == 2)
                    list_unique(main_list[atoi(argv[1] + 4)], NULL, less, NULL);
                else
                    list_unique(main_list[atoi(argv[1] + 4)], main_list[atoi(argv[2] + 4)], less, NULL);
            }
        }

        else if (!strncmp(argv[0], "hash", 4) || !strncmp(argv[1], "hash", 4))
        {
            if (!strcmp(argv[0], "create"))
            {
                create_hash(main_hash, argv[2]);
            }
            else if (!strcmp(argv[0], "delete"))
            {
                delete_hash(main_hash, argv[1]);
            }
            else if (!strcmp(argv[0], "dumpdata"))
            {
                dumpdata_hash(main_hash, argv[1]);
            }

            else if (!strcmp(argv[0], "hash_insert"))
            {
                hash_insert(main_hash[atoi(argv[1] + 4)], new_elem(atoi(argv[2])));
            }
            else if (!strcmp(argv[0], "hash_delete"))
            {
                hash_delete(main_hash[atoi(argv[1] + 4)], new_elem(atoi(argv[2])));
            }
            else if (!strcmp(argv[0], "hash_empty"))
            {
                if (hash_empty(main_hash[atoi(argv[1] + 4)]))
                    printf("true\n");
                else
                    printf("false\n");
            }
            else if (!strcmp(argv[0], "hash_size"))
            {
                printf("%zu\n", hash_size(main_hash[atoi(argv[1] + 4)]));
            }
            else if (!strcmp(argv[0], "hash_clear"))
            {
                hash_clear(main_hash[atoi(argv[1] + 4)], hash_destruct);
            }

            else if (!strcmp(argv[0], "hash_apply"))
            {
                if (!strcmp(argv[2], "square"))
                    apply_hash(main_hash, argv[1], 0);
                else
                    apply_hash(main_hash, argv[1], 1);
            }
            else if (!strcmp(argv[0], "hash_find"))
            {
                if (hash_find(main_hash[atoi(argv[1] + 4)], new_elem(atoi(argv[2]))))
                    printf("%d\n", atoi(argv[2]));
            }
            else if (!strcmp(argv[0], "hash_replace"))
            {
                hash_replace(main_hash[atoi(argv[1] + 4)], new_elem(atoi(argv[2])));
            }
        }
    }

    return 0;
}

int string_split(char *str, char argv[10][30])
{
    int word = 0, index = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ' && str[i] != '\n')
            argv[word][index++] = str[i];
        else
        {
            argv[word][index] = '\0';
            word++;
            index = 0;
        }
    }

    return word;
}