// Fill out your copyright notice in the Description page of Project Settings.


#include "M_Damage.h"

#include "Paddle.h"
#include "HealthComponent.h"

 //definicion de activate PickUp
bool AM_Damage::ActivatePickUp()
{
    return Paddle->GetHealthComponent()->ToDamage(Health);
}
