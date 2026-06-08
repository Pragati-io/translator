#include <stdio.h>
#include <string.h>
#include "history.h"

static HistoryEntry history[MAX_HISTORY];
static int          count = 0;

void history_init(void) {
    count = 0;
    memset(history, 0, sizeof(history));
}

void history_add(const char *original, const char *translated, const char *language) {
    if (count >= MAX_HISTORY) {
        // Shift everything up to make room (circular-ish)
        memmove(&history[0], &history[1], sizeof(HistoryEntry) * (MAX_HISTORY - 1));
        count = MAX_HISTORY - 1;
    }
    strncpy(history[count].original,   original,   MAX_INPUT_LEN - 1);
    strncpy(history[count].translated, translated, MAX_INPUT_LEN - 1);
    strncpy(history[count].language,   language,   31);
    count++;
}

void history_print(void) {
    if (count == 0) {
        printf("\n  No translation history yet.\n");
        return;
    }
    printf("\n  ┌─────────────────────────────────────────────────────────┐\n");
    printf("  │                  TRANSLATION HISTORY                   │\n");
    printf("  └─────────────────────────────────────────────────────────┘\n");
    for (int i = 0; i < count; i++) {
        printf("  [%2d]  %-20s →  %s  (%s)\n",
               i + 1,
               history[i].original,
               history[i].translated,
               history[i].language);
    }
    printf("\n");
}

void history_clear(void) {
    history_init();
    printf("\n  History cleared.\n");
}

int history_count(void) {
    return count;
}
