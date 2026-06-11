# Fable — Your Travel Helper
### Advanced C Programming Project

A travel companion web app built as part of an Advanced C Programming course. Fable helps you communicate, explore, and stay safe anywhere in the world — with translation, sign language, barcode food scanning, and more.

---

## Features

- *Multi-language translation* — Translate between 16 languages instantly
- *Voice to text* — Speak and get your translation out loud
- *Travel phrases* — Quick-access common phrases for travellers
- *Reverse lookup* — Enter any word and find its meaning across languages
- *Sign language* — Type or speak in any language and see it in sign language (for accessibility)
- *Barcode food scanner* — Scan any food product barcode to check ingredients against your allergies and dietary restrictions using the Open Food Facts database — no API key needed!
- *Translation history* — View and revisit past translations
- *16 supported languages* — Including English, Spanish, French, German, Arabic, Turkish, Japanese, Korean, and more

---

## File Structure


fable/
├── index.html      # Full web app (UI, logic, all features)
├── main.c          # Entry point, main loop, UI menus
├── translator.c    # Dictionary and translation logic
├── translator.h    # Translator function prototypes and types
├── history.c       # Session history management
├── history.h       # History function prototypes
└── README.md       # Project documentation


---

## How to Run

Simply open index.html in any browser — no installation needed!

Or visit the live version at: *joyful-mooncake-58ac40.netlify.app*

---

## How to Use

1. *Translate* — Pick languages, type or speak, hit translate
2. *Travel* — Browse common travel phrases by category
3. *Reverse* — Enter a word to find its meaning in any language
4. *Sign* — See sign language for anything you type or say
5. *Food Scanner* — Enter a product barcode to check if it's safe for your diet

---

## Team Members

| Name | Student ID |
|------|-----------|
| Pragati Badame | 25013466 |
| Raisa Leuza Afnan | 25013403 |
| Nafiz Arfan Ahmed | 23012854 |
| Ashu | 25014147 |

---

## Concepts Applied

- Structs and enums in C
- String tokenisation (strtok)
- Memory management with static arrays
- Modular file structure (.c / .h separation)
- Terminal I/O and formatted output
- Web technologies: HTML, CSS, JavaScript
- REST API integration (Open Food Facts)
- Base64 image encoding
- LocalStorage for persistent user preferences
