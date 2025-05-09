#ifndef STRUKTURY_H
#define STRUKTURY_H

/** Punkt w przestrzeni trojwymiarowej. */
struct punkt
{
	double x, y;   ///< wspolrzedne punktu
};

/** Struktura reprezentujaca odcinek.  */
struct odcinek
{
	punkt A, B; ///< konce odcinka
};

/** Trojkat zbudowany z trzech punktow */
struct trojkat
{
	punkt A, B, C;
};

#endif
