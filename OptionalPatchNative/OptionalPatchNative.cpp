// OptionalPatchNative.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "HookMod.h"
#include <OSIUtil.h>
#include <Native/StRGBABytes.h>
#include <Native/ScFastColor.h>
#include <Native/ScIdentifier.h>
#include <Native/Vector.h>
#include <LOMNAPI.h>
#include "../minhook/include/MinHook.h"

using namespace LOMNHook;
using namespace LOMNHook::Native;

struct ScFixedString
{
	_ScBaseString str;
	int length_max;
};

struct __ScFixedString_128
{
	ScFixedString super;
	char buffer[128];
};

struct __declspec(align(4)) SxReferenceCountable
{
	void *vtable;
	int count;
};

struct ScSLKFile
{
	SxReferenceCountable refc;
	__ScFixedString_128 fixedstr;
	DWORD unknown;
};

struct ScPoint3d {
	float X;
	float Y;
	float Z;
};

typedef ScPoint3d ScVector;

struct __declspec(align(4)) __Cinema_Thing_Location
{
	float time;
	ScPoint3d position;
	ScPoint3d orientation;
};

struct __declspec(align(4)) ___GcCinemaCharacterInfo_Locations
{
	__Cinema_Thing_Location location_1;
	__Cinema_Thing_Location location_2;
};

struct __declspec(align(4)) _GcCinemaCharacterInfo
{
	ScIdentifier anim_hierarchy;
	ScIdentifier character;
	ScIdentifier anim_baked;
	float switch_mask_times[2];
	DWORD dword_1;
	___GcCinemaCharacterInfo_Locations *sub;
};

struct __declspec(align(4)) __ScSLKFile_GcCinemaCharacter
{
	ScSLKFile slkfile;
	DWORD count;
	_GcCinemaCharacterInfo *entries;
	BYTE unknown[256];
};


typedef void ScSLOSISLKCubicSpline;


#pragma pack(push, 4)
struct _D3DMATRIX
{
  #pragma pack(push, 4)
  union
  {
    #pragma pack(push, 4)
    struct
    {
      float _11;
      float _12;
      float _13;
      float _14;
      float _21;
      float _22;
      float _23;
      float _24;
      float _31;
      float _32;
      float _33;
      float _34;
      float _41;
      float _42;
      float _43;
      float _44;
    };
    #pragma pack(pop)
    float m[4][4];
  };
  #pragma pack(pop)
};
#pragma pack(pop)
typedef _D3DMATRIX ScMatrix;

struct ScBoundingGeometry3d
{
  void *ptr_unknown;
};

struct __declspec(align(4)) ScPlane
{
  ScVector vector;
  float _float;
};

struct ScBoundingFrustum
{
  ScBoundingGeometry3d super;
  float floats[27];
  BYTE unknown[4];
  ScPlane planes[6];
};

struct __declspec(align(4)) ScBoundingSphere
{
  ScBoundingGeometry3d super;
  ScPoint3d point_4;
  float float_16;
  float float_20;
};

struct SxStateStamp
{
  BYTE process_call_toggle;
  BYTE removed__added_0_removed_1_process_manager;
  BYTE _pad_2;
  BYTE _pad_3;
};

struct __declspec(align(4)) SxTypedBase
{
  void* get_type_info_ptr;
};

struct ScRenderObject
{
  SxReferenceCountable super;
  SxTypedBase typed_base;
  SxStateStamp state_stamp;
  ScBoundingSphere bounding_sphere;
};

struct __declspec(align(4)) ScCamera
{
  ScRenderObject super;
  ScBoundingFrustum bounding_frustum;
  float nearclip;
  float draw_distance;
  BYTE byte_1;
  BYTE byte_2;
  ScMatrix matrix;
};

struct __declspec(align(4)) ScPerspectiveCamera
{
  ScCamera super;
  float fov_rad;
  float aspect;
};

struct __declspec(align(4)) GcLookatCamera
{
  ScPerspectiveCamera super;
  ScPoint3d point3d_eye;
  ScPoint3d point3d_at;
  ScPoint3d point3d_3;
  ScPoint3d point3d_at_minus_eye;
  float zoom_factor;
  ScMatrix view_matrix;
  BYTE byte_1;
};

struct __declspec(align(8)) GcLegoCamera
{
  GcLookatCamera super;
  ScPoint3d points_10_1[10];
  ScPoint3d points_10_2[10];
  BYTE byte_1;
  BYTE byte_2;
  WORD word_1;
  ScIdentifier id_700;
  BYTE bytes_704[4];
  float float_708__conversation_related;
  float float_712__conversation_related;
  float float_716__conversation_related;
  float float_720__conversation_related;
  float float_724__conversation_related;
  float float_728__conversation_related;
  WORD word_732;
  BYTE _pad_734[2];
  float lock_pitch_float;
  BYTE unknown_740[4];
  float float_744;
  float mouse_seneitivity;
  BYTE invert_mouse;
  BYTE byte_753;
  BYTE bytes_754[6];
  double popback_time;
  BYTE use_popback;
  BYTE lock_pitch_byte;
  BYTE bytes_770[6];
  BYTE substruct_bytes_776[32];
  BYTE substruct_bytes_808[32];
  BYTE substruct_bytes_840[32];
  BYTE substruct_bytes_872[32];
  ScPoint3d point_904;
  ScPoint3d point_916;
  BYTE byte_928;
  BYTE ai_mode;
  ScSLOSISLKCubicSpline* camera_spline;
  double double_936;
  double double_944;
  DWORD dword_952;
  DWORD dword_956;
  BYTE bytes_960[8];
  float float_968;
  float float_972;
  float float_976;
  float height_offset;
  BYTE byte_984;
  float float_988;
  float float_992;
  float float_996;
  float float_1000;
  ScVector forward_vector;
  float float_1016;
  float float_1020;
  float float_1024;
  BYTE byte_1028;
  BYTE byte_1029;
  ScMatrix matrix_1028;
  float height_offset_2;
  float float_1100;
  float zoom_factor;
  BYTE byte_1108;
  BYTE bytes_1109[11];
  BYTE byte_1120;
  BYTE byte_1121;
  float float_1124;
  float float_1128;
  float float_1132;
  BYTE byte_1134;
  BYTE bytes_1135[7];
  double double_1144;
  float float_1152;
  float float_1156;
  BYTE byte_1160;
  DWORD flags_1164;
  BYTE byte_1168;
  ScVector vector_1172;
  float float_1184;
  BYTE byte_1188;
  double double_1192;
  DWORD id_1200;
};

struct GcMask;
struct GcCharacterMoveInterpreter;
struct GcCollisionPhysics;
struct GcTargeteer;
struct GcMotionSystem;
struct GcCharacterAIController;
struct _GtCharacterDamage;
struct _GtCharacterTexture;
struct _GtBoneAdjustment;
struct GcCharacterModel;
struct GcMorphModel;
struct ScDrawableModel;
struct ScFastMatrix;
struct GcSprite;
struct GcCollisionModel;
struct ScBlock;

struct __declspec(align(4)) ScProcess
{
  SxReferenceCountable refc;
  SxStateStamp state_stamp;
};

struct __declspec(align(4)) ScRenderNode
{
    ScProcess super;
    SxTypedBase typed_base;
    ScIdentifier id_16;
    DWORD flags;
    void* ptr_24;
    ScRenderObject* render_object_28;
    ScRenderNode* parent_node_32;
    ScBoundingSphere bounding_sphere;
    ScMatrix* matrix_56;
    BYTE byte_60;
    BYTE byte_61;
};

struct __declspec(align(4)) ScRenderNodeGroup
{
    ScRenderNode super;
    Util::Vector<ScRenderNode* > render_node_vector;
};

struct __ScFixedString_32
{
    ScFixedString str;
    char buffer[32];
};

struct __ScFixedString_255
{
    ScFixedString super;
    char buffer[255];
};

struct __declspec(align(4)) _GcAIInfo
{
    DWORD anim_index;
    float float_4;
    DWORD flags;
    BYTE byte_12;
    BYTE _pad_13[3];
    float float_16;
    float float_20;
    float float_24;
    float float_28;
    float float_32;
};


struct __declspec(align(4)) ScBlockFile
{
    _ScBaseString* str;
    DWORD dword_4;
    DWORD entries_count;
    DWORD dword_12;
    ScBlock* entries_array;
    DWORD dword_20;
    __ScFixedString_255 blk_path;
};


struct __declspec(align(8)) GcCharacter
{
    ScRenderNodeGroup super;
    DWORD dword_80;
    BYTE byte_84;
    BYTE byte_85;
    DWORD dword_88;
    DWORD dword_92;
    DWORD dword_96;
    GcMask* mask_100;
    BYTE reacting;
    BYTE _pad_105[3];
    float reacting_time_delta_current;
    float reacting_time_delta_end;
    DWORD dword_116;
    DWORD dword_120;
    DWORD dword_124;
    DWORD refc_ptr_128;
    BYTE evil_permanent;
    BYTE byte_133;
    BYTE byte_134;
    ScPoint3d scpoint3d_136;
    float float_148;
    BYTE byte_152;
    BYTE byte_153;
    __ScFixedString_32 character_fstr_156;
    BYTE unknown_200[4];
    __ScFixedString_32 fstr_204;
    BYTE unknown_248[4];
    ScIdentifier character_id_252;
    ScIdentifier instance_id_256;
    ScIdentifier area_id_260;
    ScIdentifier id_264;
    BYTE byte_268__always_morph_related;
    BYTE always_morph;
    BYTE _pad_270[2];
    BYTE byte_272;
    BYTE byte_273;
    BYTE _pad_274[2];
    GcCharacterMoveInterpreter* character_move_interpreter;
    GcCollisionPhysics* collision_physics;
    GcTargeteer* targeteer;
    BYTE byte_288;
    GcMotionSystem* motion_system_296;
    _GcAIInfo aiinfo;
    GcCharacterAIController* character_ai_controller;
    float transparency;
    float float_340;
    BYTE model_director_fade;
    Native::Vector<_GtCharacterDamage> character_damage_vector;
    GcCharacterModel* character_model;
    GcMorphModel* morph_model;
    Native::Vector<_GtCharacterTexture> character_texture_vector;
    DWORD dword_380;
    ScDrawableModel* drawable_model_384;
    ScFastMatrix* fast_matrixes_388_probably_bones;
    ScFastMatrix* fastmatrix_array_5_392;
    ScFastMatrix* fastmatrix_array_5_396;
    void* ptr_400__size_400;
    Native::Vector<ScIdentifier> id_vector;
    Native::Vector<ScPoint3d> point3d_vector;
    Native::Vector<_GtBoneAdjustment> bone_adjustment_vector;
    double double_440__time_related;
    ScIdentifier vine_id;
    ScFastMatrix* vine_hold_matrix_452;
    float float_456;
    ScFastMatrix* matrix_460_probably_bone_matrix_from_set_holder;
    GcCharacter* holder_character_464;
    GcCharacter* holding_character_468;
    ScPoint3d point_472;
    BYTE shadow_type;
    GcSprite* sprite_488;
    float float_492;
    void* drawable_model_496;
    ScFastMatrix* fast_martix_array;
    float float_504;
    float float_508;
    float animation_rate;
    BYTE is_boss;
    BYTE byte_517__true_shatter_false_freeze;
    BYTE byte_518;
    BYTE byte_519;
    BYTE byte_520;
    float float_524;
    float float_528;
    float death_animation_related;
    ScPoint3d point_536;
    ScIdentifier id_548;
    ScBlockFile block_file;
    GcCollisionModel* collision_model[6];
    BYTE unknown__2[4];
};

struct GcToa;

Util::ScOSIVirtualMachine** pGcGame__sVM = (Util::ScOSIVirtualMachine**)0x0083877C;

typedef void(__fastcall* GcCinemaCharacter__InitCharacters)(__ScSLKFile_GcCinemaCharacter* _this, void* unused);
GcCinemaCharacter__InitCharacters tGcCinemaCharacter__InitCharacters;
GcCinemaCharacter__InitCharacters pGcCinemaCharacter__InitCharacters = (GcCinemaCharacter__InitCharacters)0x00590DA0;

typedef void(__fastcall* GcLegoCamera__NewToa)(GcLegoCamera* _this, void* unused, ScIdentifier* toa_id);
GcLegoCamera__NewToa tGcLegoCamera__NewToa;
GcLegoCamera__NewToa pGcLegoCamera__NewToa = (GcLegoCamera__NewToa)0x00450CA0;

typedef void(__fastcall* GcCharacter__AddPart)(GcCharacter* _this, void* unused, const struct _ScBaseString* a2, const ScIdentifier* a3);
GcCharacter__AddPart tGcCharacter__AddPart;
GcCharacter__AddPart pGcCharacter__AddPart = (GcCharacter__AddPart)0x00419060;

typedef void(__thiscall *GcCharacter__SetPosition)(GcCharacter* _this, const ScPoint3d* location);
GcCharacter__SetPosition pGcCharacter__SetPosition = (GcCharacter__SetPosition)0x004187B0;

typedef void(__thiscall *GcCharacter__SetRotation)(GcCharacter* _this, const ScPoint3d* rotation);
GcCharacter__SetRotation pGcCharacter__SetRotation = (GcCharacter__SetRotation)0x004185D0;

typedef void (__thiscall *GcCharacter__LoadCharBlockHeader)(GcCharacter* _this);
GcCharacter__LoadCharBlockHeader pGcCharacter__LoadCharBlockHeader = (GcCharacter__LoadCharBlockHeader)0x00419330;

typedef void (__cdecl *GcAreaDirector__LoadCharTexBlockHeader)(bool a1);
GcAreaDirector__LoadCharTexBlockHeader pGcAreaDirector__LoadCharTexBlockHeader = (GcAreaDirector__LoadCharTexBlockHeader)0x0048BE30;

typedef ScBlockFile*(__cdecl *SrGetCurBlockFile)();
SrGetCurBlockFile pSrGetCurBlockFile = (SrGetCurBlockFile)0x0054DB30;

typedef void (__cdecl *SrSetCurBlockFile)(struct ScBlockFile* a1);
SrSetCurBlockFile pSrSetCurBlockFile = (SrSetCurBlockFile)0x0054DB20;

typedef ScBlockFile*(__cdecl *SrGetCurSecondBlockFile)();
SrGetCurSecondBlockFile pSrGetCurSecondBlockFile = (SrGetCurSecondBlockFile)0x0054DB50;

typedef void (__cdecl *SrSetCurSecondBlockFile)(struct ScBlockFile* a1);
SrSetCurSecondBlockFile pSrSetCurSecondBlockFile = (SrSetCurSecondBlockFile)0x0054DB40;

typedef SxReferenceCountable*(__cdecl *GcModelDirector__Get)(ScIdentifier* id);
GcModelDirector__Get pGcModelDirector__Get = (GcModelDirector__Get)0x00480F70;

typedef Util::ScOSIVirtualMachine*(__thiscall *ScOSIVirtualMachine__Call)(Util::ScOSIVirtualMachine* __this, const char* function_name, ScOSIVariant* arg1, ScOSIVariant* arg2, ScOSIVariant* arg3, ScOSIVariant* arg4, ScOSIVariant* arg5, ScOSIVariant* arg6, ScOSIVariant* arg7, ScOSIVariant* arg8, ScOSIVariant* arg9, ScOSIVariant* arg10);
ScOSIVirtualMachine__Call pScOSIVirtualMachine__Call = (ScOSIVirtualMachine__Call)0x0060B320;


void __fastcall hGcCinemaCharacter__InitCharacters(__ScSLKFile_GcCinemaCharacter* _this, void* unused) {
	// Do whatever it normally does
	tGcCinemaCharacter__InitCharacters(_this, unused);

	// Loop through each character in the SLK file
	for (int i = 0; i < _this->count; i++) {
		// Get character at index i
		GcCharacter* character = (GcCharacter*)pGcModelDirector__Get(&_this->entries[i].anim_hierarchy);

		// Teleport character
		pGcCharacter__SetPosition(character, &_this->entries[i].sub->location_1.position);
		pGcCharacter__SetRotation(character, &_this->entries[i].sub->location_1.orientation);
	}
}

void __fastcall hGcLegoCamera__NewToa(GcLegoCamera* _this, void* unused, ScIdentifier* toa_id) {
    //Original function is no longer used
}

void(__fastcall hGcCharacter__AddPart)(GcCharacter* _this, void* unused, const struct _ScBaseString* a2, const ScIdentifier* a3) {      
    //Here we get the current character blockfile
    ScBlockFile* oldblockfile;
    ScBlockFile* secondaryblockfile;
    oldblockfile = pSrGetCurBlockFile();
    secondaryblockfile = pSrGetCurSecondBlockFile();
    pGcCharacter__LoadCharBlockHeader(_this);
    pGcAreaDirector__LoadCharTexBlockHeader(1);

    //Trampoline back to native function
    tGcCharacter__AddPart(_this, unused, a2, a3);

    //Reset back to original current blockfile
    pSrSetCurBlockFile(oldblockfile);
    pSrSetCurSecondBlockFile(secondaryblockfile);
}


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

Native::ScOSIVariant* GcLegoCamera__SetHeightOffset(Native::ScOSIVariant* result, Util::ScOSIVirtualMachine* vm, GcLegoCamera* camera, float height_offset, void* param3, void* param4, void* param5, void* param6, void* param7, void* param8, void* param9, void* param10) {
	// Update the camera with the given height offset
	camera->height_offset = height_offset;
	camera->height_offset_2 = height_offset;

	// Return a Nothing to the script
	result->TypeID = LOMNHook::Native::VARIANT_NULL;
	result->Payload = 0;
	return result;
}

Native::ScOSIVariant* GcLegoCamera__SetCamZoomFactor(Native::ScOSIVariant* result, Util::ScOSIVirtualMachine* vm, GcLegoCamera* camera, float zoom_factor, void* param3, void* param4, void* param5, void* param6, void* param7, void* param8, void* param9, void* param10) {
	// Update the camera with the given zoom factor
	camera->zoom_factor = zoom_factor;

	// Return a Nothing to the script
	result->TypeID = LOMNHook::Native::VARIANT_NULL;
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

	int GetAPIRevision() const override {
		return LOMNAPI_REVISION;
	}

	void OnPostInit() override {
		Util::ScOSITypeID characterType = Util::OSIGetTypeID("GcCharacter");
		Util::ScOSITypeID legoCameraType = Util::OSIGetTypeID("GcLegoCamera");
		Util::ScOSITypeID colorType = 21;
		LOMNHook::Util::OSIRegisterFunction((Util::OSIFunctionCallback)GcCharacter__SetColors, "gccharacter", "setcolors", 4, 4, characterType, colorType, colorType, colorType, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf);
		LOMNHook::Util::OSIRegisterFunction((Util::OSIFunctionCallback)GcLegoCamera__SetHeightOffset, "gclegocamera", "setheightoffset", 2, 2, legoCameraType, Native::VARIANT_FLOAT, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf);
		LOMNHook::Util::OSIRegisterFunction((Util::OSIFunctionCallback)GcLegoCamera__SetCamZoomFactor, "gclegocamera", "setcamzoomfactor", 2, 2, legoCameraType, Native::VARIANT_FLOAT, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf);

		MH_STATUS s = MH_Initialize();
		s = MH_CreateHook(pGcCinemaCharacter__InitCharacters, &hGcCinemaCharacter__InitCharacters, (void**)&tGcCinemaCharacter__InitCharacters);
		s = MH_CreateHook(pGcLegoCamera__NewToa, &hGcLegoCamera__NewToa, (void**)&tGcLegoCamera__NewToa);
        s = MH_CreateHook(pGcCharacter__AddPart, &hGcCharacter__AddPart, (void**)&tGcCharacter__AddPart);
		s = MH_EnableHook(MH_ALL_HOOKS);
	}
};

OptionalPatchNative Instance;

extern "C" {
	__declspec(dllexport) LOMNHook::HookMod* HookmodInit() {
		return &Instance;
	}
}