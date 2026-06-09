#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#define MAX_INPUT_LEN 1024
#define MAX_WORD_LEN  128
#define MAX_LANGUAGES 17

typedef enum {
    LANG_ENGLISH    = 0,
    LANG_SPANISH,
    LANG_FRENCH,
    LANG_GERMAN,
    LANG_TURKISH,
    LANG_ARABIC,
    LANG_HINDI,
    LANG_PORTUGUESE,
    LANG_RUSSIAN,
    LANG_JAPANESE,
    LANG_KOREAN,
    LANG_CHINESE,
    LANG_ITALIAN,
    LANG_DUTCH,
    LANG_POLISH,
    LANG_URDU,
    LANG_UZBEK
} Language;

typedef struct {
    char english[MAX_WORD_LEN];
    char spanish[MAX_WORD_LEN];
    char french[MAX_WORD_LEN];
    char german[MAX_WORD_LEN];
    char turkish[MAX_WORD_LEN];
    char arabic[MAX_WORD_LEN];
    char hindi[MAX_WORD_LEN];
    char portuguese[MAX_WORD_LEN];
    char russian[MAX_WORD_LEN];
    char japanese[MAX_WORD_LEN];
    char korean[MAX_WORD_LEN];
    char chinese[MAX_WORD_LEN];
    char italian[MAX_WORD_LEN];
    char dutch[MAX_WORD_LEN];
    char polish[MAX_WORD_LEN];
    char urdu[MAX_WORD_LEN];
    char uzbek[MAX_WORD_LEN];
} DictionaryEntry;

void        init_translator(void);
const char *translate_word(const char *word, Language target);
void        translate_sentence(const char *input, Language target, char *output);
const char *language_name(Language lang);
Language    parse_language(int choice);
void        print_language_menu(void);

#endif

