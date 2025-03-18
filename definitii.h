#ifndef definitii_h
#define definitii_h

typedef unsigned long long U64;
#define NAME "jocul 1.0"
#define BRD_SQ_NUM 120
#define MAXGAMEMOVES 2048

enum {EMPTY, wP, wC, wN, wT, wRe, wRi, bP, bC, bN, bT, bRe, bRi};
enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};
enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};
enum {WHITE, BLACK, BOTH};
enum {
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum {TRUE, FALSE};
 
enum {WRER = 1, WRIR = 2, BRER = 4, BRIR = 8 }; // ROCADELE

typedef struct
{

}S_UNDO;
typedef struct {
	int pieces[BRD_SQ_NUM]; // piesele de pe tabla
	U64 pawns[3]; //face usoara gasirea pionilor, mai ales culoarea 
	int KingSq[2]; //pozitia regilor 
	int side; //cine muta
	int enPas; //mutare speciala
	int fiftyMove; //daca se ajunge la 50 de mutari se incheie meciul la egalitate

	int ply; // numarul jumatatilor de mutare
	int hisPly; //si cate jumatati de mutari s au facut pana acum

	int castlePerm; 

	U64 posKey; //o cheie unica generata pentru fiecare pozitie
	int pceNum[13]; //numarul total de piese de pe masa
	int bigPce[3];// numarul de piese care nu sunt pioni
	int majPce[3]; // ture si regine
	int minPce[3];// cal si nebuni
	S_TABLA PvTable[1]; 
	int PvArray[13][MAXDEPTH];
	int searchHistory[13][BRD_SQ_NUM];
	int searchKillers[2][MAXDEPTH];
} S_TABLA;
#endif
