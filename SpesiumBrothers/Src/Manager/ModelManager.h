#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include <Definition/Definition.h>
#include<Utility/Singleton.h>

#include<map>

namespace spacium
{
	class ModelManager :public spesium::Singleton<ModelManager>
	{
	public:
		ModelManager() = default;
		~ModelManager() = default;

		void LoadModel();
		void DeleteModel();
		int32_t GetModel();
	private:
		std::map<std::string, int32_t>modelList{};
	};

}

#endif // !MODEL_MANAGER_H

