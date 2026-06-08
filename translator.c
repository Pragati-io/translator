#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "translator.h"

static DictionaryEntry dictionary[] = {
/*  english       spanish          french              german               turkish          arabic       hindi          portuguese       russian        japanese    korean      chinese    italian          dutch           polish           urdu           uzbek        */
{"hello",       "hola",          "bonjour",          "hallo",             "merhaba",       "مرحبا",     "नमस्ते",      "olá",           "привет",      "こんにちは",  "안녕하세요", "你好",    "ciao",          "hallo",        "cześć",         "ہیلو",        "salom"},
{"goodbye",     "adiós",         "au revoir",        "auf wiedersehen",   "hoşça kal",     "وداعا",     "अलविदा",      "adeus",         "пока",        "さようなら",  "안녕히",    "再见",    "arrivederci",   "tot ziens",    "do widzenia",   "الوداع",      "xayr"},
{"yes",         "sí",            "oui",              "ja",                "evet",          "نعم",       "हाँ",         "sim",           "да",          "はい",       "네",        "是",      "sì",            "ja",           "tak",           "ہاں",         "ha"},
{"no",          "no",            "non",              "nein",              "hayır",         "لا",        "नहीं",        "não",           "нет",         "いいえ",     "아니요",    "不",      "no",            "nee",          "nie",           "نہیں",        "yo'q"},
{"please",      "por favor",     "s'il vous plaît",  "bitte",             "lütfen",        "من فضلك",   "कृपया",       "por favor",     "пожалуйста",  "どうぞ",     "제발",      "请",      "per favore",    "alstublieft",  "proszę",        "براہ کرم",    "iltimos"},
{"thank you",   "gracias",       "merci",            "danke",             "teşekkür",      "شكرا",      "धन्यवाद",     "obrigado",      "спасибо",     "ありがとう",  "감사합니다","谢谢",    "grazie",        "dank je",      "dziękuję",      "شکریہ",       "rahmat"},
{"sorry",       "lo siento",     "désolé",           "entschuldigung",    "özür dilerim",  "آسف",       "माफ करना",    "desculpe",      "извините",    "ごめんなさい","죄송합니다", "对不起",  "scusa",         "sorry",        "przepraszam",   "معاف کریں",   "kechirasiz"},
{"help",        "ayuda",         "aide",             "hilfe",             "yardım",        "مساعدة",    "मदद",         "ajuda",         "помощь",      "助けて",     "도움",      "帮助",    "aiuto",         "hulp",         "pomoc",         "مدد",         "yordam"},
{"water",       "agua",          "eau",              "wasser",            "su",            "ماء",       "पानी",        "água",          "вода",        "水",         "물",        "水",      "acqua",         "water",        "woda",          "پانی",        "suv"},
{"food",        "comida",        "nourriture",       "essen",             "yemek",         "طعام",      "खाना",        "comida",        "еда",         "食べ物",     "음식",      "食物",    "cibo",          "eten",         "jedzenie",      "کھانا",       "ovqat"},
{"house",       "casa",          "maison",           "haus",              "ev",            "منزل",      "घर",          "casa",          "дом",         "家",         "집",        "房子",    "casa",          "huis",         "dom",           "گھر",         "uy"},
{"friend",      "amigo",         "ami",              "freund",            "arkadaş",       "صديق",      "दोस्त",       "amigo",         "друг",        "友達",       "친구",      "朋友",    "amico",         "vriend",       "przyjaciel",    "دوست",        "do'st"},
{"love",        "amor",          "amour",            "liebe",             "aşk",           "حب",        "प्यार",       "amor",          "любовь",      "愛",         "사랑",      "爱",      "amore",         "liefde",       "miłość",        "محبت",        "muhabbat"},
{"good",        "bueno",         "bon",              "gut",               "iyi",           "جيد",       "अच्छा",       "bom",           "хорошо",      "良い",       "좋다",      "好",      "buono",         "goed",         "dobry",         "اچھا",        "yaxshi"},
{"bad",         "malo",          "mauvais",          "schlecht",          "kötü",          "سيء",       "बुरा",        "mau",           "плохо",       "悪い",       "나쁘다",    "坏",      "cattivo",       "slecht",       "zły",           "برا",         "yomon"},
{"morning",     "mañana",        "matin",            "morgen",            "sabah",         "صباح",      "सुबह",        "manhã",         "утро",        "朝",         "아침",      "早上",    "mattina",       "ochtend",      "rano",          "صبح",         "ertalab"},
{"night",       "noche",         "nuit",             "nacht",             "gece",          "ليل",       "रात",         "noite",         "ночь",        "夜",         "밤",        "晚上",    "notte",         "nacht",        "noc",           "رات",         "kecha"},
{"day",         "día",           "jour",             "tag",               "gün",           "يوم",       "दिन",         "dia",           "день",        "日",         "날",        "天",      "giorno",        "dag",          "dzień",         "دن",          "kun"},
{"school",      "escuela",       "école",            "schule",            "okul",          "مدرسة",     "स्कूल",       "escola",        "школа",       "学校",       "학교",      "学校",    "scuola",        "school",       "szkoła",        "اسکول",       "maktab"},
{"book",        "libro",         "livre",            "buch",              "kitap",         "كتاب",      "किताब",       "livro",         "книга",       "本",         "책",        "书",      "libro",         "boek",         "książka",       "کتاب",        "kitob"},
{"computer",    "computadora",   "ordinateur",       "computer",          "bilgisayar",    "حاسوب",     "कंप्यूटर",    "computador",    "компьютер",   "コンピューター","컴퓨터",  "电脑",    "computer",      "computer",     "komputer",      "کمپیوٹر",     "kompyuter"},
{"phone",       "teléfono",      "téléphone",        "telefon",           "telefon",       "هاتف",      "फ़ोन",         "telefone",      "телефон",     "電話",       "전화",      "电话",    "telefono",      "telefoon",     "telefon",       "فون",         "telefon"},
{"money",       "dinero",        "argent",           "geld",              "para",          "مال",       "पैसा",        "dinheiro",      "деньги",      "お金",       "돈",        "钱",      "soldi",         "geld",         "pieniądze",     "پیسہ",        "pul"},
{"time",        "tiempo",        "temps",            "zeit",              "zaman",         "وقت",       "समय",         "tempo",         "время",       "時間",       "시간",      "时间",    "tempo",         "tijd",         "czas",          "وقت",         "vaqt"},
{"happy",       "feliz",         "heureux",          "glücklich",         "mutlu",         "سعيد",      "खुश",         "feliz",         "счастливый",  "嬉しい",     "행복하다",  "快乐",    "felice",        "blij",         "szczęśliwy",    "خوش",         "baxtli"},
{"sad",         "triste",        "triste",           "traurig",           "üzgün",         "حزين",      "दुखी",        "triste",        "грустный",    "悲しい",     "슬프다",    "悲伤",    "triste",        "verdrietig",   "smutny",        "اداس",        "qayg'uli"},
{"big",         "grande",        "grand",            "groß",              "büyük",         "كبير",      "बड़ा",        "grande",        "большой",     "大きい",     "크다",      "大",      "grande",        "groot",        "duży",          "بڑا",         "katta"},
{"small",       "pequeño",       "petit",            "klein",             "küçük",         "صغير",      "छोटा",        "pequeno",       "маленький",   "小さい",     "작다",      "小",      "piccolo",       "klein",        "mały",          "چھوٹا",       "kichik"},
{"cat",         "gato",          "chat",             "katze",             "kedi",          "قطة",       "बिल्ली",      "gato",          "кошка",       "猫",         "고양이",    "猫",      "gatto",         "kat",          "kot",           "بلی",         "mushuk"},
{"dog",         "perro",         "chien",            "hund",              "köpek",         "كلب",       "कुत्ता",      "cachorro",      "собака",      "犬",         "개",        "狗",      "cane",          "hond",         "pies",          "کتا",         "it"},
{"i",           "yo",            "je",               "ich",               "ben",           "أنا",       "मैं",         "eu",            "я",           "私",         "나",        "我",      "io",            "ik",           "ja",            "میں",         "men"},
{"you",         "tú",            "vous",             "du",                "sen",           "أنت",       "तुम",         "você",          "ты",          "あなた",     "당신",      "你",      "tu",            "jij",          "ty",            "آپ",          "siz"},
{"we",          "nosotros",      "nous",             "wir",               "biz",           "نحن",       "हम",          "nós",           "мы",          "私たち",     "우리",      "我们",    "noi",           "wij",          "my",            "ہم",          "biz"},
{"they",        "ellos",         "ils",              "sie",               "onlar",         "هم",        "वे",          "eles",          "они",         "彼ら",       "그들",      "他们",    "loro",          "zij",          "oni",           "وہ",          "ular"},
{"what",        "qué",           "quoi",             "was",               "ne",            "ماذا",      "क्या",        "o que",         "что",         "何",         "뭐",        "什么",    "cosa",          "wat",          "co",            "کیا",         "nima"},
{"where",       "dónde",         "où",               "wo",                "nerede",        "أين",       "कहाँ",        "onde",          "где",         "どこ",       "어디",      "哪里",    "dove",          "waar",         "gdzie",         "کہاں",        "qayer"},
{"when",        "cuándo",        "quand",            "wann",              "ne zaman",      "متى",       "कब",          "quando",        "когда",       "いつ",       "언제",      "什么时候","quando",        "wanneer",      "kiedy",         "کب",          "qachon"},
{"how",         "cómo",          "comment",          "wie",               "nasıl",         "كيف",       "कैसे",        "como",          "как",         "どうやって",  "어떻게",    "怎么",    "come",          "hoe",          "jak",           "کیسے",        "qanday"},
{"why",         "por qué",       "pourquoi",         "warum",             "neden",         "لماذا",     "क्यों",       "por que",       "почему",      "なぜ",       "왜",        "为什么",  "perché",        "waarom",       "dlaczego",      "کیوں",        "nima uchun"},
{"name",        "nombre",        "nom",              "name",              "isim",          "اسم",       "नाम",         "nome",          "имя",         "名前",       "이름",      "名字",    "nome",          "naam",         "imię",          "نام",         "ism"},
{"today",       "hoy",           "aujourd'hui",      "heute",             "bugün",         "اليوم",     "आज",          "hoje",          "сегодня",     "今日",       "오늘",      "今天",    "oggi",          "vandaag",      "dzisiaj",       "آج",          "bugun"},
{"tomorrow",    "mañana",        "demain",           "morgen",            "yarın",         "غدا",       "कल",          "amanhã",        "завтра",      "明日",       "내일",      "明天",    "domani",        "morgen",       "jutro",         "کل",          "ertaga"},
{"work",        "trabajo",       "travail",          "arbeit",            "iş",            "عمل",       "काम",         "trabalho",      "работа",      "仕事",       "일",        "工作",    "lavoro",        "werk",         "praca",         "کام",         "ish"},
{"city",        "ciudad",        "ville",            "stadt",             "şehir",         "مدينة",     "शहर",         "cidade",        "город",       "都市",       "도시",      "城市",    "città",         "stad",         "miasto",        "شہر",         "shahar"},
{"country",     "país",          "pays",             "land",              "ülke",          "بلد",       "देश",         "país",          "страна",      "国",         "나라",      "国家",    "paese",         "land",         "kraj",          "ملک",         "mamlakat"},
{"student",     "estudiante",    "étudiant",         "student",           "öğrenci",       "طالب",      "छात्र",       "estudante",     "студент",     "学生",       "학생",      "学生",    "studente",      "student",      "student",       "طالب علم",    "talaba"},
{"teacher",     "profesor",      "professeur",       "lehrer",            "öğretmen",      "معلم",      "शिक्षक",      "professor",     "учитель",     "先生",       "선생님",    "老师",    "insegnante",    "leraar",       "nauczyciel",    "استاد",       "o'qituvchi"},
{"university",  "universidad",   "université",       "universität",       "üniversite",    "جامعة",     "विश्वविद्यालय","universidade", "университет", "大学",       "대학교",    "大学",    "università",    "universiteit", "uniwersytet",   "یونیورسٹی",   "universitet"},
{"family",      "familia",       "famille",          "familie",           "aile",          "عائلة",     "परिवार",      "família",       "семья",       "家族",       "가족",      "家庭",    "famiglia",      "familie",      "rodzina",       "خاندان",      "oila"},
{"beautiful",   "hermoso",       "beau",             "schön",             "güzel",         "جميل",      "सुंदर",       "bonito",        "красивый",    "美しい",     "아름답다",  "美丽",    "bello",         "mooi",         "piękny",        "خوبصورت",     "chiroyli"},
};

static int dict_size = sizeof(dictionary) / sizeof(DictionaryEntry);

static void to_lower(char *s) {
    for (; *s; s++) *s = (char)tolower((unsigned char)*s);
}

void init_translator(void) {}

const char *language_name(Language lang) {
    switch (lang) {
        case LANG_ENGLISH:    return "English";
        case LANG_SPANISH:    return "Spanish";
        case LANG_FRENCH:     return "French";
        case LANG_GERMAN:     return "German";
        case LANG_TURKISH:    return "Turkish";
        case LANG_ARABIC:     return "Arabic";
        case LANG_HINDI:      return "Hindi";
        case LANG_PORTUGUESE: return "Portuguese";
        case LANG_RUSSIAN:    return "Russian";
        case LANG_JAPANESE:   return "Japanese";
        case LANG_KOREAN:     return "Korean";
        case LANG_CHINESE:    return "Chinese";
        case LANG_ITALIAN:    return "Italian";
        case LANG_DUTCH:      return "Dutch";
        case LANG_POLISH:     return "Polish";
        case LANG_URDU:       return "Urdu";
        case LANG_UZBEK:      return "Uzbek";
        default:              return "Unknown";
    }
}

Language parse_language(int choice) {
    if (choice >= 1 && choice <= 16)
        return (Language)(choice);
    return LANG_ENGLISH;
}

void print_language_menu(void) {
    printf("\n  Select target language:\n");
    printf("  [1]  Spanish      [2]  French       [3]  German\n");
    printf("  [4]  Turkish      [5]  Arabic        [6]  Hindi\n");
    printf("  [7]  Portuguese   [8]  Russian       [9]  Japanese\n");
    printf("  [10] Korean       [11] Chinese       [12] Italian\n");
    printf("  [13] Dutch        [14] Polish        [15] Urdu\n");
    printf("  [16] Uzbek\n");
}

const char *translate_word(const char *word, Language target) {
    char lower[MAX_WORD_LEN];
    strncpy(lower, word, MAX_WORD_LEN - 1);
    lower[MAX_WORD_LEN - 1] = '\0';
    to_lower(lower);

    for (int i = 0; i < dict_size; i++) {
        if (strcmp(lower, dictionary[i].english) == 0) {
            switch (target) {
                case LANG_SPANISH:    return dictionary[i].spanish;
                case LANG_FRENCH:     return dictionary[i].french;
                case LANG_GERMAN:     return dictionary[i].german;
                case LANG_TURKISH:    return dictionary[i].turkish;
                case LANG_ARABIC:     return dictionary[i].arabic;
                case LANG_HINDI:      return dictionary[i].hindi;
                case LANG_PORTUGUESE: return dictionary[i].portuguese;
                case LANG_RUSSIAN:    return dictionary[i].russian;
                case LANG_JAPANESE:   return dictionary[i].japanese;
                case LANG_KOREAN:     return dictionary[i].korean;
                case LANG_CHINESE:    return dictionary[i].chinese;
                case LANG_ITALIAN:    return dictionary[i].italian;
                case LANG_DUTCH:      return dictionary[i].dutch;
                case LANG_POLISH:     return dictionary[i].polish;
                case LANG_URDU:       return dictionary[i].urdu;
                case LANG_UZBEK:      return dictionary[i].uzbek;
                default:              return word;
            }
        }
    }
    return word;
}

void translate_sentence(const char *input, Language target, char *output) {
    char buffer[MAX_INPUT_LEN];
    strncpy(buffer, input, MAX_INPUT_LEN - 1);
    buffer[MAX_INPUT_LEN - 1] = '\0';

    output[0] = '\0';
    int first = 1;

    char *token = strtok(buffer, " \t\n");
    while (token != NULL) {
        const char *translated = translate_word(token, target);
        if (!first) strcat(output, " ");
        strcat(output, translated);
        first = 0;
        token = strtok(NULL, " \t\n");
    }
}
