/*
 * MATH_EQs.c
 *
 * Created: 06/02/2024
 *  Author: Mahmoud Barakat
 */ 
/* SERVICE LAYER */
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MATH_EQs.h"


f32 MAP (f32 Input_Val,f32 MinInput_Val,f32 MaxInput_Val,f32 MinOutput_Val,f32 MaxOutput_Val)
{
	s32 Output_Val;
	Output_Val=(s32)(Input_Val - MinInput_Val)*((MaxOutput_Val - MinOutput_Val)/(MaxInput_Val - MinInput_Val))+ MinOutput_Val;
	return Output_Val;
}
