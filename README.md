# Mini Unix Shell — Language Translator

### Advanced C Programming Project

A terminal-based language translator built in C, designed as part of an Advanced C Programming course. The program translates English text into multiple languages using a built-in dictionary, process-style input handling, and session history management.

-----

## Features

- **Multi-language translation** — English to Spanish, French, German, Turkish, Arabic
- **Sentence-level translation** — tokenises and translates word by word
- **Translation history** — stores up to 50 past translations in memory
- **Clean terminal UI** — box-drawn menus and formatted output
- **Built-in help system** — accessible from the main menu

-----

## File Structure

```
translator/
├── main.c          # Entry point, main loop, UI menus
├── translator.c    # Dictionary and translation logic
├── translator.h    # Translator function prototypes and types
├── history.c       # Session history management
├── history.h       # History function prototypes
└── README.md       # Project documentation
```

-----

## How to Compile & Run

```bash
gcc main.c translator.c history.c -o translator
./translator
```

-----

## How to Use

1. Run the program
1. Choose **Translate text** from the menu
1. Select a target language
1. Type an English sentence
1. See the translation instantly
1. View past translations under **View history**

-----

## Team Members

|Name             |Student ID|
|-----------------|----------|
|Pragati Badame   |25013466  |
|Laiza Afnan      |—         |
|Nafiz Arfan Ahmed|23012854  |
|Ashu             |25014147  |

-----

## Concepts Applied

- Structs and enums in C
- String tokenisation (`strtok`)
- Memory management with static arrays
- Modular file structure (`.c` / `.h` separation)
- Terminal I/O and formatted output