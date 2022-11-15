#pragma once
#include <minwindef.h>


DWORD offset_uworld;
DWORD offset_gneme = 0x4f1cf40;

DWORD offset_getbonematrix = 0x231BAB0;

DWORD offset_camera_manager = 0x2e0; 
DWORD offset_camera_cache = 0x1a40;
DWORD offset_persistent_level = 0x30;
DWORD offset_game_instance = 0x170; 
DWORD offset_local_players_array = 0x38;
DWORD offset_player_controller = 0x30; 
DWORD offset_apawn = 0x2c8;  
DWORD offset_root_component = 0x160; 
DWORD offsets_instigator_actor = 0x148;
DWORD offset_actor_array = 0x98; 
DWORD offset_actor_count = 0xa0; 
DWORD offset_actor_id = 0x18;
DWORD offset_player_teamid = 0x420;
DWORD offset_player_state = 0x268;
DWORD offset_actor_mesh = 0x2a8; 
DWORD offset_actor_health = 0x1c18;
DWORD offset_relative_location = 0x144;
DWORD offset_last_submit_time = 0x2AC;
DWORD offset_last_render_time = 0x2B4;



enum bones
{
	HEAD = 13,//Ó^
	UPPER_NECK = 7,
	NECK = 6,//≤±◊”
	RIGHT_SHOULDER = 66,//ºÁ∞Ú
	RIGHT_ELBOW = 89,//÷‚
	RIGHT_HAND = 124,// ÷
	LEFT_SHOULDER = 93,
	LEFT_ELBOW = 94,
	LEFT_HAND = 123,
	PELVIS = 2,//π«≈Ë
	STOMACH = 4,//Œ∏
	CHEST = 5,//–ÿ
	RIGHT_THIGH = 130,//¥ÛÕ»
	RIGHT_KNEE = 131,
	RIGHT_FOOT = 140,
	LEFT_THIGH = 125,
	LEFT_KNEE = 126,
	LEFT_FOOT = 139,
	ROOT = 199,
};

struct FPlane
{
	float x, y, z;
	float  w;                                                         // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

};
struct FMatrix 
{
	struct FPlane                                      XPlane;                                                    // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      YPlane;                                                    // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      ZPlane;                                                    // 0x0020(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      WPlane;                                                    // 0x0030(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};