#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "translator.h"
#include "history.h"

// ─────────────────────────────────────────────
//  UI helpers
// ─────────────────────────────────────────────
static void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void print_banner(void) {
    printf("\n");
    printf("  ╔══════════════════════════════════════════════════════╗\n");
    printf("  ║         MINI UNIX SHELL — LANGUAGE TRANSLATOR        ║\n");
    printf("  ║          Advanced C Programming Project              ║\n");
    printf("  ╚══════════════════════════════════════════════════════╝\n");
    printf("\n");
}

static void print_main_menu(void) {
    printf("  ┌──────────────────────────────┐\n");
    printf("  │           MAIN MENU          │\n");
    printf("  ├──────────────────────────────┤\n");
    printf("  │  [1]  Translate text         │\n");
    printf("  │  [2]  View history           │\n");
    printf("  │  [3]  Clear history          │\n");
    printf("  │  [4]  Help                   │\n");
    printf("  │  [5]  Exit                   │\n");
    printf("  └──────────────────────────────┘\n");
    printf("\n  > ");
}

static void print_help(void) {
    printf("\n");
    printf("  ┌─────────────────────────────────────────────────────────┐\n");
    printf("  │                        HELP                             │\n");
    printf("  ├─────────────────────────────────────────────────────────┤\n");
    printf("  │  This program translates English text into:             │\n");
    printf("  │    Spanish, French, German, Turkish, Arabic             │\n");
    printf("  │                                                         │\n");
    printf("  │  How to use:                                            │\n");
    printf("  │    1. Choose 'Translate text' from the main menu        │\n");
    printf("  │    2. Pick your target language                         │\n");
    printf("  │    3. Type an English sentence and press Enter          │\n");
    printf("  │    4. The translation appears instantly                 │\n");
    printf("  │                                                         │\n");
    printf("  │  Notes:                                                 │\n");
    printf("  │    - Unknown words are kept as-is                       │\n");
    printf("  │    - History stores up to 50 translations               │\n");
    printf("  │    - Input is case-insensitive                          │\n");
    printf("  └─────────────────────────────────────────────────────────┘\n\n");
}

// ─────────────────────────────────────────────
//  Translation flow
// ─────────────────────────────────────────────
static void do_translation(void) {
    int lang_choice;
    char input[MAX_INPUT_LEN];
    char output[MAX_INPUT_LEN * 2];

    print_language_menu();
    printf("\n  > ");

    if (scanf("%d", &lang_choice) != 1) {
        printf("  Invalid input.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // flush newline

    if (lang_choice < 1 || lang_choice > 5) {
        printf("  Invalid language choice.\n");
        return;
    }

    Language target = parse_language(lang_choice);

    printf("\n  Enter English text:\n  > ");
    if (!fgets(input, sizeof(input), stdin)) return;

    // Strip trailing newline
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
        printf("  Nothing to translate.\n");
        return;
    }

    translate_sentence(input, target, output);

    printf("\n  ┌─────────────────────────────────────────────────────────┐\n");
    printf("  │  Original   : %-43s│\n", input);
    printf("  │  Language   : %-43s│\n", language_name(target));
    printf("  │  Translation: %-43s│\n", output);
    printf("  └─────────────────────────────────────────────────────────┘\n\n");

    history_add(input, output, language_name(target));
}

// ─────────────────────────────────────────────
//  Main loop
// ─────────────────────────────────────────────
int main(void) {
    init_translator();
    history_init();

    int running = 1;
    while (running) {
        clear_screen();
        print_banner();
        print_main_menu();

        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                do_translation();
                printf("  Press Enter to continue...");
                getchar();
                break;
            case 2:
                history_print();
                printf("  Press Enter to continue...");
                getchar();
                break;
            case 3:
                history_clear();
                printf("  Press Enter to continue...");
                getchar();
                break;
            case 4:
                print_help();
                printf("  Press Enter to continue...");
                getchar();
                break;
            case 5:
                printf("\n  Goodbye! شكرا • Merci • Gracias • Danke • Teşekkür\n\n");
                running = 0;
                break;
            default:
                printf("\n  Invalid option. Please try again.\n");
                printf("  Press Enter to continue...");
                getchar();
                break;
        }
    }

    return 0;
}
