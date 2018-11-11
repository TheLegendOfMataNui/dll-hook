// OptionalPatchNative.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "HookMod.h"
#include <OSIUtil.h>
#include <Native/StRGBABytes.h>
#include <Native/ScFastColor.h>
#include <LOMNAPI.h>

using namespace LOMNHook;

Native::ScOSIVariant* GcCharacter__SetColors(Native::ScOSIVariant* result, Util::ScOSIVirtualMachine* vm, void* character, DWORD color2, DWORD color3, DWORD color1, void* param5, void* param6, void* param7, void* param8, void* param9, void* param10) {

	DWORD pDrawableModel = *(DWORD*)((DWORD)character + 384);
	Native::ScFastColor* pColor1 = (Native::ScFastColor*)(pDrawableModel + 0x6C);
	Native::ScFastColor* pColor2 = (Native::ScFastColor*)(pDrawableModel + 0x80);
	Native::ScFastColor* pColor3 = (Native::ScFastColor*)(pDrawableModel + 0x94);
	Native::StRGBABytes inColor1 = Native::StRGBABytes((color1 >> 24) & 0xFF, (color1 >> 16) & 0xFF, (color1 >> 8) & 0xFF, (color1 >> 0) & 0xFF);
	Native::StRGBABytes inColor2 = Native::StRGBABytes((color2 >> 24) & 0xFF, (color2 >> 16) & 0xFF, (color2 >> 8) & 0xFF, (color2 >> 0) & 0xFF);
	Native::StRGBABytes inColor3 = Native::StRGBABytes((color3 >> 24) & 0xFF, (color3 >> 16) & 0xFF, (color3 >> 8) & 0xFF, (color3 >> 0) & 0xFF);

	OutputDebugMemory((void*)pDrawableModel, 0xBC, "Drawable Model");

	pColor1->R = (float)inColor1.R / 255.0f;
	pColor1->G = (float)inColor1.G / 255.0f;
	pColor1->B = (float)inColor1.B / 255.0f;
	pColor1->A = (float)inColor1.A / 255.0f;
	pColor2->R = (float)inColor2.R / 255.0f;
	pColor2->G = (float)inColor2.G / 255.0f;
	pColor2->B = (float)inColor2.B / 255.0f;
	pColor2->A = (float)inColor2.A / 255.0f;
	pColor3->R = (float)inColor3.R / 255.0f;
	pColor3->G = (float)inColor3.G / 255.0f;
	pColor3->B = (float)inColor3.B / 255.0f;
	pColor3->A = (float)inColor3.A / 255.0f;

	DWORD pMask = *(DWORD*)((DWORD)character + 100);
	if (pMask > 0) {
		DWORD pMaskModel = *(DWORD*)(pMask + 5 * 4);
		OutputDebugMemory((void*)pMaskModel, 0xBC, "Mask Model");
		Native::ScFastColor* pMaskColor1 = (Native::ScFastColor*)(pMaskModel + 0x6C);
		Native::ScFastColor* pMaskColor2 = (Native::ScFastColor*)(pMaskModel + 0x80);
		Native::ScFastColor* pMaskColor3 = (Native::ScFastColor*)(pMaskModel + 0x94);

		pMaskColor1->R = (float)inColor2.R / 255.0f;
		pMaskColor1->G = (float)inColor2.G / 255.0f;
		pMaskColor1->B = (float)inColor2.B / 255.0f;
		pMaskColor1->A = (float)inColor2.A / 255.0f;
		pMaskColor2->R = (float)inColor2.R / 255.0f;
		pMaskColor2->G = (float)inColor2.G / 255.0f;
		pMaskColor2->B = (float)inColor2.B / 255.0f;
		pMaskColor2->A = (float)inColor2.A / 255.0f;
		pMaskColor3->R = (float)inColor3.R / 255.0f;
		pMaskColor3->G = (float)inColor3.G / 255.0f;
		pMaskColor3->B = (float)inColor3.B / 255.0f;
		pMaskColor3->A = (float)inColor3.A / 255.0f;
	}

	result->TypeID = 0xF;
	result->Payload = 0;
	return result;
}

class OptionalPatchNative : public HookMod {
public:
	std::wstring GetName() const override {
		return L"Litestone Optional Patch Native Hookmod";
	}

	int GetVersion() const override {
		return 0;
	}

	void OnPostInit() override {
		Util::ScOSITypeID characterType = Util::OSIGetTypeID("GcCharacter");
		Util::ScOSITypeID colorType = 21;
		LOMNHook::Util::OSIRegisterFunction((Util::OSIFunctionCallback)GcCharacter__SetColors, "gccharacter", "setcolors", 4, 4, characterType, colorType, colorType, colorType, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf);
	}
};

OptionalPatchNative Instance;

extern "C" {
	__declspec(dllexport) LOMNHook::HookMod* HookmodInit() {
		return &Instance;
	}
}