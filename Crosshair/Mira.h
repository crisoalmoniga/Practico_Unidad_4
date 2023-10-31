#pragma once
#include "stdafx.h"

using namespace sf;

class Mira{

	Texture _crossTex;
	Sprite _crossSprite;

public:

	Mira() {

		_crossTex.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practica_Unidad_4\\Practico_Unidad_4\\Unidad3_Assets\\Unidad3_Assets\\rcircle.png");
		_crossSprite.setTexture(_crossTex);
		_crossSprite.setScale(0.1f, 0.1f);


	}

	void Dibujar(RenderWindow* wnd) {
		wnd->draw(_crossSprite);
	}

}