#pragma once

namespace vz
{

	template <typename T = void>
	class ScopePtr
	{
	public:
		constexpr ScopePtr(T* ptr_, size_t size_ = 1) : m_pointer(ptr_), m_size(size_)
		{
		}

		constexpr ScopePtr() : ScopePtr{ nullptr }
		{
		}

		ScopePtr(const ScopePtr& other) = delete;
		ScopePtr& operator=(const ScopePtr& other) = delete;

		// Move ownership
		constexpr ScopePtr(ScopePtr&& other) noexcept
			: m_pointer(other.m_pointer), m_size(other.m_size)
		{
			other.m_pointer = nullptr;
		}

		// Move ownership
		constexpr ScopePtr& operator=(ScopePtr&& other) noexcept
		{
			if (this == &other)
				return *this;
			m_pointer = other.m_pointer;
			m_size = other.m_size;
			other.m_pointer = nullptr;
			return *this;
		}

		~ScopePtr()
		{
			// Perhaps can checking m_pointer nullptr
			if (m_size > 1)	delete[] m_pointer;
			else			delete m_pointer;
		}

		[[nodiscard]] constexpr size_t GetSize() const
		{
			return m_size;
		}

		[[nodiscard]] constexpr bool IsValid() const
		{
			return m_pointer;
		}

		[[nodiscard]] constexpr T* Get() const
		{
			return m_pointer;
		}

		[[nodiscard]] constexpr T* Release()
		{
			return m_pointer;
		}

		constexpr T* operator->() const { return m_pointer; }

	public:
		static ScopePtr<void> Invalid;
	private:
		T* m_pointer;
		size_t m_size;			// For raw pointer that used as array
	};


	template <typename Ptr>
	class SharedPtr
	{
	public:
		constexpr SharedPtr(Ptr* ptr_, size_t size_ = 1)
			: m_pointer(ptr_), m_reference(new size_t{ size_ }), m_size(size_)
		{
		}

		constexpr SharedPtr(const SharedPtr& other)
			: m_pointer(other.m_pointer),
			m_reference(other.m_reference),
			m_size(other.m_size)
		{
			IncRefCount();
		}

		constexpr SharedPtr(SharedPtr&& other) noexcept
			: m_pointer(other.m_pointer),
			m_reference(other.m_reference),
			m_size(other.m_size)
		{
		}

		constexpr SharedPtr& operator=(const SharedPtr& other)
		{
			if (this == &other)
				return *this;
			m_pointer = other.m_pointer;
			m_reference = other.m_reference;
			m_size = other.m_size;

			IncRefCount();

			return *this;
		}

		constexpr SharedPtr& operator=(SharedPtr&& other) noexcept
		{
			if (this == &other)
				return *this;
			m_pointer = other.m_pointer;
			m_reference = other.m_reference;
			m_size = other.m_size;
			return *this;
		}

		~SharedPtr()
		{
			DecRefCount();

			if (!HasReference())
			{
				if (m_size > 1)	delete[] m_pointer;
				else			delete m_pointer;

				delete m_reference;
			}
		}

	private:
		constexpr void IncRefCount()  { ++* m_reference; }
		constexpr void DecRefCount()  { --* m_reference; }
		constexpr bool HasReference() { return *m_reference; }

	private:
		Ptr* m_pointer;
		size_t* m_reference;
		size_t m_size;
	};
}
