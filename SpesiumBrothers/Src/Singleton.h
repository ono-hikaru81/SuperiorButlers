#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}

public:
	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
	}

	static void DestoroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	static T* GetInstance()
	{
		return m_pInstance;
	}

	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}

private:
	static T* m_pInstance;
};

template <class T>
T* Singleton<T>::m_pInstance = nullptr;

#endif // !SINGLETON_H
