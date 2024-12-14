#pragma once

#include "Resource.hpp"

class ResourceManager {
private:
    Resource resource; // Obiekt typu Resource, którym zarządza ResourceManager

public:
    // Konstruktor domyślny
    ResourceManager() = default;

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(other.resource) {}

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    // Operator przypisania (kopiujący)
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    // Operator przypisania (przenoszący)
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    // Destruktor
    ~ResourceManager() = default;

    // Metoda, która zwraca wynik zawołania metody get obiektu Resource
    double get() {
        return resource.get();
    }
};
