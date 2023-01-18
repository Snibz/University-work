

enum Maa
{
    HERTTA = 1,
    RUUTU = 2,
    RISTI = 3,
    PATA = 4
};

typedef enum Maa Maa;

enum Arvo
{
    ASSA = 1,
    KAKKONEN = 2,
    KOLMONEN = 3,
    NELONEN = 4,
    VIITONEN = 5,
    KUUTONEN = 6,
    SEISKA = 7,
    KASI = 8,
    YSI = 9,
    KYMPPI = 10,
    JATKA = 11,
    ROUVA = 12,
    KUNKKU = 13
};

typedef enum Arvo Arvo;

enum
{
    MAA_LKM = 4,
    MAA_KOKO = 13,
    KORTTI_LKM = MAA_LKM * MAA_KOKO
};

const char *MAIDEN_NIMET[MAA_LKM +1];

const char *KORTTIEN_NIMET[MAA_KOKO + 1];

struct Kortti
{
    Maa maa;
    Arvo arvo;
};

typedef struct Kortti Kortti;

void tulostaKortti(Kortti kortti);

void tulostaKorttiOs(const Kortti *kottiOs);
