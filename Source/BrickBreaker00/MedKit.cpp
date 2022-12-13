// Fill out your copyright notice in the Description page of Project Settings.


#include "MedKit.h"

#include "Paddle.h"
#include "HealthComponent.h"

 //definicion de activate PickUp
bool AMedKit::ActivatePickUp()
{
    return Paddle->GetHealthComponent()->Heal(Healt);
}

