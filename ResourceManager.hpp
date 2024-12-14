#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:
    std::unique_ptr<Resource> resource;// Wskaźnik do zasobu

    public:
    ResourceManager() : resource(std::make_unique<Resource>()) {} // konstruktor domyślny - inicjalizuje zasób przy pomocy konstruktora Resource

    // Metoda get(), która wywołuje metodę get() obiektu Resource
    double get() const {
        return resource->get();
    }

    // Konstruktor kopiujący - tworzy kopię zasobu
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique<Resource>(*other.resource)) {}

    // Operator przypisania kopiującego - tworzy kopię zasobu
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenoszący - przenosi zasób
    ResourceManager(ResourceManager&& other) noexcept
        : resource(std::move(other.resource)) {}

    // Operator przypisania przenoszącego - przenosi zasób
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    // Destruktor - std::unique_ptr automatycznie usuwa zasób
    ~ResourceManager() = default;
};


