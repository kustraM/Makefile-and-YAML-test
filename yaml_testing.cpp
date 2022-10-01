#include <iostream>
#include <fstream>
#include <string>
#include "yaml-cpp/yaml.h"

int main()
{

    YAML::Node yaml_configuration = YAML::LoadFile("manifest.yaml");
    const YAML::Node &command = yaml_configuration["TOPKEY"]["interfaces"]["command"];
    for (unsigned i = 0; i < command.size(); i++)
    {
        std::cout << i << std::endl;

        if (command[i]["component_name"].as<std::string>().empty())
        {
            std::cout << command[i]["iface_name"].as<std::string>() << std::endl;
            std::cout << command[i]["description"].as<std::string>() << std::endl;
        }
        else
        {
            std::cout << command[i]["component_name"].as<std::string>() << std::endl;
            std::cout << command[i]["iface_name"].as<std::string>() << std::endl;
            std::cout << command[i]["description"].as<std::string>() << std::endl;
        }
    }
}

/**
 * @result SICK
 *
 */