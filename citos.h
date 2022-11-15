#pragma once
#include <cstdint>
#include <misc/offsets.h>
#include <misc/math.h>
#include <misc/memory.h>
#include <misc/render.h>

bool esp = false;
bool draw_bone = false;
bool draw_teammates = false;

static std::string getnamebyid(uint32_t actor_id) {

	auto chunkOffset = (UINT)((int)(actor_id) >> 16);
	auto nameOffset = (USHORT)actor_id;

	auto namePoolChunk = read<UINT64>(Globals::Base + offset_gneme  + ((chunkOffset + 2) * 8));
	auto entryOffset = namePoolChunk + (ULONG)(2 * nameOffset);
	auto nameEntry = read<INT16>(entryOffset);

	auto nameLength = nameEntry >> 6;
	char buff[1028];
	if ((DWORD)nameLength && nameLength > 0)
	{
		memcpy(buff, (LPCVOID)(entryOffset + 2), nameLength);
		buff[nameLength] = '\0';
		return std::string(buff);
	}
	else return "";
}


void drawplayerbone(uintptr_t player_controller, uintptr_t mesh, ImU32 color)
{
	std::vector<std::vector<bones>> _boneVector =
	{
		{ bones::HEAD, bones::NECK, bones::CHEST, bones::PELVIS },
		{ bones::NECK, bones::RIGHT_SHOULDER, bones::RIGHT_ELBOW, bones::RIGHT_HAND},
		{ bones::NECK, bones::LEFT_SHOULDER, bones::LEFT_ELBOW,bones::LEFT_HAND },
		{ bones::PELVIS, bones::RIGHT_THIGH, bones::RIGHT_KNEE, bones::RIGHT_FOOT },
		{ bones::PELVIS,bones::LEFT_THIGH, bones::LEFT_KNEE,bones::LEFT_FOOT},
	};

	for (const std::vector<bones>& part : _boneVector)
	{
		vec2 previousBone{};
		for (const bones& bone : part)
		{
			vec2 bonePos = {};
			worldtoscreen(player_controller, getbonelocation(mesh, bone), &bonePos, false);
			if (bonePos.x == 0.0f && bonePos.y == 0.0f)
				break;
			if (previousBone.x == 0.0f) // first bone no draw happens
			{
				previousBone = bonePos;
				continue;
			}
			DrawLine(ImVec2(previousBone.x, previousBone.y), ImVec2(bonePos.x, bonePos.y), color,2.0f);
			previousBone = bonePos;
		}
	}
}




inline static void initcitos() {
	if (esp) {
		auto u_world = read<uintptr_t>(uworld_sig + *(int*)(uworld_sig + 0x3) + 0x7);
		auto game_instance = read<uintptr_t>(u_world + offset_game_instance);
		auto local_player_array = read<uintptr_t>(game_instance + offset_local_players_array);
		auto local_player = read<uintptr_t>(local_player_array);
		auto local_player_controller = read<uintptr_t>(local_player + offset_player_controller);
		auto local_player_pawn = read<uintptr_t>(local_player_controller + offset_apawn);
		auto local_player_root = read<uintptr_t>(local_player_pawn + offset_root_component);
		auto local_player_state = read<uintptr_t>(local_player_pawn + offset_player_state);
		auto local_player_teamid = read<int32_t>(local_player_state + offset_player_teamid);
		auto persistent_level = read<uintptr_t>(u_world + offset_persistent_level);
		auto actors = read<uintptr_t>(persistent_level + offset_actor_array);
		auto actor_count = read<int>(persistent_level + offset_actor_count);

		int32_t width, height;
		screensize(local_player_controller, width, height);
		for (int i = 0; i < actor_count; i++)
		{
			auto actor_pawn = read<uintptr_t>(actors + i * 0x8);
			if (actor_pawn == local_player_pawn) continue;
			auto uinstigator = read<uintptr_t>(actor_pawn + offsets_instigator_actor);
			if (uinstigator == local_player_pawn) continue;
			auto root = read<uintptr_t>(uinstigator + offset_root_component);
			auto mesh = read<uintptr_t>(uinstigator + offset_actor_mesh);
			vec3 loc = read<vec3>(root + offset_relative_location);
			auto state = read<uintptr_t>(uinstigator + offset_player_state);
			auto teamid = read<int32_t>(state + offset_player_teamid);
			auto health = read<float>(actor_pawn + offset_actor_health);

			if(health<0)continue;
			std::string name = getnamebyid(read<int32_t>(actor_pawn + offset_actor_id));
			if (teamid == local_player_teamid && !draw_teammates)continue;

			if (name.substr(0, 10) == _("BP_Soldier"))
			{

				if (draw_bone) 
				{
					drawplayerbone(local_player_controller, mesh, ImColor(51, 255, 51, 255));
				}
			}

		}
	}
		
}

