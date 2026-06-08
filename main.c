#include <stdio.h>
#include <string.h>
#include "translator.h"
#include "history.h"

int main(void) {
    init_translator();
    history_init();

    int choice = 0;

    while (1) {
        printf("\n=== LANGUAGE TRANSLATOR ===\n");
        printf("1. Translate\n");
        printf("2. View History\n");
        printf("3. Clear History\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            print_language_menu();
            printf("> ");
            int lang;
            scanf("%d", &lang);
            getchar();

            if (lang < 1 || lang > 16) {
                printf("Invalid choice.\n");
                continue;
            }

            printf("Enter English text: ");
            char input[512];
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;

            char output[512];
            Language target = parse_language(lang);
            translate_sentence(input, target, output);

            printf("\nOriginal   : %s\n", input);
            printf("Language   : %s\n", language_name(target));
            printf("Translation: %s\n", output);

            history_add(input, output, language_name(target));

        } else if (choice == 2) {
            history_print();
        } else if (choice == 3) {
            history_clear();
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
    }
    return 0;
}
