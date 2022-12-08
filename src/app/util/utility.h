#pragma once
#include <filesystem>
#include <functional>
#include <string>
#include <random>

#ifdef VZ_SFML
#include <SFML/System/Vector2.hpp>
#endif

#include "core.h"

namespace vz
{
	template <typename T>
	concept Enum = std::is_enum_v<T>;

	static constexpr std::string_view RES_FONT{ "fonts/" };
	static constexpr std::string_view RES_IMAGE{ "images/" };
	static constexpr std::string_view RES_SOUND{ "sounds/" };
	static constexpr std::string_view RES_DATA{ "data/" };

	static constexpr std::string_view WINDOW_TITLE{ "Pong" };
	static constexpr std::string_view WINDOW_DESCRIPTION_TITLE{ "Just a game" };

	namespace util
	{
		template <typename T>
		class CRTP
		{
		protected:
			CRTP() = default;

			T& Cvt()
			{
				return static_cast<T&>(*this);
			}

			T const& Cvt() const
			{
				return static_cast<T const&>(*this);
			}
		};

		inline std::string GetResourceDir() noexcept	// better using inline instead of static in header file, because static means that it is belong to the file (translation unit)
		{
			static std::filesystem::path path = std::filesystem::current_path();
			static bool isInit = false;

			if (!isInit)
			{
				// Search res folder
				bool isThere = false;
				for (auto& data : std::filesystem::directory_iterator{ path })
				{
					if (data.path().filename().string() == "res") isThere = true;
				}

				if (!isThere)
					return {};

				path += "\\res\\";
				isInit = true;
			}

			return path.string();
		}

		constexpr std::string GetResourceDir(const std::string_view& type_, const std::string& filename_) noexcept	// constexpr is imply inline on it
		{
			return "./res/" + std::string{ type_.data() } + filename_;
		}

		template <std::integral Type, vz::Enum  En>
		constexpr Type EnumTo(En enum_)
		{
			return static_cast<Type>(enum_);
		}

		template <typename En, typename Tp> requires std::is_enum_v<En>&& std::is_integral_v<Tp>
		constexpr En ToEnum(Tp val_)
		{
			return static_cast<En>(val_);
		}

		// Numeric simplification
		//========================================================================================================
		template <typename Type>
		FORCEINLINE constexpr Type HalfOf(Type value_)
		{
			return value_ / static_cast<Type>(2);
		}

		template <typename RetType, typename Type>
		FORCEINLINE constexpr RetType HalfOf(Type value_)
		{
			return static_cast<RetType>(value_ / static_cast<RetType>(2));
		}

		template <typename Type>
		FORCEINLINE constexpr Type QuarterOf(Type value_)
		{
			return value_ / static_cast<Type>(4);
		}

		template <typename RetType, typename Type>
		FORCEINLINE constexpr RetType QuarterOf(Type value_)
		{
			return static_cast<RetType>(value_ / static_cast<RetType>(4));
		}

		template <typename Type>
		FORCEINLINE constexpr Type HalfOfSub(Type value_, Type sub_)
		{
			return value_ / static_cast<Type>(2) - sub_;
		}

		template <typename Type>
		FORCEINLINE constexpr Type HalfOfAdd(Type value_, Type add_)
		{
			return value_ / static_cast<Type>(2) + add_;
		}

		//========================================================================================================

		template<std::integral Type>
		inline Type GenerateRandom(Type min_, Type max_)
		{
			static std::random_device device{};
			static std::mt19937 engine{ device() };

			return std::uniform_int_distribution<Type>{min_, max_}(engine);	// mersenne_twister is engine to generate random number from seed obtained by random device
						  //return static_cast<Type>(engine()) % (max_ - min_) + min_;
		}

		template<std::floating_point Fp>
		inline Fp GenerateRandom(Fp min_, Fp max_)
		{
			static std::random_device device{};
			static std::mt19937 engine{ device() };

			return std::uniform_real_distribution<Fp>{min_, max_}(engine);	// mersenne_twister is engine to generate random number from seed obtained by random device
		}

		/**
		* \brief Compare two floating point precisely
		* \tparam Fp floating point type
		* \param val1_ first value
		* \param val2_ second value
		* \param epsilon_ epsilon to use
		* \return either the value is equal or not
		*/
		template<std::floating_point Fp>
		bool Equal(Fp val1_, Fp val2_, Fp epsilon_ = std::numeric_limits<Fp>::epsilon())
		{
			return std::fabs(val1_ - val2_) < epsilon_;
		}
	}
}
