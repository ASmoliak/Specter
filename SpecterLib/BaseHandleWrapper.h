#pragma once
#include <utility>

template <typename HandleType, class Derivative>
class BaseHandleWrapper
{
public:
	BaseHandleWrapper(const BaseHandleWrapper& other) = delete;
	BaseHandleWrapper& operator=(const BaseHandleWrapper& other) = delete;

	BaseHandleWrapper(BaseHandleWrapper&& other) noexcept
		: m_handle(std::move(other.m_handle))
	{
		other.m_handle = nullptr;
	}

	BaseHandleWrapper& operator=(BaseHandleWrapper&& other) noexcept
	{
		if (this == &other)
		{
			return *this;
		}

		Release();
		m_handle = std::move(other.m_handle);
		other.m_handle = nullptr;
		return *this;
	}

	BaseHandleWrapper() : m_handle(nullptr)
	{
	}

	BaseHandleWrapper(HandleType handle) : m_handle(handle)
	{
	}

	HandleType Get() const
	{
		return m_handle;
	}

	HandleType* Put()
	{
		Release();
		return &m_handle;
	}

	bool IsValid() const
	{
		return Derivative::IsValidImp(m_handle);
	}

	void Release()
	{
		if (Derivative::IsValidImp(m_handle))
		{
			Derivative::ReleaseImp(m_handle);
			m_handle = nullptr;
		}
	}

	void Attach(HandleType handle)
	{
		Release();
		m_handle = handle;
	}

	[[nodiscard]] HandleType Detach()
	{
		HandleType handle = m_handle;
		m_handle = nullptr;
		return handle;
	}

protected:
	~BaseHandleWrapper()
	{
		Release();
	}

	HandleType m_handle;

	friend Derivative;
};
