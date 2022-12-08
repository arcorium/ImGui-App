#pragma once
#include <unordered_map>

#include "utility.h"

namespace vz
{
	// Forward Declaration
	class IState;
	class Entity;


	enum class State
	{
		Current = -1,
		None = Current,
		Intro,
		MainMenu,
		Game,
		Pause,
		Done,
		Count,
	};

	// Typedef
	// =========================================[Resource]====================================
	using ResourceId = std::string;
	using RefCounter = unsigned;
	template<typename T>
	using Resource = std::pair<RefCounter, T>;
	template <typename T>
	using ResourceContainer = std::unordered_map<ResourceId, Resource<T>>;

	// =========================================[Entity]====================================
	using EntityId = unsigned;
	using EntityList = std::unordered_map<EntityId, Entity*>;
	using EntityContainer = std::unordered_map<State, EntityList>;

	// =========================================[State]====================================
	using StateList = std::vector<State>;
	using StateContainer = std::unordered_map<State, IState*>;


}
