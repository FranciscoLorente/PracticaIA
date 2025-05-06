#include "../Comportamientos_Jugador/auxiliar.hpp"
#include <iostream>
#include "motorlib/util.h"

Action ComportamientoAuxiliar::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoAuxiliarNivel_0 (sensores);
		break;
	case 1:
		// accion = ComportamientoAuxiliarNivel_1 (sensores);
		break;
	case 2:
		// accion = ComportamientoAuxiliarNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoAuxiliarNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoAuxiliarNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoAuxiliar::interact(Action accion, int valor)
{
	return 0;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
	// El comportamiento de seguir un camino hasta encontrar un puesto base.
	Action accion;
	// El comportamiento de seguir un camino hasta encontrar un puesto base.
	// Actualizacion de variables de estado
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;

	//Definicion del comportamiento
	if (sensores.superficie[0] == 'X'){ //llega a objetivo
		accion = IDLE;
	}
	else if (giro45Izq != 0){
		accion = TURN_SR;
		giro45Izq--;
	}
	else{	
		int pos = VeoCasillaInteresanteA(sensores.superficie[1], sensores.superficie[2], sensores.superficie[3], tiene_zapatillas);
		switch (pos){
			case 2:
				accion = WALK;
				break;
			case 1:
				giro45Izq = 6;
				accion = TURN_SR;
				break;
			case 3:
				accion = TURN_SR;
				break;
			case 0:
				giro45Izq = 6;
				accion = TURN_SR;
				break;
		}
	}

	last_action = accion;
	return accion;

}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_1(Sensores sensores)
{
	return IDLE;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
	return IDLE;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
	return IDLE;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
	return IDLE;
}

int ComportamientoAuxiliar::VeoCasillaInteresanteA (char i, char c, char d, bool zap){
	if (c == 'X') return 2;
	else if (i == 'X') return 1;
	else if (d == 'X') return 3;
	else if (!zap){
		if (c == 'D') return 2;
		else if (i == 'D') return 1;
		else if (d == 'D') return 3;
	}
	if (c == 'C') return 2;
	else if (i == 'C') return 1;
	else if (d == 'C') return 3;
	else return 0;
}

int ComportamientoAuxiliar::ViablePorAlturaA()
{
	return 0;
}