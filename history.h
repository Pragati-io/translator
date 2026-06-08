#ifndef HISTORY_H
#define HISTORY_H

#define MAX_HISTORY     50
#define MAX_INPUT_LEN  1024

// One history record
typedef struct {
    char original[MAX_INPUT_LEN];
    char translated[MAX_INPUT_LEN];
    char language[32];
} HistoryEntry;

void        history_init(void);
void        history_add(const char *original, const char *translated, const char *language);
void        history_print(void);
void        history_clear(void);
int         history_count(void);

#endif // HISTORY_H
