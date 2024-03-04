#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Create a new JSON object
    json j;

    // Add key-value pairs to the JSON object
    j["name"] = "John Doe";
    j["age"] = 30;
    j["is_student"] = false;
    j["skills"] = {"C++", "Python", "JavaScript"};

    // Create a nested JSON object
    json address;
    address["city"] = "New York";
    address["country"] = "USA";

    // Add the nested object to the main JSON object
    j["address"] = address;

    // Serialize the JSON object to a string
    std::string serializedString = j.dump();
    std::cout << serializedString << std::endl;

    // Deserialize JSON from string
    auto deserializedJson = json::parse(serializedString);

    // Access elements
    std::cout << "Name: " << deserializedJson["name"] << std::endl;
    std::cout << "City: " << deserializedJson["address"]["city"] << std::endl;

    // Modify elements
    deserializedJson["age"] = 31;  // Change age
    deserializedJson["skills"].push_back("HTML");  // Add a new skill

    // Serialize and print the modified JSON
    std::cout << deserializedJson.dump(4) << std::endl; // Pretty print with 4 spaces indentation

    return 0;
}
