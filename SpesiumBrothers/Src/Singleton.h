#ifndef SINGLETON_H
#define SINGLETON_H

template<class T>
class Singleton {
   protected:
    Singleton() {}

    virtual ~Singleton() {}

   public:
    static T* CreateInstance() {
        if ( Instance == nullptr ) {
            Instance = new T();
        }

        return Instance;
    }

    static void DestoroyInstance() {
        delete Instance;
        Instance = nullptr;
    }

    static T* GetInstance() {
        if ( Instance == nullptr ) {
            return CreateInstance();
        }

        return Instance;
    }

    static bool IsNull() {
        return Instance == nullptr;
    }

   private:
    static T* Instance;
};

template<class T>
T* Singleton<T>::Instance = nullptr;

#endif  // !SINGLETON_H
