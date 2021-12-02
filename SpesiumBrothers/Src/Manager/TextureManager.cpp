#include "TextureManager.h"

namespace spesium
{
	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
	}

	void TextureManager::LoadTexture(const std::string& name, const std::string& filePath)
	{
		TextureList.emplace(name, LoadGraph(filePath.c_str()));
	}

	void TextureManager::ReleaseTexture()
	{
		TextureList.clear();
		InitGraph();
	}

	std::optional<int32_t> TextureManager::GetTexture(const std::string& name)
	{
		const auto& tmp = TextureList.find(name);
		return(tmp == TextureList.end()) ? std::nullopt : std::make_optional( tmp->second);
	}
}
