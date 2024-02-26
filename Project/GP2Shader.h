#pragma once
#include <vulkan/vulkan_core.h>
#include <vector>
#include <string>

class GP2Shader
{
public:
	GP2Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) :
		m_VertexShaderFile(vertexShaderFile)
		, m_FragmentShaderFile(fragmentShaderFile)
	{
	}

	~GP2Shader() = default;
	void Initialize(const VkDevice& vkDevice);
	std::vector<VkPipelineShaderStageCreateInfo>& GetShaderStages() { return m_ShaderStages; };
	void DestroyShaderModules(const VkDevice& vkDevice);

	VkPipelineShaderStageCreateInfo createFragmentShaderInfo(const VkDevice& vkDevice);
	VkPipelineShaderStageCreateInfo createVertexShaderInfo(const VkDevice& vkDevice);
	VkPipelineVertexInputStateCreateInfo createVertexInputStateInfo();
	VkPipelineInputAssemblyStateCreateInfo createInputAssemblyStateInfo();

private:
	
	
	VkShaderModule createShaderModule(const VkDevice& vkDevice, const std::vector<char>& code);

	std::string m_VertexShaderFile;
	std::string m_FragmentShaderFile;
	std::vector<VkPipelineShaderStageCreateInfo> m_ShaderStages;

	GP2Shader(const GP2Shader&) = delete;
	GP2Shader& operator=(const GP2Shader&) = delete;
	GP2Shader(const GP2Shader&&) = delete;
	GP2Shader& operator=(const GP2Shader&&) = delete;
};