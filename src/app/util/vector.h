#pragma once

#include "core.h"

namespace vz
{
	template<unsigned N, typename T>
	struct Vector
	{
		T Data[N];

		Vector() { memset(Data, 0, N); }

	};

	template<typename T>
	struct Vector<2, T>
	{
		T x;
		T y;

		Vector(T x_, T y_) : x(x_), y(y_) {}
		Vector() : x(static_cast<T>(0)), y(static_cast<T>(0)) {}
		template <typename U>
		Vector(const Vector<2, U>& vec_) : Vector(static_cast<T>(vec_.x), static_cast<T>(vec_.y)) {}
	};

	template<typename T>
	struct Vector<3, T>
	{
		T x;
		T y;
		T z;

		Vector(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}
		Vector() : x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0)) {}
		template <typename U>
		Vector(const Vector<3, U>& vec_) : Vector(static_cast<T>(vec_.x), static_cast<T>(vec_.y), static_cast<T>(vec_.z)) {}
	};

	template<unsigned N, typename T>
	Vector<N, T> operator+(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) + *((T*)&rhs_ + i);
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator-(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) - *((T*)&rhs_ + i);
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator*(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) * *((T*)&rhs_ + i);
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator/(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) / *((T*)&rhs_ + i);
		}

		return result;
	}

	template<unsigned N, typename T>
	void operator+=(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) += *((T*)&rhs_ + i);
		}
	}

	template<unsigned N, typename T>
	void operator-=(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) -= *((T*)&rhs_ + i);
		}
	}

	template<unsigned N, typename T>
	void operator*= (const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) *= *((T*)&rhs_ + i);
		}
	}

	template<unsigned N, typename T>
	void operator/=(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) /= *((T*)&rhs_ + i);
		}
	}

	template<unsigned N, typename T>
	bool operator==(const Vector<N, T>& lhs_, const Vector<N, T>& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			if (*((T*)&lhs_ + i) != *((T*)&rhs_ + i))
				return false;
		}

		return true;
	}

	// Scalar
	template<unsigned N, typename T>
	Vector<N, T> operator+(const Vector<N, T>& lhs_, const T& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) + rhs_;
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator-(const Vector<N, T>& lhs_, const T& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) - rhs_;
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator*(const Vector<N, T>& lhs_, const T& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) * rhs_;
		}

		return result;
	}

	template<unsigned N, typename T>
	Vector<N, T> operator/(const Vector<N, T>& lhs_, const T& rhs_)
	{
		Vector<N, T> result;

		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&result + i) = *((T*)&lhs_ + i) / rhs_;
		}

		return result;
	}

	template<unsigned N, typename T>
	void operator+=(const Vector<N, T>& lhs_, const T& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) += rhs_;
		}
	}

	template<unsigned N, typename T>
	void operator-=(const Vector<N, T>& lhs_, const T& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) -= rhs_;
		}
	}

	template<unsigned N, typename T>
	void operator*=(const Vector<N, T>& lhs_, const T& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) *= rhs_;
		}
	}

	template<unsigned N, typename T>
	void operator/=(const Vector<N, T>& lhs_, const T& rhs_)
	{
		for (unsigned i = 0; i < N; ++i)
		{
			*((T*)&lhs_ + i) /= rhs_;
		}
	}

	using Vec2f = Vector<2, float>;
	using Vec2i = Vector<2, int>;
	using Vec2u = Vector<2, unsigned>;
	using Vec3f = Vector<3, float>;
	using Vec3i = Vector<3, int>;
	using Vec3u = Vector<3, unsigned>;

	namespace util
	{
		template <typename Type>
		FORCEINLINE constexpr vz::Vector<2, Type> HalfOf(const vz::Vector<2, Type>& value_)
		{
			return value_ / static_cast<Type>(2);
		}

		template <typename Type>
		FORCEINLINE constexpr vz::Vector<2, Type> QuarterOf(const vz::Vector<2, Type>& value_)
		{
			return value_ / static_cast<Type>(4);
		}
	}

}