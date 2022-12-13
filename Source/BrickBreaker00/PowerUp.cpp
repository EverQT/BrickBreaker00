// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"

#include<Engine/World.h>

bool APowerUp::ActivatePickUp()
{

	auto world = GetWorld();
	if (!world) return false;	// si es null false no se va activar el objeto

	// si es valido
	auto powerup = world->SpawnActor<AActor>(BPPowerUp, FTransform::Identity);	// devuelve un puntero con la direccion de memoria
	if (!powerup) return false;	//no se creo el objeto

	return true;
}

