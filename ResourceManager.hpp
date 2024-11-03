#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    private:
    std::unique_ptr<Resource> resource;// Wskaźnik do zasobu

    public:
    ResourceManager() : resource(std::make_unique<Resource>()) {} // konstruktor domyślny - inicjalizuje zasób przy pomocy konstruktora Resource

    // Metoda get(), która wywołuje metodę get() obiektu Resource
    double get() const {
        return resource->get();
    }

    // Domyślny konstruktor kopiujący i operator przypisania są usuwane, aby uniknąć kopiowania zasobu, który jest drogi w konstrukcji.
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Konstruktor przenoszący i operator przypisania przenoszącego
    ResourceManager(ResourceManager&&) = default;
    ResourceManager& operator=(ResourceManager&&) = default;
};
