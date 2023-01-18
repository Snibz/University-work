


enum Asteikko
{
    Celsius = 0,
    Fahrenheit = 1,
    Kelvin = 2
};

typedef enum Asteikko Asteikko;

struct Lampotila
{
    float lampotila;
    Asteikko asteikko;
};

typedef struct Lampotila Lampotila;

float muunna(Lampotila a, Asteikko b);

float erotus(Lampotila a, Lampotila b, Asteikko c);
